
#include "GameFramework/CFR_IGameMode.h"

#include "CommonActivatableWidget.h"
#include "Kismet/GameplayStatics.h"

#include "Actors/CFR_CinematicTrigger.h"

ACFR_IGameMode::ACFR_IGameMode() = default;

void ACFR_IGameMode::StartPlay()
{
	Super::StartPlay();

	auto world = GetWorld();
	check(world);

	world->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());

	if (auto cutsceneTriggerActor = CheckIfInitialCutsceneExists())
	{
		FDelegateHandle cinematicHandle;
		FDelegateHandle skipHandle;
		auto spawnPlayerAfterInitialCutsceneDelegate = [&]() {
			if (!bCanPlayerSpawn)
			{
				bCanPlayerSpawn = true;
				HandlePlayerSpawn();
				OnCinematicEnded.Remove(cinematicHandle);
				OnSkipCutscene.Remove(skipHandle);
			}
			};

		OnCinematicEnded.AddLambda(spawnPlayerAfterInitialCutsceneDelegate);
	}
	else
	{
		bCanPlayerSpawn = true;
		HandlePlayerSpawn();
	}
}

void ACFR_IGameMode::PauseGame()
{
	OnGamePaused.Broadcast();
}

void ACFR_IGameMode::ResumeGame()
{
	OnGameResumed.Broadcast();
}

bool ACFR_IGameMode::GetCanPlayerSpawn() const
{
	return bCanPlayerSpawn;
}

void ACFR_IGameMode::PlayerWins()
{
	OnPlayerWins.Broadcast();
}

void ACFR_IGameMode::PlayerLoses()
{
	OnPlayerLoses.Broadcast();
}

void ACFR_IGameMode::StartCutscene()
{
	bIsCutscenePlaying = true;

	OnCinematicStarted.Broadcast();
}

void ACFR_IGameMode::EndCutscene()
{
	bIsCutscenePlaying = false;

	OnCinematicEnded.Broadcast();
}

bool ACFR_IGameMode::IsCutscenePlaying() const
{
	return bIsCutscenePlaying;
}

void ACFR_IGameMode::SkipCutscene()
{
	bIsCutscenePlaying = false;

	OnSkipCutscene.Broadcast();
}

void ACFR_IGameMode::NotifyEnemySpawned(ACFR_AICharacter* InEnemyCharacter)
{
	OnEnemySpawned.Broadcast(InEnemyCharacter);
}

void ACFR_IGameMode::NotifyEnemyKilled()
{
	OnEnemyKilled.Broadcast();
}

void ACFR_IGameMode::HandlePlayerSpawn()
{
	if (!bCanPlayerSpawn)
		return;

	RestartPlayer(UGameplayStatics::GetPlayerController(this, 0));

	OnPlayerSpawned.Broadcast();
}

ACFR_CinematicTrigger* ACFR_IGameMode::CheckIfInitialCutsceneExists()
{
	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(this, ACFR_CinematicTrigger::StaticClass(), foundActors);

	if (foundActors.IsEmpty())
	{
		return nullptr;
	}

	for (const auto foundActor : foundActors)
	{
		const auto cinematicTriggerActor = Cast<ACFR_CinematicTrigger>(foundActor);

		if (cinematicTriggerActor->TriggerType == ECinematicTriggerType::BeginPlay)
		{
			return cinematicTriggerActor;
		}
	}

	return nullptr;
}
