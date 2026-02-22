#include "Subsystems/CFR_WidgetSubsystem.h"

#include "Kismet/GameplayStatics.h"

#include "Subsystems/CFR_CinematicSubsystem.h"
#include "Characters/CFR_PlayerCharacter.h"
#include "Characters/CFR_PlayerController.h"
#include "GameFramework/CFR_IGameMode.h"
#include "Widgets/CFR_IHUDWidget.h"
#include "Widgets/CFR_IPauseMenuWidget.h"
#include "Widgets/CFR_ISkipCutsceneWidget.h"

bool UCFR_WidgetSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	if (this->GetClass()->IsInBlueprint() && Super::ShouldCreateSubsystem(Outer))
	{
		return true;
	}

	return false;
}

void UCFR_WidgetSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	OwningPlayerController = Cast<ACFR_PlayerController>(InWorld.GetFirstPlayerController());
	OwningPlayerController->OnAnyInputAction.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnAnyInput);

	const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(gameMode);

	gameMode->OnGamePaused.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnGamePaused);
	gameMode->OnGameResumed.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnGameResumed);
	gameMode->OnPlayerSpawned.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnPlayerSpawned);
	gameMode->OnPlayerWins.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnPlayerWins);
	gameMode->OnPlayerLoses.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnPlayerLoses);

	const auto cinematicManager = gameMode->GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();
	cinematicManager->OnCinematicStarted.AddUObject(this, &UCFR_WidgetSubsystem::HideHUDWidget);
	cinematicManager->OnCinematicEnded.AddUObject(this, &UCFR_WidgetSubsystem::ShowHUDWidget);
}

bool UCFR_WidgetSubsystem::IsHUDWidgetVisible() const
{
	return HUDWidget && HUDWidget->IsVisible();
}

bool UCFR_WidgetSubsystem::IsSkipCutsceneWidgetVisible() const
{
	return SkipCutsceneWidget && SkipCutsceneWidget->IsVisible();
}

void UCFR_WidgetSubsystem::HandleOnPlayerSpawned()
{
	auto playerCharacter = Cast<ACFR_PlayerCharacter>(OwningPlayerController->GetPawn());

	playerCharacter->OnPlayerDamaged.AddLambda([this, playerCharacter](float InDamageTaken) {
		const auto normalizedHealth = playerCharacter->GetHealth() / playerCharacter->GetMaxHealth();
		check(HUDWidget);
		HUDWidget->SetHealth(normalizedHealth);
		});

	HUDWidget = Cast<UCFR_IHUDWidget>(CreateWidget(OwningPlayerController.Get(), HUDWidgetType));
	HUDWidget->AddToViewport();
}

void UCFR_WidgetSubsystem::HandleOnGamePaused()
{
	if (IsHUDWidgetVisible())
	{
		HUDWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (IsSkipCutsceneWidgetVisible())
	{
		SkipCutsceneWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	PauseMenuWidget = Cast<UCFR_IPauseMenuWidget>(CreateWidget(OwningPlayerController.Get(), PauseMenuWidgetType));
	PauseMenuWidget->AddToViewport();
	PauseMenuWidget->ActivateWidget();
}

void UCFR_WidgetSubsystem::HandleOnGameResumed()
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

void UCFR_WidgetSubsystem::HandleOnPlayerWins()
{
	auto playerWinsWidget = Cast<UCommonActivatableWidget>(CreateWidget(OwningPlayerController.Get(), PlayerWinsWidgetType));
	playerWinsWidget->AddToViewport();
	playerWinsWidget->ActivateWidget();
}

void UCFR_WidgetSubsystem::HandleOnPlayerLoses()
{
	auto playerLosesWidget = Cast<UCommonActivatableWidget>(CreateWidget(OwningPlayerController.Get(), PlayerLosesWidgetType));
	playerLosesWidget->AddToViewport();
	playerLosesWidget->ActivateWidget();
}

void UCFR_WidgetSubsystem::HandleOnSkipCutscene()
{
	SkipCutsceneWidget->SetVisibility(ESlateVisibility::Hidden);
}

void UCFR_WidgetSubsystem::HandleOnAnyInput()
{
	const auto gameMode = UGameplayStatics::GetGameMode(this);
	const auto cinematicManager = gameMode->GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();

	if (!cinematicManager || !cinematicManager->IsCinematicPlaying())
	{
		return;
	}

	if (!SkipCutsceneWidget)
	{
		SkipCutsceneWidget = Cast<UCFR_ISkipCutsceneWidget>(CreateWidget(OwningPlayerController.Get(), SkipCutsceneWidgetType));
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

void UCFR_WidgetSubsystem::HideHUDWidget()
{
	if (HUDWidget)
	{
		HUDWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UCFR_WidgetSubsystem::ShowHUDWidget()
{
	if (HUDWidget)
	{
		HUDWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}
