#include "Characters/CFR_PlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"

#include "Subsystems/CFR_CinematicSubsystem.h"
#include "Subsystems/CFR_WidgetSubsystem.h"
#include "GameFramework/CFR_IGameMode.h"
#include "Utils/CFR_CheatManager.h"

ACFR_PlayerController::ACFR_PlayerController()
{
	CheatClass = UCFR_CheatManager::StaticClass();
}

void ACFR_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(MappingContext);
	check(CinematicMappingContext);

	const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(gameMode);

	auto setUIMode = [this]()
		{
			SetInputMode(FInputModeUIOnly());
			Pause();
			SetShowMouseCursor(true);
		};

	auto setGameMode = [this]()
		{
			SetInputMode(FInputModeGameOnly());
			SetPause(false);
			SetShowMouseCursor(false);
		};

	gameMode->OnGameResumed.AddLambda(setGameMode);
	gameMode->OnGamePaused.AddLambda(setUIMode);
	gameMode->OnPlayerWins.AddLambda(setUIMode);
	gameMode->OnPlayerLoses.AddLambda(setUIMode);

	if (auto enhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		enhancedInputSubsystem->AddMappingContext(MappingContext, 0);
	}

	auto cinematicManager = GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();
	cinematicManager->OnCinematicStarted.AddLambda([this]()
		{
			auto enhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
			enhancedInputSubsystem->AddMappingContext(CinematicMappingContext, 10);
		});

	cinematicManager->OnCinematicEnded.AddLambda([this]()
		{
			auto enhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
			enhancedInputSubsystem->RemoveMappingContext(CinematicMappingContext);
		});
}

bool ACFR_PlayerController::CanRestartPlayer()
{
	const bool bCanSpawn = Super::CanRestartPlayer();

	if (const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		return gameMode->GetCanPlayerSpawn() && bCanSpawn;
	}

	return bCanSpawn;
}

void ACFR_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	auto enhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	check(enhancedInputComponent);

	enhancedInputComponent->BindAction(PauseGameAction, ETriggerEvent::Triggered, this, &ACFR_PlayerController::HandlePauseGameInput);
	enhancedInputComponent->BindAction(AnyInputAction, ETriggerEvent::Triggered, this, &ACFR_PlayerController::HandleAnyInput);
	enhancedInputComponent->BindAction(SkipCutsceneAction, ETriggerEvent::Triggered, this, &ACFR_PlayerController::HandleSkipCutsceneInput);
}

void ACFR_PlayerController::HandlePauseGameInput()
{
	const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(gameMode);
	check(!gameMode->IsPaused());

	const auto cinematicManager = GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();

	if (cinematicManager->IsCinematicPlaying())
	{
		return;
	}

	gameMode->PauseGame();
}

void ACFR_PlayerController::HandleSkipCutsceneInput()
{
	const auto widgetSubsystem = GetWorld()->GetSubsystem < UCFR_WidgetSubsystem>();
	if (!widgetSubsystem->IsSkipCutsceneWidgetVisible())
	{
		return;
	}

	const auto cinematicManager = GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();
	cinematicManager->SkipCinematic();
}

void ACFR_PlayerController::HandleAnyInput()
{
	OnAnyInputAction.Broadcast();
}
