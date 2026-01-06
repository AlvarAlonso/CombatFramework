#pragma once

#include "Blueprint/UserWidget.h"

#include "CFR_ISkipCutsceneWidget.generated.h"

UCLASS()
class COMBATFRAMEWORK_API UCFR_ISkipCutsceneWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// UCFR_ISkipCutsceneWidget
	void ResetTimer();

protected:
	// UObject interface
	virtual void BeginDestroy() override;

	// UUserWidget interface
	virtual void NativeConstruct() override;

private:
	void HideWidget();

	UPROPERTY(EditDefaultsOnly)
	float FadeAwayTime = 1.0f;

	FTimerHandle HideTimerHandle;
};
