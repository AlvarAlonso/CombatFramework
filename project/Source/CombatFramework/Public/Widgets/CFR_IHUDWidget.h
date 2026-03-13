#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "CFR_IHUDWidget.generated.h"

class UProgressBar;

UCLASS()
class COMBATFRAMEWORK_API UCFR_IHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetHealth(float NormalizedHealth);

	UFUNCTION(BlueprintCallable)
	void SetMana(float NormalizedMana);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* PowerBar;
};
