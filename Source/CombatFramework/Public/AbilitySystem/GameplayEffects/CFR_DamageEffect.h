#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"

#include "CFR_DamageEffect.generated.h"

UCLASS()
class UCFR_DamageEffect : public UGameplayEffect
{
    GENERATED_BODY()

public:
    UCFR_DamageEffect();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Damage = 1.0f;
};
