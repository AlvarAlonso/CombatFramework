#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "CFR_IHUDWidget.generated.h"

class UProgressBar;
class UTextBlock;

UCLASS()
class COMBATFRAMEWORK_API UCFR_IHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetHealth(float NormalizedHealth);

	UFUNCTION(BlueprintCallable)
	void SetPower(float Power);

	UFUNCTION(BlueprintCallable)
	void SetScore(int32 Score);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* PowerBar;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ScoreText;
};
