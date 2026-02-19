
#include "GameFramework/CFR_IGameMode.h"

#include "Kismet/GameplayStatics.h"

ACFR_IGameMode::ACFR_IGameMode() = default;

void ACFR_IGameMode::StartPlay()
{
	Super::StartPlay();
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

void ACFR_IGameMode::HandlePlayerSpawn()
{
	if (!bCanPlayerSpawn)
		return;

	RestartPlayer(UGameplayStatics::GetPlayerController(this, 0));

	OnPlayerSpawned.Broadcast();
}
