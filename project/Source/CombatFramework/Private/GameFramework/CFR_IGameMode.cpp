
#include "GameFramework/CFR_IGameMode.h"

#include "CommonActivatableWidget.h"
#include "Kismet/GameplayStatics.h"

ACFR_IGameMode::ACFR_IGameMode() = default;

void ACFR_IGameMode::StartPlay()
{
	Super::StartPlay();

	auto world = GetWorld();
	check(world);

	world->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
}

void ACFR_IGameMode::PauseGame()
{
	const auto world = GetWorld();

	check(InGamePauseMenuWidgetType);
	check(world);

	// Open menu
	const auto ActiveWidget = Cast<UCommonActivatableWidget>(UUserWidget::CreateWidgetInstance(*world, InGamePauseMenuWidgetType, FName("InGamePauseMenu")));

	check(ActiveWidget);

	ActiveWidget->AddToViewport();
	ActiveWidget->ActivateWidget();
}

void ACFR_IGameMode::PlayerWins()
{
	ShowPlayerConditionWidget(PlayerWinsWidgetType);
}

void ACFR_IGameMode::PlayerLoses()
{
	ShowPlayerConditionWidget(PlayerLosesWidgetType);
}

void ACFR_IGameMode::ShowSkipCutsceneWidget()
{
	UE_LOG(LogTemp, Warning, TEXT("ShowSkipCutsceneWidget not implemented in derived class"));
}

void ACFR_IGameMode::SkipCutscene()
{
	UE_LOG(LogTemp, Warning, TEXT("SkipCutscene not implemented in derived class"));
}

void ACFR_IGameMode::ShowPlayerConditionWidget(TSubclassOf<UUserWidget> InWidget)
{
	const auto world = GetWorld();

	check(InWidget != nullptr);
	check(world);

	const auto playerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (!playerController)
	{
		return;
	}

	playerController->SetInputMode(FInputModeUIOnly());

	const auto widget = Cast<UCommonActivatableWidget>(UUserWidget::CreateWidgetInstance(*world, InWidget, FName("PlayerConditionWidget")));
	check(widget);

	widget->AddToViewport();
	widget->ActivateWidget();
}