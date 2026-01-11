#include "Widgets/CFR_InGameWidgetManager.h"

#include "Kismet/GameplayStatics.h"

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
	gameMode->OnSkipCutscene.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnSkipCutscene);
	gameMode->OnPlayerWins.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnPlayerWins);
	gameMode->OnPlayerLoses.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnPlayerLoses);
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
	const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(gameMode);

	if (!gameMode->IsCutscenePlaying())
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
