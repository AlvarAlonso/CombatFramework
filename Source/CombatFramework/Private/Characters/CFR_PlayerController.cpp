#include "Characters/CFR_PlayerController.h"

#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"

#include "GameFramework/CFR_IGameMode.h"
#include "Utils/CFR_CheatManager.h"

ACFR_PlayerController::ACFR_PlayerController()
{
	CheatClass = UCFR_CheatManager::StaticClass();
}

bool ACFR_PlayerController::CanRestartPlayer()
{
	const bool bCanSpawn = Super::CanRestartPlayer();

	if (const auto MainGameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		return MainGameMode->GetCanPlayerSpawn() && bCanSpawn;
	}

	return bCanSpawn;
}

void ACFR_PlayerController::HandlePauseGameInput()
{
	const auto GameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(GameMode);
	check(!GameMode->IsPaused());

	// Pause game, InputMode should be UI only.
	SetInputMode(FInputModeUIOnly());
	Pause();
	SetShowMouseCursor(true);
	GameMode->PauseGame();
}
