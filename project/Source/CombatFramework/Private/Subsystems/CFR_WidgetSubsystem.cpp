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
	Super::OnWorldBeginPlay(InWorld);

	OwningPlayerController = Cast<ACFR_PlayerController>(InWorld.GetFirstPlayerController());

	if (!OwningPlayerController.Get() || !OwningPlayerController.IsValid())
	{
		return;
	}

	OwningPlayerController->OnAnyInputAction.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnAnyInput);

	const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(gameMode);

	gameMode->OnGamePaused.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnGamePaused);
	gameMode->OnGameResumed.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnGameResumed);
	gameMode->OnPlayerSpawned.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnPlayerSpawned);
	gameMode->OnPlayerWins.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnPlayerWins);
	gameMode->OnPlayerLoses.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnPlayerLoses);

	const auto cinematicSubsystem = gameMode->GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();
	cinematicSubsystem->OnCinematicStarted.AddUObject(this, &UCFR_WidgetSubsystem::HideHUDWidget);
	cinematicSubsystem->OnCinematicEnded.AddUObject(this, &UCFR_WidgetSubsystem::ShowHUDWidget);
	cinematicSubsystem->OnCinematicEnded.AddUObject(this, &UCFR_WidgetSubsystem::HandleOnSkipCutscene);
}

void UCFR_WidgetSubsystem::ShowWidget(const FName InWidgetName)
{
	if (!WidgetClasses.Contains(InWidgetName))
	{
		return;
	}

	UUserWidget* widget = nullptr;

	if (Widgets.Contains(InWidgetName))
	{
		widget = Widgets.FindRef(InWidgetName);
		widget->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		widget = CreateWidget(OwningPlayerController.Get(), WidgetClasses[InWidgetName]);
		widget->AddToViewport();

		Widgets.Add(InWidgetName, widget);
	}

	if (auto activatableWidget = Cast<UCommonActivatableWidget>(widget))
	{
		activatableWidget->ActivateWidget();
	}
}

void UCFR_WidgetSubsystem::HideWidget(const FName InWidgetName)
{
	if (!WidgetClasses.Contains(InWidgetName))
	{
		return;
	}

	if (Widgets.Contains(InWidgetName))
	{
		auto widget = Widgets.FindRef(InWidgetName);

		if (auto activatableWidget = Cast<UCommonActivatableWidget>(widget))
		{
			activatableWidget->DeactivateWidget();
		}
		else
		{
			widget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

bool UCFR_WidgetSubsystem::IsWidgetVisible(const FName InWidgetName) const
{
	if (!Widgets.Contains(InWidgetName))
	{
		return false;
	}

	const auto widget = Widgets.FindRef(InWidgetName);

	return widget && widget->IsVisible();
}

void UCFR_WidgetSubsystem::SetWidgetVisibility(const FName InWidgetName, ESlateVisibility InVisibility)
{
	if (!Widgets.Contains(InWidgetName))
	{
		return;
	}

	auto widget = Widgets.FindRef(InWidgetName);
	widget->SetVisibility(InVisibility);
}

void UCFR_WidgetSubsystem::HandleOnPlayerSpawned()
{
	auto playerCharacter = Cast<ACFR_PlayerCharacter>(OwningPlayerController->GetPawn());

	playerCharacter->OnPlayerDamaged.AddLambda([this, playerCharacter](float InDamageTaken) {
		const auto normalizedHealth = playerCharacter->GetHealth() / playerCharacter->GetMaxHealth();

		auto widget = Cast<UCFR_IHUDWidget>(Widgets.FindRef("HUD"));
		check(widget);
		widget->SetHealth(normalizedHealth);
		});

	ShowWidget("HUD");
}

void UCFR_WidgetSubsystem::HandleOnGamePaused()
{
	const auto widgetSubsystem = GetWorld()->GetSubsystem<UCFR_WidgetSubsystem>();

	if (widgetSubsystem->IsWidgetVisible("HUD"))
	{
		SetWidgetVisibility("HUD", ESlateVisibility::Hidden);
	}

	if (widgetSubsystem->IsWidgetVisible("SkipCutscene"))
	{
		SetWidgetVisibility("SkipCutscene", ESlateVisibility::Hidden);
	}

	ShowWidget("Pause");
}

void UCFR_WidgetSubsystem::HandleOnGameResumed()
{
	if (IsWidgetVisible("Pause"))
	{
		HideWidget("Pause");
	}

	ShowWidget("HUD");
}

void UCFR_WidgetSubsystem::HandleOnPlayerWins()
{
	ShowWidget("PlayerWins");
}

void UCFR_WidgetSubsystem::HandleOnPlayerLoses()
{
	ShowWidget("PlayerLoses");
}

void UCFR_WidgetSubsystem::HandleOnSkipCutscene()
{
	HideWidget("SkipCutscene");
}

void UCFR_WidgetSubsystem::HandleOnAnyInput()
{
	const auto gameMode = UGameplayStatics::GetGameMode(this);
	const auto cinematicSubsystem = gameMode->GetGameInstance()->GetSubsystem<UCFR_CinematicSubsystem>();

	if (!cinematicSubsystem || !cinematicSubsystem->IsCinematicPlaying())
	{
		return;
	}

	if (!IsWidgetVisible("SkipCutscene"))
	{
		ShowWidget("SkipCutscene");
	}
	else
	{
		auto skipCutsceneWidget = Cast<UCFR_ISkipCutsceneWidget>(Widgets.FindRef("SkipCutscene"));

		if (skipCutsceneWidget)
		{
			skipCutsceneWidget->ResetTimer();
		}
	}
}

void UCFR_WidgetSubsystem::HideHUDWidget()
{
	auto HUDWidget = Cast<UCFR_IHUDWidget>(Widgets.FindRef("HUD"));
	SetWidgetVisibility("HUD", ESlateVisibility::Hidden);
}

void UCFR_WidgetSubsystem::ShowHUDWidget()
{
	auto HUDWidget = Cast<UCFR_IHUDWidget>(Widgets.FindRef("HUD"));
	SetWidgetVisibility("HUD", ESlateVisibility::HitTestInvisible);
}
