
#include "GameFramework/CFR_MainGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

#include "Subsystems/CFR_CinematicSubsystem.h"
#include "Actors/CFR_CinematicTrigger.h"
#include "Subsystems/CFR_ArenaSubsystem.h"

ACFR_CinematicTrigger* ACFR_MainGameMode::FindCinematicTrigger(UCFR_CinematicSubsystem* InCinematicSubsystem, ECinematicTriggerType InTriggerType)
{
	const TObjectPtr<ACFR_CinematicTrigger>* foundTrigger = InCinematicSubsystem->GetRegisteredTriggers().FindByPredicate([InTriggerType](const TObjectPtr<ACFR_CinematicTrigger>& InCinematicTrigger) {
		return InCinematicTrigger->TriggerType == InTriggerType;
		});

	return foundTrigger ? foundTrigger->Get() : nullptr;
}
void ACFR_MainGameMode::StartPlay()
{
	Super::StartPlay();

	const auto gameInstance = GetGameInstance();

	auto arenaManager = gameInstance->GetSubsystem<UCFR_ArenaSubsystem>();
	check(arenaManager);
	arenaManager->OnArenaFinished.BindUObject(this, &ACFR_MainGameMode::PlayerWins);

	auto cinematicSubsystem = gameInstance->GetSubsystem<UCFR_CinematicSubsystem>();
	check(cinematicSubsystem);

	auto world = GetWorld();
	check(world);

	world->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());

	if (auto cinematicTriggerActor = FindCinematicTrigger(cinematicSubsystem, ECinematicTriggerType::BeginPlay))
	{
		cinematicSubsystem->StartCinematic(cinematicTriggerActor);
		cinematicSubsystem->OnCinematicEnded.AddLambda([&]() {
			if (!bCanPlayerSpawn)
			{
				bCanPlayerSpawn = true;
				HandlePlayerSpawn();
			}
			});
	}
	else
	{
		bCanPlayerSpawn = true;
		HandlePlayerSpawn();
	}
}

void ACFR_MainGameMode::RestartPlayer(AController* InNewPlayerController)
{
	Super::RestartPlayer(InNewPlayerController);

	const auto arenaSubsystem = GetGameInstance()->GetSubsystem<UCFR_ArenaSubsystem>();
	arenaSubsystem->StartArena();
}

void ACFR_MainGameMode::PlayerWins()
{
	auto cinematicSubsystem = GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();

	const auto foundTrigger = FindCinematicTrigger(cinematicSubsystem, ECinematicTriggerType::EndPlay);

	if (!foundTrigger)
	{
		Super::PlayerWins();
		return;
	}

	cinematicSubsystem->StartCinematic(foundTrigger);

	if (cinematicSubsystem->IsCinematicPlaying())
	{
		cinematicSubsystem->OnCinematicEnded.AddLambda([this]() {
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
