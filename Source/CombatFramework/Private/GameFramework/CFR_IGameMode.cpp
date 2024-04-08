
#include "GameFramework/CFR_IGameMode.h"

#include "Blueprint/UserWidget.h"

void ACFR_IGameMode::PauseGame()
{
	const auto World = GetWorld();
	check(InGamePauseMenuWidget);
	check(World);

	// Open menu
	const auto ActiveWidget = UUserWidget::CreateWidgetInstance(*World, InGamePauseMenuWidget, FName("InGamePauseMenu"));
	ActiveWidget->AddToViewport();
}
