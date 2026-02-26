#include "Subsystems/CFR_ArenaSubsystem.h"

#include "Animation/WidgetAnimation.h"
#include "Blueprint/UserWidget.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreaming.h"
#include "Templates/Function.h"

#include "Actors/CFR_CinematicTrigger.h"
#include "Subsystems/CFR_CinematicSubsystem.h"
#include "Actors/CFR_Portal.h"
#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "Characters/CFR_CharacterBase.h"
#include "GameFramework/CFR_IGameMode.h"
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

void UCFR_ArenaSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FWorldDelegates::OnWorldCleanup.AddUObject(this, &UCFR_ArenaSubsystem::Cleanup);
}

void UCFR_ArenaSubsystem::StartArena()
{
	check(StartWaveWidget);
	check(EndWaveWidget);

	const auto world = GetWorld();

	const auto spawnerSubsystem = world->GetSubsystem<UCFR_SpawnerSubsystem>();
	spawnerSubsystem->OnEnemySpawned.AddUObject(this, &UCFR_ArenaSubsystem::HandleOnEnemySpawned);
	spawnerSubsystem->OnEnemyKilled.AddUObject(this, &UCFR_ArenaSubsystem::HandleOnEnemyKilled);

	for (const auto wave : WaveDataAssets)
	{
		WaveDataAssetsQueue.Enqueue(wave);
	}

	check(!WaveDataAssets.IsEmpty());
	StartNextWave();
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

void UCFR_ArenaSubsystem::StartNextWave()
{
	CurrentWaveIndex++;

	WaveDataAssetsQueue.Dequeue(CurrentWaveDataAsset);

	if (CurrentWaveDataAsset->LevelSequence)
	{
		TriggerWaveCutscene();
	}
	else
	{
		SpawnWave();
	}
}

void UCFR_ArenaSubsystem::TriggerWaveCutscene()
{
	const auto cinematicSubsystem = GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();

	if (!cinematicSubsystem)
	{
		return;
	}

	const auto cinematicTrigger = GetWorld()->SpawnActor<ACFR_CinematicTrigger>();
	cinematicTrigger->CinematicSequence = CurrentWaveDataAsset->LevelSequence;
	cinematicSubsystem->StartCinematic(cinematicTrigger);
	cinematicSubsystem->OnCinematicEnded.RemoveAll(this);
	cinematicSubsystem->OnCinematicEnded.AddUObject(this, &UCFR_ArenaSubsystem::SpawnWave);
}

void UCFR_ArenaSubsystem::SpawnWave()
{
	StartWaveWidget->AddToViewport();
	StartWaveWidget->UnbindAllFromAnimationFinished(StartWaveWidget->AnimationWidget);

	if (!StartWaveWidget->AnimationWidget)
	{
		HandleSpawnWave();
		return;
	}

	FWidgetAnimationDynamicEvent widgetDynamicEvent;
	widgetDynamicEvent.BindUFunction(this, "HandleSpawnWave");
	StartWaveWidget->BindToAnimationFinished(StartWaveWidget->AnimationWidget, MoveTemp(widgetDynamicEvent));
}

void UCFR_ArenaSubsystem::SpawnActors(TSubclassOf<AActor> InActorType, int InNumber)
{
	const auto world = GetWorld();
	const auto spawnerSubsystem = world->GetSubsystem<UCFR_SpawnerSubsystem>();

	if (!spawnerSubsystem)
	{
		UE_LOG(LogTemp, Error, TEXT("No available spawner subsystem or valid game mode for the wave."));
		return;
	}

	const auto spawnedActors = spawnerSubsystem->SpawnActors(InActorType, InNumber);

	if (spawnedActors.Num() >= InNumber)
	{
		return;
	}

	FTimerHandle timerHandle;
	world->GetTimerManager().SetTimer(timerHandle, FTimerDelegate::CreateUObject(this, &UCFR_ArenaSubsystem::HandleRetrySpawnWave, InActorType, InNumber - spawnedActors.Num()), 1.0f, false);
}

void UCFR_ArenaSubsystem::HandleWaveFinished()
{
	const auto world = GetWorld();
	EndWaveWidget->AddToViewport();
	EndWaveWidget->UnbindAllFromAnimationFinished(EndWaveWidget->AnimationWidget);

	const bool bIsArenaFinished = WaveDataAssetsQueue.IsEmpty();

	if (bIsArenaFinished)
	{
		check(OnArenaFinished.IsBound());
		const auto spawnerSubsystem = GetWorld()->GetSubsystem<UCFR_SpawnerSubsystem>();
		spawnerSubsystem->OnEnemySpawned.RemoveAll(this);
		spawnerSubsystem->OnEnemyKilled.RemoveAll(this);

		const auto cinematicSubsystem = GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();
		cinematicSubsystem->OnCinematicEnded.RemoveAll(this);

		FWidgetAnimationDynamicEvent endArenaWidgetAnimationDynamicEvent;
		endArenaWidgetAnimationDynamicEvent.BindUFunction(this, "HandleOnArenaFinished");
		EndWaveWidget->BindToAnimationFinished(EndWaveWidget->AnimationWidget, MoveTemp(endArenaWidgetAnimationDynamicEvent));

		return;
	}

	if (CurrentWaveDataAsset->bShouldTransitionLevel)
	{
		auto portalActor = Cast<ACFR_Portal>(UGameplayStatics::GetActorOfClass(world, ACFR_Portal::StaticClass()));
		check(portalActor);

		portalActor->SetVisible();
		portalActor->OnPlayerTeleported.BindUObject(this, &UCFR_ArenaSubsystem::StartNextWave);

		return;
	}

	FWidgetAnimationDynamicEvent widgetDynamicEvent;
	widgetDynamicEvent.BindUFunction(this, "StartNextWave");
	EndWaveWidget->BindToAnimationFinished(EndWaveWidget->AnimationWidget, MoveTemp(widgetDynamicEvent));
}

void UCFR_ArenaSubsystem::HandleOnEnemySpawned(ACFR_AICharacter* /*InEnemyCharacter*/)
{
	EnemiesAliveCounter++;
}

void UCFR_ArenaSubsystem::HandleOnEnemyKilled()
{
	EnemiesAliveCounter--;

	if (EnemiesAliveCounter <= 0)
	{
		HandleWaveFinished();
	}
}

void UCFR_ArenaSubsystem::HandleSpawnWave()
{
	for (const auto& enemies : CurrentWaveDataAsset->Enemies)
	{
		SpawnActors(enemies.Key, enemies.Value);
	}
}

void UCFR_ArenaSubsystem::HandleRetrySpawnWave(TSubclassOf<AActor> InActorType, int InRemaining)
{
	SpawnActors(InActorType, InRemaining);
}

void UCFR_ArenaSubsystem::HandleOnArenaFinished()
{
	OnArenaFinished.Execute();
}

void UCFR_ArenaSubsystem::Cleanup(UWorld* /*World*/, bool /*bSessionEnded*/, bool /*bCleanupResources*/)
{
	CurrentLevelIndex = 0;
	CurrentWaveIndex = -1;
	EnemiesAliveCounter = 0;
	Score = 0;

	CurrentWaveDataAsset = nullptr;
	WaveDataAssetsQueue.Empty();
}
