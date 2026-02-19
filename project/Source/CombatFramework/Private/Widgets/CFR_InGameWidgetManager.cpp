#include "Widgets/CFR_InGameWidgetManager.h"

#include "Kismet/GameplayStatics.h"

#include "Subsystems/CFR_CinematicSubsystem.h"
#include "Characters/CFR_PlayerCharacter.h"
#include "Characters/CFR_PlayerController.h"
#include "GameFramework/CFR_IGameMode.h"
#include "Widgets/CFR_IHUDWidget.h"
#include "Widgets/CFR_IPauseMenuWidget.h"
#include "Widgets/CFR_ISkipCutsceneWidget.h"

void UCFR_InGameWidgetManager::Initialize(ACFR_PlayerController* InOwningPlayerController)
{
	OwningPlayerController = InOwningPlayerController;
	OwningPlayerController->OnAnyInputAction.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnAnyInput);

	const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(gameMode);

	gameMode->OnGamePaused.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnGamePaused);
	gameMode->OnGameResumed.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnGameResumed);
	gameMode->OnPlayerSpawned.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnPlayerSpawned);
	gameMode->OnPlayerWins.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnPlayerWins);
	gameMode->OnPlayerLoses.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnPlayerLoses);

	const auto cinematicManager = gameMode->GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();
	cinematicManager->OnCinematicStarted.AddUObject(this, &UCFR_InGameWidgetManager::HideHUDWidget);
	cinematicManager->OnCinematicEnded.AddUObject(this, &UCFR_InGameWidgetManager::ShowHUDWidget);
}

bool UCFR_InGameWidgetManager::IsHUDWidgetVisible() const
{
	return HUDWidget && HUDWidget->IsVisible();
}

bool UCFR_InGameWidgetManager::IsSkipCutsceneWidgetVisible() const
{
	return SkipCutsceneWidget && SkipCutsceneWidget->IsVisible();
}

void UCFR_InGameWidgetManager::HandleOnPlayerSpawned()
{
	auto playerCharacter = Cast<ACFR_PlayerCharacter>(OwningPlayerController->GetPawn());

	playerCharacter->OnPlayerDamaged.AddLambda([this, playerCharacter](float InDamageTaken) {
		const auto normalizedHealth = playerCharacter->GetHealth() / playerCharacter->GetMaxHealth();
		check(HUDWidget);
		HUDWidget->SetHealth(normalizedHealth);
		});

	HUDWidget = Cast<UCFR_IHUDWidget>(CreateWidget(OwningPlayerController.Get(), OwningPlayerController->HUDWidgetType));
	HUDWidget->AddToViewport();
}

void UCFR_InGameWidgetManager::HandleOnGamePaused()
{
	if (IsHUDWidgetVisible())
	{
		HUDWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (IsSkipCutsceneWidgetVisible())
	{
		SkipCutsceneWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	PauseMenuWidget = Cast<UCFR_IPauseMenuWidget>(CreateWidget(OwningPlayerController.Get(), OwningPlayerController->PauseMenuWidgetType));
	PauseMenuWidget->AddToViewport();
	PauseMenuWidget->ActivateWidget();
}

void UCFR_InGameWidgetManager::HandleOnGameResumed()
{
	if (PauseMenuWidget)
	{
		PauseMenuWidget->DeactivateWidget();
		PauseMenuWidget->RemoveFromParent();
		PauseMenuWidget = nullptr;
	}

	if (HUDWidget)
	{
		HUDWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}

void UCFR_InGameWidgetManager::HandleOnPlayerWins()
{
	auto playerWinsWidget = Cast<UCommonActivatableWidget>(CreateWidget(OwningPlayerController.Get(), OwningPlayerController->PlayerWinsWidgetType));
	playerWinsWidget->AddToViewport();
	playerWinsWidget->ActivateWidget();
}

void UCFR_InGameWidgetManager::HandleOnPlayerLoses()
{
	auto playerLosesWidget = Cast<UCommonActivatableWidget>(CreateWidget(OwningPlayerController.Get(), OwningPlayerController->PlayerLosesWidgetType));
	playerLosesWidget->AddToViewport();
	playerLosesWidget->ActivateWidget();
}

void UCFR_InGameWidgetManager::HandleOnSkipCutscene()
{
	SkipCutsceneWidget->SetVisibility(ESlateVisibility::Hidden);
}

void UCFR_InGameWidgetManager::HandleOnAnyInput()
{
	const auto gameMode = UGameplayStatics::GetGameMode(this);
	const auto cinematicManager = gameMode->GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();

	if (!cinematicManager || !cinematicManager->IsCinematicPlaying())
	{
		return;
	}

	if (!SkipCutsceneWidget)
	{
		SkipCutsceneWidget = Cast<UCFR_ISkipCutsceneWidget>(CreateWidget(OwningPlayerController.Get(), OwningPlayerController->SkipCutsceneWidgetType));
		SkipCutsceneWidget->AddToViewport();
	}
	else if (!SkipCutsceneWidget->IsVisible())
	{
		SkipCutsceneWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
	else
	{
		SkipCutsceneWidget->ResetTimer();
	}
}

void UCFR_InGameWidgetManager::HideHUDWidget()
{
	if (HUDWidget)
	{
		HUDWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UCFR_InGameWidgetManager::ShowHUDWidget()
{
	if (HUDWidget)
	{
		HUDWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}
