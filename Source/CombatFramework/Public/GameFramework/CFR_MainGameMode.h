#pragma once

#include "CoreMinimal.h"

#include "GameFramework/CFR_IGameMode.h"

#include "CFR_MainGameMode.generated.h"

class UUserWidget;

UCLASS()
class COMBATFRAMEWORK_API ACFR_MainGameMode : public ACFR_IGameMode
{
    GENERATED_BODY()

public:
    void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
    void StartPlay() override;
    bool GetCanPlayerSpawn() const;

    void PlayerWins() override;
    void PlayerLoses() override;

private:
    bool bCanPlayerSpawn = false;
};
