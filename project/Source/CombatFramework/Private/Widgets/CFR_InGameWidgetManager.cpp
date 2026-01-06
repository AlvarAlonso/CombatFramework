#include "Widgets/CFR_InGameWidgetManager.h"

#include "Kismet/GameplayStatics.h"

#include "Characters/CFR_PlayerController.h"
#include "GameFramework/CFR_IGameMode.h"
#include "Widgets/CFR_IHUDWidget.h"
#include "Widgets/CFR_IPauseMenuWidget.h"
#include "Widgets/CFR_ISkipCutsceneWidget.h"

bool UCFR_InGameWidgetManager::Initialize()
{
	Super::Initialize();

	AddToViewport();
	SetVisibility(ESlateVisibility::HitTestInvisible);

	const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(gameMode);

	gameMode->OnGamePaused.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnGamePaused);
	gameMode->OnGameResumed.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnGameResumed);
	gameMode->OnPlayerSpawned.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnPlayerSpawned);
	gameMode->OnSkipCutscene.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnSkipCutscene);

	auto playerController = GetOwningPlayer<ACFR_PlayerController>();
	check(playerController);

	playerController->OnAnyInputAction.AddUObject(this, &UCFR_InGameWidgetManager::HandleOnShowSkipCutsceneWidget);

	return true;
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
	HUDWidget = Cast<UCFR_IHUDWidget>(CreateWidget(this, HUDWidgetType));
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

	PauseMenuWidget = Cast<UCFR_IPauseMenuWidget>(CreateWidget(this, PauseMenuWidgetType));
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

void UCFR_InGameWidgetManager::HandleOnSkipCutscene()
{
	SkipCutsceneWidget->SetVisibility(ESlateVisibility::Hidden);
}

void UCFR_InGameWidgetManager::HandleOnShowPlayerConditionWidget()
{
	// Implementation for showing player condition widget can be added here
}

void UCFR_InGameWidgetManager::HandleOnShowSkipCutsceneWidget()
{
	const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(gameMode);

	if (!gameMode->IsCutscenePlaying())
	{
		return;
	}

	if (!SkipCutsceneWidget)
	{
		SkipCutsceneWidget = Cast<UCFR_ISkipCutsceneWidget>(CreateWidget(this, SkipCutsceneWidgetType));
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
