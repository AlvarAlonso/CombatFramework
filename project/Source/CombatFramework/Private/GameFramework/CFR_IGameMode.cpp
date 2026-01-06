
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
	OnGamePaused.Broadcast();
}

void ACFR_IGameMode::ResumeGame()
{
	OnGameResumed.Broadcast();
}

bool ACFR_IGameMode::GetCanPlayerSpawn() const
{
	return true;
}

void ACFR_IGameMode::SpawnPlayer()
{
	RestartPlayer(Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0)));

	OnPlayerSpawned.Broadcast();
}

void ACFR_IGameMode::PlayerWins()
{
	ShowPlayerConditionWidget(PlayerWinsWidgetType);
}

void ACFR_IGameMode::PlayerLoses()
{
	ShowPlayerConditionWidget(PlayerLosesWidgetType);
}

bool ACFR_IGameMode::IsCutscenePlaying() const
{
	return false;
}

void ACFR_IGameMode::SkipCutscene()
{
	OnSkipCutscene.Broadcast();
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