#pragma once

#include "Components/WidgetComponent.h"

#include "CFR_DamagePopupComponent.generated.h"

class UCanvasPanel;

class UCFR_DamagePopupWidget;

UCLASS()
class COMBATFRAMEWORK_API UCFR_DamagePopupComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UCFR_DamagePopupComponent();

	void BeginPlay() override;

	UFUNCTION()
	void AddDamagePopupWidget(float InDamageValue);

	TObjectPtr<UCFR_DamagePopupWidget> GetDamagePopupWidget();
	void ReleaseDamagePopupWidget(TObjectPtr<UCFR_DamagePopupWidget> InWidget);

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCFR_DamagePopupWidget> DamagePopupWidgetClass;

	TSubclassOf<UUserWidget> CanvasWidgetClass;
	TObjectPtr<UUserWidget> CanvasWidget{ nullptr };

	UPROPERTY()
	TArray<TObjectPtr<UCFR_DamagePopupWidget>> DamagePopupPool;
	uint32_t InitialPoolSize{ 5 };
};
