#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "CFR_IGameMode.generated.h"

class UUserWidget;

UCLASS()
class COMBATFRAMEWORK_API ACFR_IGameMode : public AGameMode
{
    GENERATED_BODY()

public:
    virtual void PauseGame();

protected:
    UPROPERTY(EditDefaultsOnly, Category = Widgets)
    TSubclassOf<UUserWidget> InGamePauseMenuWidget = nullptr;
};
