#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"

#include "CFR_IPauseMenuWidget.generated.h"

UCLASS()
class COMBATFRAMEWORK_API UCFR_IPauseMenuWidget : public UCommonActivatableWidget
{
    GENERATED_BODY()

public:
    UWidget* NativeGetDesiredFocusTarget() const override;

    UFUNCTION(BlueprintCallable)
    virtual void Resume();

    UFUNCTION(BlueprintCallable)
    virtual void ReturnToMainMenu();

    UFUNCTION(BlueprintCallable)
    virtual void ExitGame();
};
