// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/CFR_GA_CastProjectileAbility.h"

void UCFR_GA_CastProjectileAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
}

void UCFR_GA_CastProjectileAbility::OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData)
{
}

void UCFR_GA_CastProjectileAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
}

bool UCFR_ClusteredSpawn::Spawn_Implementation()
{
    return false;
}

bool UCFR_BurstSpawn::Spawn_Implementation()
{
    return false;
}
