#include "Widgets/CFR_IHUDWidget.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UCFR_IHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UCFR_IHUDWidget::SetHealth(float NormalizedHealth)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(NormalizedHealth);
	}
}

void UCFR_IHUDWidget::SetPower(float Power)
{
	if (PowerBar)
	{
		PowerBar->SetPercent(Power);
	}
}

void UCFR_IHUDWidget::SetScore(int32 Score)
{
	if (ScoreText)
	{
		ScoreText->SetText(FText::AsNumber(Score));
	}
}
