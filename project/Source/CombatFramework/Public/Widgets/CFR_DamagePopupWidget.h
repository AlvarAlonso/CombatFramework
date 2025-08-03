#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

#include "CFR_DamagePopupWidget.generated.h"

class UWidgetComponent;

UCLASS()
class COMBATFRAMEWORK_API UCFR_DamagePopupWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetDamageValue(float InDamageValue);

	UPROPERTY(meta = (BindWidgetAnim), Transient, BlueprintReadWrite)
	TObjectPtr<UWidgetAnimation> Popup{ nullptr };

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> DamageTextBlock{ nullptr };
};
