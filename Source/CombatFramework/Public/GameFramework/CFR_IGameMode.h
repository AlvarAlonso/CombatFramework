#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "CFR_IGameMode.generated.h"

class UUserWidget;

UCLASS(Abstract)
class COMBATFRAMEWORK_API ACFR_IGameMode : public AGameMode
{
    GENERATED_BODY()

public:
    void StartPlay() override;

    virtual void PauseGame();

    // Must be overriden by child class.
    virtual void PlayerWins() PURE_VIRTUAL(ACFR_IGameMode::PlayerWins, );
    virtual void PlayerLoses() PURE_VIRTUAL(ACFR_IGameMode::PlayerLoses, );

protected:
    UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
    TSubclassOf<UUserWidget> InGamePauseMenuWidget = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
    TSubclassOf<UUserWidget> PlayerWinsWidget = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = WidgetMenus)
    TSubclassOf<UUserWidget> PlayerLosesWidget = nullptr;
};
