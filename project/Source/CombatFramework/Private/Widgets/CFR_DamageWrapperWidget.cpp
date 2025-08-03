#include "Widgets/CFR_DamageWrapperWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

#include "Widgets/CFR_DamagePopupWidget.h"

void UCFR_DamageWrapperWidget::AddDamagePopupWidget(float InDamageValue)
{
	if (!DamageCanvas || !DamagePopupWidgetClass)
		return;

	auto damagePopupWidget = CreateWidget<UCFR_DamagePopupWidget>(this, DamagePopupWidgetClass);
	if (!damagePopupWidget)
		return;

	if (auto slot = Cast<UCanvasPanelSlot>(DamageCanvas->AddChild(damagePopupWidget)))
	{
		slot->SetAnchors(FAnchors(0.5f, 0.5f));
	}

	damagePopupWidget->SetDamageValue(InDamageValue);

	const auto animationDuration = damagePopupWidget->Popup->GetEndTime();

	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, [this]() {
		this->RemoveFromParent();
		}, animationDuration, false);
}
