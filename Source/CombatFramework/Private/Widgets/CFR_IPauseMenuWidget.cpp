#include "Widgets/CFR_IPauseMenuWidget.h"

#include "Kismet/GameplayStatics.h"

void UCFR_IPauseMenuWidget::Resume()
{
	const auto World = GetWorld();
	check(World);
	const auto PlayerController = UGameplayStatics::GetPlayerController(World, 0);
	check(PlayerController);

	PlayerController->SetInputMode(FInputModeGameOnly());
	UGameplayStatics::SetGamePaused(World, false);

	RemoveFromParent();
}

void UCFR_IPauseMenuWidget::ReturnToMainMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Return to Main Menu button in Pause Menu Widget is not yet implemented."));
}

void UCFR_IPauseMenuWidget::ExitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}
