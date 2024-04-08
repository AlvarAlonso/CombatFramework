#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "CFR_IPauseMenuWidget.generated.h"

UCLASS()
class COMBATFRAMEWORK_API UCFR_IPauseMenuWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    virtual void Resume();

    UFUNCTION(BlueprintCallable)
    virtual void ReturnToMainMenu();

    UFUNCTION(BlueprintCallable)
    virtual void ExitGame();
};
