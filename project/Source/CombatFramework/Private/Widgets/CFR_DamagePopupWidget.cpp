#include "Widgets/CFR_DamagePopupWidget.h"

void UCFR_DamagePopupWidget::SetDamageValue(float InDamageValue)
{
	DamageTextBlock->SetText(FText::AsNumber(InDamageValue));
}
