
#include "GameFramework/CFR_MainGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

#include "Actors/CFR_CinematicManager.h"
#include "Actors/CFR_CinematicTrigger.h"
#include "Subsystems/CFR_ArenaSubsystem.h"

void ACFR_MainGameMode::StartPlay()
{
	Super::StartPlay();

	auto arenaManager = GetGameInstance()->GetSubsystem<UCFR_ArenaSubsystem>();
	check(arenaManager);
	arenaManager->OnArenaFinished.BindUObject(this, &ACFR_IGameMode::PlayerWins);
}

void ACFR_MainGameMode::RestartPlayer(AController* InNewPlayerController)
{
	Super::RestartPlayer(InNewPlayerController);

	const auto arenaSubsystem = GetGameInstance()->GetSubsystem<UCFR_ArenaSubsystem>();
	arenaSubsystem->StartArena();
}

void ACFR_MainGameMode::PlayerWins()
{
	const TObjectPtr<ACFR_CinematicTrigger>* foundTrigger = CinematicManager->GetRegisteredTriggers().FindByPredicate([](const TObjectPtr<ACFR_CinematicTrigger>& InCinematicTrigger) {
		return InCinematicTrigger->TriggerType == ECinematicTriggerType::EndPlay;
		});

	if (!foundTrigger)
	{
		Super::PlayerWins();
		return;
	}

	CinematicManager->StartCinematic(foundTrigger->Get());

	if (CinematicManager->IsCinematicPlaying())
	{
		CinematicManager->OnCinematicEnded.AddLambda([this]() {
			Super::PlayerWins();
			});
	}
	else
	{
		Super::PlayerWins();
	}
}

int ACFR_MainGameMode::GetCurrentWaveIndex() const
{
	const auto arenaSubsystem = GetGameInstance()->GetSubsystem<UCFR_ArenaSubsystem>();
	check(arenaSubsystem);
	return arenaSubsystem->GetCurrentWaveIndex();
}

int ACFR_MainGameMode::GetScore() const
{
	const auto arenaSubsystem = GetGameInstance()->GetSubsystem<UCFR_ArenaSubsystem>();
	check(arenaSubsystem);
	return arenaSubsystem->GetScore();
}
