
#include "GameFramework/CFR_MainGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

#include "Subsystems/CFR_ArenaSubsystem.h"

void ACFR_MainGameMode::StartPlay()
{
	Super::StartPlay();

	auto arenaManager = GetGameInstance()->GetSubsystem<UCFR_ArenaSubsystem>();
	check(arenaManager);
	arenaManager->OnArenaFinished.BindUObject(this, &ACFR_MainGameMode::PlayerWins);

	if (IntroSequence)
	{
		ALevelSequenceActor* levelSequenceActor;
		FMovieSceneSequencePlaybackSettings playbackSettings;
		auto levelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), IntroSequence, playbackSettings, levelSequenceActor);

		if (levelSequencePlayer)
		{
			CurrentLevelSequencePlayer = levelSequencePlayer;
			CurrentLevelSequencePlayer->Play();
			CurrentLevelSequencePlayer->OnFinished.AddDynamic(this, &ACFR_MainGameMode::HandlePlayerSpawn);
			CurrentLevelSequencePlayer->OnStop.AddDynamic(this, &ACFR_MainGameMode::HandlePlayerSpawn);
		}
	}
	else
	{
		HandlePlayerSpawn();
	}
}

void ACFR_MainGameMode::RestartPlayer(AController* InNewPlayerController)
{
	Super::RestartPlayer(InNewPlayerController);

	const auto arenaSubsystem = GetGameInstance()->GetSubsystem<UCFR_ArenaSubsystem>();
	arenaSubsystem->StartArena();
}

bool ACFR_MainGameMode::GetCanPlayerSpawn() const
{
	return bCanPlayerSpawn;
}

bool ACFR_MainGameMode::IsCutscenePlaying() const
{
	return CurrentLevelSequencePlayer && CurrentLevelSequencePlayer->IsPlaying();
}

void ACFR_MainGameMode::SkipCutscene()
{
	if (!IsCutscenePlaying())
	{
		return;
	}

	CurrentLevelSequencePlayer->Stop();

	Super::SkipCutscene();
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

void ACFR_MainGameMode::HandlePlayerSpawn()
{
	bCanPlayerSpawn = true;
	SpawnPlayer();
}
