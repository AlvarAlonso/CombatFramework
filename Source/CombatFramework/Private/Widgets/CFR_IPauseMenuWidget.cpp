
#include "Widgets/CFR_IPauseMenuWidget.h"

#include "Kismet/GameplayStatics.h"

UWidget* UCFR_IPauseMenuWidget::NativeGetDesiredFocusTarget() const
{
	Super::NativeGetDesiredFocusTarget();

	// In PauseMenuWidgets should always exist a ResumeButton button.
	const auto Button = GetWidgetFromName(TEXT("ResumeButton"));
	check(Button);

	return Button;
}

void UCFR_IPauseMenuWidget::Resume()
{
	const auto World = GetWorld();
	check(World);
	const auto PlayerController = UGameplayStatics::GetPlayerController(World, 0);
	check(PlayerController);

	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->SetShowMouseCursor(false);
	UGameplayStatics::SetGamePaused(World, false);

	RemoveFromParent();
}
