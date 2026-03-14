#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "CFR_IHUDWidget.generated.h"

class UHorizontalBox;
class UProgressBar;

struct FOnAttributeChangeData;

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

	void UpdateManaStacks(const FOnAttributeChangeData& Data);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* PowerBar;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UHorizontalBox* StackContainer;
};
