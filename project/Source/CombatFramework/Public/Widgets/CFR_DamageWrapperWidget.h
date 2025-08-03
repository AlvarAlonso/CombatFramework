#pragma once

#include "Blueprint/UserWidget.h"

#include "CFR_DamageWrapperWidget.generated.h"

class UCanvasPanel;

class UCFR_DamagePopupWidget;

UCLASS()
class COMBATFRAMEWORK_API UCFR_DamageWrapperWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr< UCanvasPanel > DamageCanvas{ nullptr };

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCFR_DamagePopupWidget> DamagePopupWidgetClass;

	UFUNCTION(BlueprintCallable)
	void AddDamagePopupWidget(float InDamageValue);
};
