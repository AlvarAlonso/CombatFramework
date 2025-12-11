// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"

#include "AbilitySystem/CFR_BlueprintFunctionLibrary.h"
#include "AI/CFR_AIController.h"
#include "AI/Enums/CFR_AIEnums.h"
#include "Characters/CFR_AICharacter.h"
#include "Characters/CFR_PlayerCharacter.h"

// TODO: Remove this dependency. Combat manager should not have knowledge about arenas. 
// Maybe GameMode can have the notion of EnemySpawned, which is the callback we need here.
#include "Subsystems/CFR_ArenaSubsystem.h" 

#include "Subsystems/CFR_CombatManagerSubsystem.h"

void FCFR_EnemyCombatItem::Reset(ACFR_AICharacter* enemy)
{
	if (enemy)
	{
		Enemy = enemy;
		LastAttackTime = UGameplayStatics::GetTimeSeconds(enemy);
	}
	else
	{
		Enemy.Reset();
		LastAttackTime = 0.0;
	}

	Distance = 0.0;
	Scoring = 0.0;
}

void UCFR_CombatManagerSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	EnemyMeleeItems.Reserve(MaxMeleeEnemies);
	EnemyMeleeItems.Init(FCFR_EnemyCombatItem(), MaxMeleeEnemies);

	EnemyRangedItems.Reserve(MaxRangedEnemies);
	EnemyRangedItems.Init(FCFR_EnemyCombatItem(), MaxRangedEnemies);

	if (InWorld.GetGameInstance())
	{
		const auto ArenaSubsystem = InWorld.GetGameInstance()->GetSubsystem<UCFR_ArenaSubsystem>();
		if (ArenaSubsystem)
		{
			ArenaSubsystem->OnEnemySpawned.AddUObject(this, &UCFR_CombatManagerSubsystem::OnActorSpawned);
		}
	}
}

void UCFR_CombatManagerSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Player == nullptr)
	{
		Player = Cast<ACFR_PlayerCharacter>(UGameplayStatics::GetActorOfClass(this, ACFR_PlayerCharacter::StaticClass()));
		if (Player == nullptr)
		{
			return;
		}
	}

	if (bAddedNewEnemies || bEnemyDead || FVector::Dist2D(LastPlayerPosition, Player->GetActorLocation()) > InvalidateOffset)
	{
		Invalidate();
		LastPlayerPosition = Player->GetActorLocation();
		bAddedNewEnemies = false;
		bEnemyDead = false;
	}

	UpdateMeleeEnemies();
	UpdateDistanceEnemies();
}

TStatId UCFR_CombatManagerSubsystem::GetStatId() const
{
	return TStatId();
}

void UCFR_CombatManagerSubsystem::OnActorSpawned(AActor* actor)
{
	if (ACFR_AICharacter* Enemy = Cast<ACFR_AICharacter>(actor))
	{
		switch (Enemy->GetAICharacterType())
		{
		// TODO: Maybe the AICharacter should already tell us if it's melee or ranged.
		case ECFR_AICharacterType::MeleePeasant:
		case ECFR_AICharacterType::ShieldPeasant:
			OnEnemySpawned(Enemy, EnemyMeleeItems);
			break;
		case ECFR_AICharacterType::DistancePeasant:
			OnEnemySpawned(Enemy, EnemyRangedItems);
			break;
		}
	}
}

void UCFR_CombatManagerSubsystem::OnEnemySpawned(ACFR_AICharacter* Enemy, TArray<FCFR_EnemyCombatItem>& EnemyItems)
{
	int32 Index = 0;
	while (Index < EnemyItems.Num())
	{
		auto& item = EnemyItems[Index++];
		if (item.IsValid() == false)
		{
			item.Reset(Enemy);

			Enemy->OnHandleDeathEvent.AddUObject(this, &UCFR_CombatManagerSubsystem::OnEnemyDeath);
			Enemy->TargetActor = Player.Get();

			bAddedNewEnemies = true;
			return;
		}
	}
}

void UCFR_CombatManagerSubsystem::OnEnemyDeath(ACFR_AICharacter* enemy)
{
	bEnemyDead = true;
}

void UCFR_CombatManagerSubsystem::Invalidate()
{
	InvalidateImpl(EnemyMeleeItems);
	InvalidateImpl(EnemyRangedItems);
}

void UCFR_CombatManagerSubsystem::InvalidateImpl(TArray<FCFR_EnemyCombatItem>& EnemyItems)
{
	const FVector playerLocation = Player->GetActorLocation();

	for (FCFR_EnemyCombatItem& item : EnemyItems)
	{
		if (item.IsValid())
		{
			item.Distance = FVector::Dist2D(playerLocation, item.Enemy->GetActorLocation());
			item.Scoring = item.Distance;
		}
	}

	EnemyItems.Sort([this](const FCFR_EnemyCombatItem& left, const FCFR_EnemyCombatItem& right)
		{
			if (left.IsValid() && right.IsValid())
			{
				return left.Scoring < right.Scoring;
			}
			else if (left.IsValid())
			{
				return true;
			}
			else
			{
				return false;
			}
		});

	int32 index = 0;
	const int32 lastIndex = EnemyItems.IndexOfByPredicate([](const FCFR_EnemyCombatItem& item) { return item.IsValid() == false; });

	while (index < lastIndex && index < NbHoldingEnemies)
	{
		FCFR_EnemyCombatItem& item = EnemyItems[index++];
		if (ACFR_AIController* enemyController = item.Enemy->GetController<ACFR_AIController>())
		{
			if (enemyController->GetEnemyAIState() == ECFR_EnemyAIState::None || enemyController->GetEnemyAIState() == ECFR_EnemyAIState::Waiting)
			{
				enemyController->SetEnemyAIState(ECFR_EnemyAIState::Holding);
			}
		}
	}

	while (index < lastIndex)
	{
		FCFR_EnemyCombatItem& item = EnemyItems[index++];
		if (ACFR_AIController* enemyController = item.Enemy->GetController<ACFR_AIController>())
		{
			if (enemyController->GetEnemyAIState() == ECFR_EnemyAIState::None)
			{
				enemyController->SetEnemyAIState(ECFR_EnemyAIState::Waiting);
			}
		}
	}
}

void UCFR_CombatManagerSubsystem::UpdateMeleeEnemies()
{
	const FVector playerLocation = Player->GetActorLocation();

	float oldestAttackTime = UGameplayStatics::GetTimeSeconds(this);
	for (FCFR_EnemyCombatItem& item : EnemyMeleeItems)
	{
		if (item.IsValid())
		{
			oldestAttackTime = std::min(oldestAttackTime, item.LastAttackTime);
		}
	}

	UpdateScoring(EnemyMeleeItems, [this, playerLocation, oldestAttackTime](FCFR_EnemyCombatItem& item)
		{
			item.Distance = std::numeric_limits<float>::infinity();
			item.Scoring = std::numeric_limits<float>::infinity();

			if (item.IsValid())
			{
				item.Distance = FVector::Dist2D(playerLocation, item.Enemy->GetActorLocation());
				const float speed = item.Enemy->GetCurrentMaxSpeed();

				const float distanceScore = (item.Distance / speed) * DistanceWeight;
				const float visibilityScore = (UCFR_BlueprintFunctionLibrary::IsInFrustum(item.Enemy.Get()) ? 0.0 : IsNotInFrustumScore) * IsNotInFrustumWeight;
				const float lastAttackTimeScore = (item.LastAttackTime - oldestAttackTime) * LastAttackTimeWeight;

				item.Scoring = distanceScore + visibilityScore + lastAttackTimeScore;
			}
		});

	UpdateSlots(EnemyMeleeItems, NbMeleeSlots);
}

void UCFR_CombatManagerSubsystem::UpdateDistanceEnemies()
{
	const FVector playerLocation = Player->GetActorLocation();

	float oldestAttackTime = UGameplayStatics::GetTimeSeconds(this);
	for (FCFR_EnemyCombatItem& item : EnemyMeleeItems)
	{
		if (item.IsValid())
		{
			oldestAttackTime = std::min(oldestAttackTime, item.LastAttackTime);
		}
	}

	UpdateScoring(EnemyRangedItems, [this, playerLocation, oldestAttackTime](FCFR_EnemyCombatItem& item)
		{
			item.Distance = std::numeric_limits<float>::infinity();
			item.Scoring = std::numeric_limits<float>::infinity();

			if (item.IsValid())
			{
				item.Distance = FVector::Dist2D(playerLocation, item.Enemy->GetActorLocation());
				const float speed = item.Enemy->GetCurrentMaxSpeed();

				const float distanceScore = (item.Distance / speed) * DistanceWeight;
				const float visibilityScore = (UCFR_BlueprintFunctionLibrary::IsInFrustum(item.Enemy.Get()) ? 0.0 : IsNotInFrustumScore) * IsNotInFrustumWeight;
				const float lastAttackTimeScore = (item.LastAttackTime - oldestAttackTime) * LastAttackTimeWeight;

				item.Scoring = distanceScore + visibilityScore + lastAttackTimeScore;
			}
		});



	UpdateSlots(EnemyRangedItems, NbRangedSlots);
}

void UCFR_CombatManagerSubsystem::UpdateScoring(TArray<FCFR_EnemyCombatItem>& EnemyItems, const std::function<void(FCFR_EnemyCombatItem&)>& ScoringFunction)
{
	for (FCFR_EnemyCombatItem& item : EnemyItems)
	{
		if (item.IsValid())
		{
			ScoringFunction(item);
		}
	}

	EnemyItems.Sort([this](const FCFR_EnemyCombatItem& left, const FCFR_EnemyCombatItem& right)
		{
			if (left.IsValid() && right.IsValid())
			{
				return left.Scoring < right.Scoring;
			}
			else if (left.IsValid())
			{
				return true;
			}
			else
			{
				return false;
			}
		});
}

void UCFR_CombatManagerSubsystem::UpdateSlots(TArray<FCFR_EnemyCombatItem>& EnemyItems, int32 numSlots)
{
	TArray<int32> candidates;
	int32 numAttackers = 0;
	int32 numRecoveries = 0;

	PrepareCandidateData(EnemyItems, candidates, numAttackers, numRecoveries);

	const float currentTime = UGameplayStatics::GetTimeSeconds(this);
	int32 numFreeSlots = numSlots - numAttackers;
	while (numFreeSlots > 0 && candidates.Num())
	{
		const int32 candidateIndex = FindBestAttacker(candidates, EnemyItems);
		const int32 index = candidates[candidateIndex];
		auto& item = EnemyItems[index];

		// assert state holding
		ACFR_AIController* enemyController = item.Enemy->GetController<ACFR_AIController>();
		enemyController->SetEnemyAIState(ECFR_EnemyAIState::Attacking);
		item.LastAttackTime = currentTime;

		candidates.RemoveAtSwap(candidateIndex);
		--numFreeSlots;
	}
}

void UCFR_CombatManagerSubsystem::PrepareCandidateData(const TArray<FCFR_EnemyCombatItem>& EnemyItems, TArray<int32>& candidates, int32& numAttackers, int32& numRecoveries) const
{
	candidates.Empty();
	numAttackers = 0;
	numRecoveries = 0;

	const int32 lastIndex = EnemyItems.IndexOfByPredicate([](const FCFR_EnemyCombatItem& item) { return item.IsValid() == false; });
	for (int32 index = 0; index < lastIndex && index < NbHoldingEnemies; ++index)
	{
		const auto& item = EnemyItems[index];
		if (ACFR_AIController* enemyController = item.Enemy->GetController<ACFR_AIController>())
		{
			switch (enemyController->GetEnemyAIState())
			{
			case ECFR_EnemyAIState::Attacking:
				++numAttackers;
				break;
			case ECFR_EnemyAIState::Recovering:
				++numRecoveries;
				break;
			case ECFR_EnemyAIState::Holding:
				candidates.Add(index);
				break;
			default:
				break;
			}
		}
	}
}

int32 UCFR_CombatManagerSubsystem::FindBestAttacker(const TArray<int32>& candidates, const TArray<FCFR_EnemyCombatItem>& EnemyItems) const
{
	return 0;
}

int32 UCFR_CombatManagerSubsystem::FindNewAttacker(const TArray<int32>& candidates, const TArray<FCFR_EnemyCombatItem>& EnemyItems) const
{
	const int32 numCandidates = candidates.Num();

	if (numCandidates == 1)
	{
		return 0;
	}

	float totalScoring = 0.f;
	for (int32 index : candidates)
	{
		auto& item = EnemyItems[index];
		totalScoring += item.Scoring;
	}

	float totalSum = 0.0;
	TArray<float> candidatesWeights; candidatesWeights.Reserve(numCandidates);
	for (int32 index : candidates)
	{
		auto& item = EnemyItems[index];
		const float weight = totalScoring - item.Scoring;
		candidatesWeights.Add(weight + totalSum);
		totalSum += weight;
	}

	float randomNumber = FMath::RandRange(0.f, totalScoring * 2.f);
	for (int32 index = 0; index < (numCandidates - 1); ++index)
	{
		if (randomNumber < candidatesWeights[index])
		{
			return index;
		}
	}

	return numCandidates - 1;
}
