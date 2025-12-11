#include "Subsystems/CFR_ArenaSubsystem.h"

#include "Animation/WidgetAnimation.h"
#include "Blueprint/UserWidget.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreaming.h"
#include "Templates/Function.h"

#include "Actors/CFR_Portal.h"
#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "Characters/CFR_AICharacter.h"
#include "Characters/CFR_CharacterBase.h"
#include "Subsystems/CFR_SpawnerSubsystem.h"
#include "Widgets/CFR_IStartEndWaveWidget.h"

bool UCFR_ArenaSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	if (this->GetClass()->IsInBlueprint() && Super::ShouldCreateSubsystem(Outer))
	{
		return true;
	}

	return false;
}

void UCFR_ArenaSubsystem::StartArena()
{
	check(!WaveDataAssets.IsEmpty());
	CurrentWaveDataAsset = WaveDataAssets[CurrentWaveIndex];
	SpawnWave();
}

int UCFR_ArenaSubsystem::GetCurrentLevelIndex() const
{
	return CurrentLevelIndex;
}

int UCFR_ArenaSubsystem::GetCurrentWaveIndex() const
{
	return CurrentWaveIndex;
}

int UCFR_ArenaSubsystem::GetScore() const
{
	return Score;
}

void UCFR_ArenaSubsystem::SpawnWave()
{
	StartWaveWidget->AddToViewport();

	const auto widgetAnimationEndTime = StartWaveWidget->AnimationWidget->GetEndTime();

	auto spawnWaveDelegate = [this]() -> void
		{
			//const auto currentWave = CurrentWaveDataAsset->[CurrentWaveIndex];
			for (const auto& enemies : CurrentWaveDataAsset->Enemies)
			{
				SpawnActors(enemies.Key, enemies.Value);
			}
		};

	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, spawnWaveDelegate, widgetAnimationEndTime, false);
}

void UCFR_ArenaSubsystem::SpawnActors(TSubclassOf<AActor> InActorType, int InNumber)
{
	const auto world = GetWorld();
	const auto spawnerSubsystem = world->GetSubsystem<UCFR_SpawnerSubsystem>();

	if (!spawnerSubsystem)
	{
		UE_LOG(LogTemp, Error, TEXT("No available spawner subsystem for the wave."));
		return;
	}

	const auto actorType = InActorType;
	const auto actorNumber = InNumber;
	const auto spawnedActors = spawnerSubsystem->SpawnActors(actorType, actorNumber);

	for (auto actor : spawnedActors)
	{
		if (auto character = Cast<ACFR_AICharacter>(actor))
		{
			character->Activate();

			EnemiesAliveCounter++;
			character->OnHandleDeathEvent.AddUObject(this, &UCFR_ArenaSubsystem::HandleEnemyDeath);
			if (OnEnemySpawned.IsBound())
			{
				OnEnemySpawned.Broadcast(character);
			}
		}
	}

	if (spawnedActors.Num() < actorNumber)
	{
		FTimerHandle timerHandle;
		world->GetTimerManager().SetTimer(timerHandle, [this, actorType, number = actorNumber - spawnedActors.Num()]()
			{
				SpawnActors(actorType, number);
			}, 1.0f, false);
	}
}

void UCFR_ArenaSubsystem::HandleWaveFinished()
{
	EndWaveWidget->AddToViewport();
	const auto endTime = EndWaveWidget->AnimationWidget->GetEndTime();

	auto startNextWave = [this]() -> void
		{
			CurrentWaveIndex++;
			if (CurrentWaveIndex >= WaveDataAssets.Num())
			{
				check(OnArenaFinished.IsBound());
				OnArenaFinished.Execute();
				return;
			}

			CurrentWaveDataAsset = WaveDataAssets[CurrentWaveIndex];
			const auto previousWaveDataAsset = WaveDataAssets[CurrentWaveIndex - 1];

			if (previousWaveDataAsset->bShouldTransitionLevel)
			{
				auto portalActor = Cast<ACFR_Portal>(UGameplayStatics::GetActorOfClass(GetWorld(), ACFR_Portal::StaticClass()));
				check(portalActor);

				portalActor->SetVisible();

				portalActor->OnPlayerTeleported.BindLambda([this]()
					{
						SpawnWave();
					});
			}
			else
			{
				OnWaveFinished.ExecuteIfBound();
				SpawnWave();
			}
		};


	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, startNextWave, endTime, false);
}

void UCFR_ArenaSubsystem::HandleEnemyDeath(ACFR_AICharacter* InDeathActor)
{
	EnemiesAliveCounter--;

	if (EnemiesAliveCounter <= 0)
	{
		HandleWaveFinished();
	}
}
