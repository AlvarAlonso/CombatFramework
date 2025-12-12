
#include "GameFramework/CFR_MainGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

#include "Subsystems/CFR_ArenaSubsystem.h"

void ACFR_MainGameMode::StartPlay()
{
	Super::StartPlay();

	if (IntroSequence)
	{
		ALevelSequenceActor* levelSequenceActor;
		FMovieSceneSequencePlaybackSettings playbackSettings;
		auto levelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), IntroSequence, playbackSettings, levelSequenceActor);

		if (levelSequencePlayer)
		{
			levelSequencePlayer->Play();
			levelSequencePlayer->OnFinished.AddDynamic(this, &ACFR_MainGameMode::HandlePlayerSpawn);
		}
	}

	auto arenaManager = GetGameInstance()->GetSubsystem<UCFR_ArenaSubsystem>();
	check(arenaManager);
	arenaManager->OnArenaFinished.BindUObject(this, &ACFR_MainGameMode::PlayerWins);
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
	const auto PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	RestartPlayer(PlayerController);
}
