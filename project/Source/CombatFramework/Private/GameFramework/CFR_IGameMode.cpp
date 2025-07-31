
#include "GameFramework/CFR_IGameMode.h"

#include "CommonActivatableWidget.h"
#include "Kismet/GameplayStatics.h"

#include "Subsystems/CFR_PoolSubsystem.h"
#include "Subsystems/CFR_ArenaSubsystem.h"

ACFR_IGameMode::ACFR_IGameMode() = default;

void ACFR_IGameMode::StartPlay()
{
	Super::StartPlay();

	auto world = GetWorld();
	check(world);

	world->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());

	// Request actors to be pooled.
	if (auto poolManager = world->GetSubsystem<UCFR_PoolSubsystem>())
	{
		for (const auto actorPool : ActorPools)
		{
			poolManager->InitPool(actorPool.Key, actorPool.Value);
		}
	}

	// Pass initial wave to arena manager.
	if (auto arenaManager = world->GetSubsystem<UCFR_ArenaSubsystem>())
	{
		arenaManager->Init(InitialWave);
	}
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