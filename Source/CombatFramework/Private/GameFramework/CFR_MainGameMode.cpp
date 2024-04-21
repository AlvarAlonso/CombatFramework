
#include "GameFramework/CFR_MainGameMode.h"

#include "Blueprint/UserWidget.h"
#include "CommonActivatableWidget.h"
#include "Kismet/GameplayStatics.h"

void ACFR_MainGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	// TODO Should we create the widget instances at game initialization?
	//PlayerWinsWidget = Cast<UCommonActivatableWidget>(UUserWidget::CreateWidgetInstance(GetWorld(), PlayerWinsWidget, FName("InGamePauseMenu")));
}

void ACFR_MainGameMode::StartPlay()
{
	Super::StartPlay();

	const auto SetPlayerSpawnToTrue = [this]()
		{
			bCanPlayerSpawn = true;
			const auto PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0));
			RestartPlayer(PlayerController);
		};

	FTimerHandle SpawnPlayerTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(SpawnPlayerTimerHandle, SetPlayerSpawnToTrue, 2.0f, false);
}

bool ACFR_MainGameMode::GetCanPlayerSpawn() const
{
	return bCanPlayerSpawn;
}

void ACFR_MainGameMode::PlayerWins()
{
	const auto World = GetWorld();
	check(PlayerWinsWidget != nullptr);

	if (const auto PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		PlayerController->SetInputMode(FInputModeUIOnly());

		const auto Widget = Cast<UCommonActivatableWidget>(UUserWidget::CreateWidgetInstance(*World, PlayerWinsWidget, FName("PlayerWinsWidget")));
		check(Widget);

		Widget->AddToViewport();
		Widget->ActivateWidget();
		return;
	}

	// At the moment, we should never reach here.
	checkNoEntry();
}

void ACFR_MainGameMode::PlayerLoses()
{
	const auto World = GetWorld();
	check(PlayerLosesWidget != nullptr);

	if (const auto PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		PlayerController->SetInputMode(FInputModeUIOnly());

		const auto Widget = Cast<UCommonActivatableWidget>(UUserWidget::CreateWidgetInstance(*World, PlayerLosesWidget, FName("PlayerLosesWidget")));
		check(Widget);

		Widget->AddToViewport();
		Widget->ActivateWidget();
		return;
	}

	// At the moment, we should never reach here.
	checkNoEntry();
}
