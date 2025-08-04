#include "Components/CFR_DamagePopupComponent.h"

#include "Animation/WidgetAnimation.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Widgets/CFR_DamagePopupWidget.h"

UCFR_DamagePopupComponent::UCFR_DamagePopupComponent() {
	ConstructorHelpers::FClassFinder<UUserWidget> canvasFinder(TEXT("/Game/CombatFrameworkContent/UI/Widgets/InGame/WBP_EmptyCanvas"));
	check(canvasFinder.Succeeded());

	CanvasWidgetClass = canvasFinder.Class;
};

void UCFR_DamagePopupComponent::BeginPlay()
{
	Super::BeginPlay();

	CanvasWidget = CreateWidget(GetWorld(), CanvasWidgetClass);
	check(CanvasWidget);

	SetWidget(CanvasWidget);

	DamagePopupPool.Reserve(InitialPoolSize);

	for (uint32_t index = 0; index < InitialPoolSize; ++index)
	{
		auto widget = Cast<UCFR_DamagePopupWidget>(CreateWidget(CanvasWidget, DamagePopupWidgetClass));

		if (!widget)
			continue;

		widget->SetVisibility(ESlateVisibility::Collapsed);
		DamagePopupPool.Add(MoveTemp(widget));
	}
}

void UCFR_DamagePopupComponent::AddDamagePopupWidget(float InDamageValue)
{
	auto canvasPanel = Cast<UCanvasPanel>(CanvasWidget->GetRootWidget());
	check(canvasPanel);

	auto damageWidget = GetDamagePopupWidget();
	damageWidget->SetVisibility(ESlateVisibility::Visible);
	damageWidget->SetDamageValue(InDamageValue);

	if (auto slot = Cast<UCanvasPanelSlot>(canvasPanel->AddChild(damageWidget)))
	{
		slot->SetAnchors(FAnchors(0.5f, 0.5f));
	}

	const auto animationDuration = damageWidget->Popup->GetEndTime();

	FTimerHandle damagePopupTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(damagePopupTimerHandle, [this, weakWidget = TWeakObjectPtr<UCFR_DamagePopupWidget>(damageWidget)]() {
		if (weakWidget.IsValid())
		{
			weakWidget->RemoveFromParent();
			this->ReleaseDamagePopupWidget(weakWidget.Get());
		}
		}, animationDuration, false);
}

TObjectPtr<UCFR_DamagePopupWidget> UCFR_DamagePopupComponent::GetDamagePopupWidget()
{
	if (DamagePopupPool.IsValidIndex(0))
	{
		auto widget = DamagePopupPool[0];
		DamagePopupPool.RemoveAtSwap(0, EAllowShrinking::No);

		return widget;
	}

	return Cast<UCFR_DamagePopupWidget>(CreateWidget(CanvasWidget, DamagePopupWidgetClass));
}

void UCFR_DamagePopupComponent::ReleaseDamagePopupWidget(TObjectPtr<UCFR_DamagePopupWidget> InWidget)
{
	check(InWidget);

	DamagePopupPool.Add(MoveTemp(InWidget));
}
