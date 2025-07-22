#pragma once

#include "GameFramework/CheatManager.h"
#include "CFR_CheatManager.generated.h"

UCLASS()
class COMBATFRAMEWORK_API UCFR_CheatManager : public UCheatManager
{
    GENERATED_BODY()

public:

    UFUNCTION(exec)
    void KillPlayer();

    UFUNCTION(exec)
    void KillAllEnemies();
};
