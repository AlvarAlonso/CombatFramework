
#include "Widgets/CFR_IInGameMenuWidget.h"

#include "Kismet/GameplayStatics.h"

UWidget* UCFR_IInGameMenuWidget::NativeGetDesiredFocusTarget() const
{
	Super::NativeGetDesiredFocusTarget();

	// In PauseMenuWidgets should always exist a ResumeButton button.
	const auto Button = GetWidgetFromName(TEXT("MainMenuButton"));
	check(Button);

	return Button;
}

void UCFR_IInGameMenuWidget::ReturnToMainMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("LV_MainMenu"));
}

void UCFR_IInGameMenuWidget::ExitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}
