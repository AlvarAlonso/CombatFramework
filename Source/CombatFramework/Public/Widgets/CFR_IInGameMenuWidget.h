#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"

#include "CFR_IInGameMenuWidget.generated.h"

UCLASS()
class COMBATFRAMEWORK_API UCFR_IInGameMenuWidget : public UCommonActivatableWidget
{
    GENERATED_BODY()

public:
    UWidget* NativeGetDesiredFocusTarget() const override;

    UFUNCTION(BlueprintCallable)
    virtual void ReturnToMainMenu();

    UFUNCTION(BlueprintCallable)
    virtual void ExitGame();
};
