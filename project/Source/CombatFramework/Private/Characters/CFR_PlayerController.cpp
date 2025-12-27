#include "Characters/CFR_PlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"

#include "GameFramework/CFR_IGameMode.h"
#include "Utils/CFR_CheatManager.h"

ACFR_PlayerController::ACFR_PlayerController()
{
	CheatClass = UCFR_CheatManager::StaticClass();
}

void ACFR_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (auto enhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		enhancedInputSubsystem->AddMappingContext(MappingContext, 0);
	}
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

void ACFR_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	auto enhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	check(enhancedInputComponent);

	enhancedInputComponent->BindAction(PauseGameAction, ETriggerEvent::Triggered, this, &ACFR_PlayerController::HandlePauseGameInput);

	const auto gameMode = UGameplayStatics::GetGameMode(this);
	if (const auto gameModeInterface = Cast<ACFR_IGameMode>(gameMode))
	{
		enhancedInputComponent->BindAction(SkipCutsceneAction, ETriggerEvent::Triggered, gameModeInterface, &ACFR_IGameMode::SkipCutscene);
	}
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
