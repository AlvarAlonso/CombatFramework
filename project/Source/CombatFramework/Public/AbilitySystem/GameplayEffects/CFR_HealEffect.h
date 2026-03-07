#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"

#include "CFR_HealEffect.generated.h"

UCLASS()
class UCFR_HealEffect : public UGameplayEffect
{
    GENERATED_BODY()

public:
    UCFR_HealEffect();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float HealAmount = 100.0f;
};
