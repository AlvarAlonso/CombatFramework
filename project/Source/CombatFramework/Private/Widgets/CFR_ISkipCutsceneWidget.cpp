#include "Widgets/CFR_ISkipCutsceneWidget.h"

#include "Kismet/GameplayStatics.h"

void UCFR_ISkipCutsceneWidget::ResetTimer()
{
	if (!HideTimerHandle.IsValid())
	{
		return;
	}

	auto& timerManager = GetWorld()->GetTimerManager();

	timerManager.ClearTimer(HideTimerHandle);
	timerManager.SetTimer(HideTimerHandle, this, &UCFR_ISkipCutsceneWidget::HideWidget, FadeAwayTime, false);
}

void UCFR_ISkipCutsceneWidget::BeginDestroy()
{
	if (HideTimerHandle.IsValid())
		HideTimerHandle.Invalidate();

	Super::BeginDestroy();
}

void UCFR_ISkipCutsceneWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GetWorld()->GetTimerManager().SetTimer(HideTimerHandle, this, &UCFR_ISkipCutsceneWidget::HideWidget, FadeAwayTime, false);
}

void UCFR_ISkipCutsceneWidget::HideWidget()
{
	SetVisibility(ESlateVisibility::Hidden);
}
