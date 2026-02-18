
#include "GameFramework/CFR_IGameMode.h"

#include "CommonActivatableWidget.h"
#include "Kismet/GameplayStatics.h"

#include "Actors/CFR_CinematicTrigger.h"
#include "Actors/CFR_CinematicManager.h"

ACFR_IGameMode::ACFR_IGameMode() = default;

void ACFR_IGameMode::StartPlay()
{
	CinematicManager = NewObject<UCFR_CinematicManager>(this, UCFR_CinematicManager::StaticClass());

	Super::StartPlay();

	auto world = GetWorld();
	check(world);

	world->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());

	if (auto cutsceneTriggerActor = CheckIfInitialCutsceneExists())
	{
		FDelegateHandle cinematicHandle;
		auto spawnPlayerAfterInitialCutsceneDelegate = [&]() {
			if (!bCanPlayerSpawn)
			{
				bCanPlayerSpawn = true;
				HandlePlayerSpawn();
				CinematicManager->OnCinematicEnded.Remove(cinematicHandle);
			}
			};

		CinematicManager->OnCinematicEnded.AddLambda(spawnPlayerAfterInitialCutsceneDelegate);
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
