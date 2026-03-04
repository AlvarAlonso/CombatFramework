
#include "Widgets/CFR_IPauseMenuWidget.h"

#include "Kismet/GameplayStatics.h"

#include "GameFramework/CFR_IGameMode.h"
#include "Subsystems/CFR_WidgetSubsystem.h"

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
	const auto world = GetWorld();
	check(world);
	const auto PlayerController = UGameplayStatics::GetPlayerController(world, 0);
	check(PlayerController);

	const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
	check(gameMode);
	check(gameMode->IsPaused());

	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->SetShowMouseCursor(false);
	UGameplayStatics::SetGamePaused(world, false);

	gameMode->ResumeGame();
}
