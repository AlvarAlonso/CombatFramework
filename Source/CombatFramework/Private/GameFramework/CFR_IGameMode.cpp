
#include "GameFramework/CFR_IGameMode.h"

#include "CommonActivatableWidget.h"
#include "Kismet/GameplayStatics.h"

void ACFR_IGameMode::StartPlay()
{
	Super::StartPlay();

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
}

void ACFR_IGameMode::PauseGame()
{
	const auto World = GetWorld();
	check(InGamePauseMenuWidget);
	check(World);

	// Open menu
	const auto ActiveWidget = Cast<UCommonActivatableWidget>(UUserWidget::CreateWidgetInstance(*World, InGamePauseMenuWidget, FName("InGamePauseMenu")));
	check(ActiveWidget);

	ActiveWidget->AddToViewport();
	ActiveWidget->ActivateWidget();
}
