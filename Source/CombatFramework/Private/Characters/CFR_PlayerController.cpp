// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/CFR_PlayerController.h"

#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"

#include "GameFramework/CFR_MainGameMode.h"
#include "GameFramework/CFR_IGameMode.h"

bool ACFR_PlayerController::CanRestartPlayer()
{
	const bool bCanSpawn = Super::CanRestartPlayer();

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
