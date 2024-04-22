#include "Characters/CFR_PlayerController.h"

#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"

#include "GameFramework/CFR_MainGameMode.h"
#include "GameFramework/CFR_IGameMode.h"
#include "Utils/CFR_CheatManager.h"

ACFR_PlayerController::ACFR_PlayerController()
{
	CheatClass = UCFR_CheatManager::StaticClass();
}

bool ACFR_PlayerController::CanRestartPlayer()
{
	const bool bCanSpawn = Super::CanRestartPlayer();

	// TODO: This is a placeholder. We should not call GameMode's functions directly.
	// TODO: Create an Event and make different GameModes react to that event being broadcasted.
	if (const auto MainGameMode = Cast<ACFR_MainGameMode>(UGameplayStatics::GetGameMode(this)))
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
