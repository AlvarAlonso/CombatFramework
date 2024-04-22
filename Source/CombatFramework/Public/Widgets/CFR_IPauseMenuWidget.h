#pragma once

#include "Widgets/CFR_IInGameMenuWidget.h"

#include "CFR_IPauseMenuWidget.generated.h"

UCLASS()
class COMBATFRAMEWORK_API UCFR_IPauseMenuWidget : public UCFR_IInGameMenuWidget
{
    GENERATED_BODY()

public:
    UWidget* NativeGetDesiredFocusTarget() const override;

    UFUNCTION(BlueprintCallable)
    virtual void Resume();
};
