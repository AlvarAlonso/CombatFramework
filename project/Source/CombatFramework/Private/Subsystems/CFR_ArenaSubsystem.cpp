#include "Subsystems/CFR_ArenaSubsystem.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_GameplayTags.h"
#include "Characters/CFR_CharacterBase.h"
#include "Subsystems/CFR_SpawnerSubsystem.h"

void UCFR_ArenaSubsystem::Init(UCFR_WaveDataAsset* InWaveDataAsset)
{
	if (!InWaveDataAsset)
	{
		return;
	}

	WaveDataAsset = MoveTemp(InWaveDataAsset);
}

void UCFR_ArenaSubsystem::StartArena()
{
	SpawnWave();
}

void UCFR_ArenaSubsystem::SpawnWave()
{
	if (!WaveDataAsset)
	{
		return;
	}

	for (const auto& enemies : WaveDataAsset->Enemies)
	{
		SpawnActors(enemies.Key, enemies.Value);
	}
}

void UCFR_ArenaSubsystem::SpawnActors(TSubclassOf<AActor> InActorType, const int InNumber)
{
	auto world = GetWorld();
	const auto& spawnerSubsystem = world->GetSubsystem<UCFR_SpawnerSubsystem>();

	if (!spawnerSubsystem)
	{
		UE_LOG(LogTemp, Error, TEXT("No available spawner subsystem for the wave."));
		return;
	}

	const auto spawnedActors = spawnerSubsystem->SpawnActors(InActorType, InNumber);

	for (auto& actor : spawnedActors)
	{
		if (auto character = Cast<ACFR_CharacterBase>(actor))
		{
			EnemiesAliveCounter++;
			character->OnHandleDeathEvent.AddUObject(this, &UCFR_ArenaSubsystem::HandleEnemyDeath);
			auto CFR_ASC = Cast<UCFR_AbilitySystemComponent>(character->GetAbilitySystemComponent());
			check(CFR_ASC);

			CFR_ASC->InitializeAttributes();
			CFR_ASC->RemoveLooseGameplayTag(FCFR_GameplayTags::Get().Status_Dead);
		}
	}

	if (spawnedActors.Num() < InNumber)
	{
		FTimerHandle timerHandle;
		world->GetTimerManager().SetTimer(timerHandle, [this, InActorType, number = InNumber - spawnedActors.Num()]()
			{
				SpawnActors(InActorType, number);
			}, 1.0f, false);
	}
}

void UCFR_ArenaSubsystem::HandleWaveFinished()
{
	WaveDataAsset = WaveDataAsset->NextWave;

	OnWaveFinished.ExecuteIfBound();

	if (!WaveDataAsset)
	{
		check(OnArenaFinished.IsBound());
		OnArenaFinished.Execute();
	}

	SpawnWave();
}

void UCFR_ArenaSubsystem::HandleEnemyDeath(ACFR_CharacterBase* InDeathActor)
{
	EnemiesAliveCounter--;

	if (EnemiesAliveCounter <= 0)
	{
		HandleWaveFinished();
	}
}
