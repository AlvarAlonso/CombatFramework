#include "Widgets/CFR_IHUDWidget.h"

#include "Components/HorizontalBox.h"
#include "Components/ProgressBar.h"
#include "Blueprint/UserWidget.h"
#include "GameplayEffectTypes.h"

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

void UCFR_IHUDWidget::UpdateManaStacks(const FOnAttributeChangeData& Data)
{
	auto children = StackContainer->GetAllChildren();

	int32 i = 0;
	for (auto child : children)
	{
		i < Data.NewValue ? child->SetVisibility(ESlateVisibility::HitTestInvisible) : child->SetVisibility(ESlateVisibility::Hidden);
		++i;
	}
}
