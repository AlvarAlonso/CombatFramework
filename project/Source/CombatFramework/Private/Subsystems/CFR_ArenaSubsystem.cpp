#include "Subsystems/CFR_ArenaSubsystem.h"

#include "Animation/WidgetAnimation.h"
#include "Blueprint/UserWidget.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "Characters/CFR_AICharacter.h"
#include "Characters/CFR_CharacterBase.h"
#include "Subsystems/CFR_SpawnerSubsystem.h"
#include "Widgets/CFR_IStartEndWaveWidget.h"

void UCFR_ArenaSubsystem::Init(UCFR_WaveDataAsset* InWaveDataAsset)
{
	if (!InWaveDataAsset)
	{
		return;
	}

	WaveDataAsset = MoveTemp(InWaveDataAsset);

	auto startWaveWidgetClass = StaticLoadClass(UUserWidget::StaticClass(), nullptr, TEXT("/Game/CombatFrameworkContent/UI/Widgets/InGame/WBP_StartWave.WBP_StartWave_C"));
	auto endWaveWidgetClass = StaticLoadClass(UUserWidget::StaticClass(), nullptr, TEXT("/Game/CombatFrameworkContent/UI/Widgets/InGame/WBP_EndWave.WBP_EndWave_C"));
	check(startWaveWidgetClass);
	check(endWaveWidgetClass);

	const auto world = GetWorld();
	check(world);

	StartWaveWidget = Cast<UCFR_IStartEndWaveWidget>(CreateWidget<UUserWidget>(world, startWaveWidgetClass));
	EndWaveWidget = Cast<UCFR_IStartEndWaveWidget>(CreateWidget<UUserWidget>(world, endWaveWidgetClass));
}

void UCFR_ArenaSubsystem::StartArena()
{
	SpawnWave();
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
	if (!WaveDataAsset)
	{
		return;
	}

	StartWaveWidget->AddToViewport();

	const auto endTime = StartWaveWidget->AnimationWidget->GetEndTime();

	auto delegateFunc = [this]() -> void
		{
			for (const auto& enemies : WaveDataAsset->Enemies)
			{
				SpawnActors(enemies.Key, enemies.Value);
			}
		};


	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, delegateFunc, endTime, false);
}

void UCFR_ArenaSubsystem::SpawnActors(TSubclassOf<AActor> InActorType, const int InNumber)
{
	const auto world = GetWorld();
	const auto& spawnerSubsystem = world->GetSubsystem<UCFR_SpawnerSubsystem>();

	if (!spawnerSubsystem)
	{
		UE_LOG(LogTemp, Error, TEXT("No available spawner subsystem for the wave."));
		return;
	}

	const auto spawnedActors = spawnerSubsystem->SpawnActors(InActorType, InNumber);

	for (auto& actor : spawnedActors)
	{
		if (auto character = Cast<ACFR_AICharacter>(actor))
		{
			character->Activate();

			EnemiesAliveCounter++;
			character->OnHandleDeathEvent.AddUObject(this, &UCFR_ArenaSubsystem::HandleEnemyDeath);
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
	EndWaveWidget->AddToViewport();
	const auto endTime = EndWaveWidget->AnimationWidget->GetEndTime();

	auto delegateFunc = [this]() -> void
		{
			WaveDataAsset = WaveDataAsset->NextWave;
			CurrentWaveIndex++;

			if (!WaveDataAsset)
			{
				check(OnArenaFinished.IsBound());
				OnArenaFinished.Execute();
			}
			else
			{
				OnWaveFinished.ExecuteIfBound();
				SpawnWave();
			}
		};


	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, delegateFunc, endTime, false);
}

void UCFR_ArenaSubsystem::HandleEnemyDeath(ACFR_AICharacter* InDeathActor)
{
	EnemiesAliveCounter--;

	if (EnemiesAliveCounter <= 0)
	{
		HandleWaveFinished();
	}
}
