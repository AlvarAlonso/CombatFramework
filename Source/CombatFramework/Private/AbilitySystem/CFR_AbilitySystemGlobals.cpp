// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CFR_AbilitySystemGlobals.h"

FGameplayEffectContext* UCFR_AbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new FCFR_GameplayEffectContext();
}

bool FCFR_GameplayEffectContext::NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess)
{
	return Super::NetSerialize(Ar, Map, bOutSuccess);
}
