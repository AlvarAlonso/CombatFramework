#include "Widgets/CFR_ISkipCutsceneWidget.h"

#include "Kismet/GameplayStatics.h"

#include "GameFramework/CFR_IGameMode.h"

void UCFR_ISkipCutsceneWidget::BeginDestroy()
{
	if (HideTimerHandle.IsValid())
		HideTimerHandle.Invalidate();

	Super::BeginDestroy();
}

void UCFR_ISkipCutsceneWidget::NativeConstruct()
{
	Super::NativeConstruct();

	auto removeFromParent = [this]() -> void
		{
			const auto gameMode = Cast<ACFR_IGameMode>(UGameplayStatics::GetGameMode(this));
			check(gameMode);

			gameMode->bSkipCutsceneWidgetShown = false;

			RemoveFromParent();
		};

	GetWorld()->GetTimerManager().SetTimer(HideTimerHandle, removeFromParent, FadeAwayTime, false);
}
