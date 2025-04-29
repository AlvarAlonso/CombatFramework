
#include "GameFramework/CFR_IGameMode.h"

#include "CommonActivatableWidget.h"
#include "Kismet/GameplayStatics.h"

void ACFR_IGameMode::StartPlay()
{
	Super::StartPlay();

	ActorPoolManager.InitPool(ACFR_CharacterBase::StaticClass(), 10);

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
}

void ACFR_IGameMode::PauseGame()
{
	const auto world = GetWorld();

	check(InGamePauseMenuWidget);
	check(world);

	// Open menu
	const auto ActiveWidget = Cast<UCommonActivatableWidget>(UUserWidget::CreateWidgetInstance(*world, InGamePauseMenuWidget, FName("InGamePauseMenu")));

	check(ActiveWidget);

	ActiveWidget->AddToViewport();
	ActiveWidget->ActivateWidget();
}

void ACFR_IGameMode::PlayerWins()
{
	ShowPlayerConditionWidget(PlayerWinsWidget);
}

void ACFR_IGameMode::PlayerLoses()
{
	ShowPlayerConditionWidget(PlayerLosesWidget);
}

const UCFR_ActorPoolManager& ACFR_IGameMode::GetPoolManager()
{
	return ActorPoolManager;
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