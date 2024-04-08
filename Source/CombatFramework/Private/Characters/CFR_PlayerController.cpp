// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/CFR_PlayerController.h"

#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"

#include "GameFramework/CFR_IGameMode.h"

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
