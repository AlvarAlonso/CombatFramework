#include "Widgets/CFR_IHUDWidget.h"

#include "Components/ProgressBar.h"

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

void UCFR_IHUDWidget::SetMana(float NormalizedMana)
{
	if (PowerBar)
	{
		PowerBar->SetPercent(NormalizedMana);
	}
}
