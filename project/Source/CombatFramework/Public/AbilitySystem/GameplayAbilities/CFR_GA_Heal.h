#pragma once

#include "AbilitySystem/CFR_GameplayAbility.h"

#include "CFR_GA_Heal.generated.h"

UCLASS()
class UCFR_GA_Heal : public UCFR_GameplayAbility
{
    GENERATED_BODY()

    public:
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
