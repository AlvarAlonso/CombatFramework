#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"

#include "CFR_IStartEndWaveWidget.generated.h"

UCLASS()
class COMBATFRAMEWORK_API UCFR_IStartEndWaveWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidgetAnim), Transient, BlueprintReadOnly, Category = "Widget")
	TObjectPtr<UWidgetAnimation> AnimationWidget{ nullptr };
};
