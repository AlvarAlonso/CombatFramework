// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CFR_HitboxesManagerComponent.h"
#include "Components/CFR_HitboxComponent.h"

UCFR_HitboxesManagerComponent::UCFR_HitboxesManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCFR_HitboxesManagerComponent::AddHitboxToMap(FGameplayTag IdentifierTag, UCFR_HitboxComponent* HitboxComponent)
{
	HitboxesMap.Add(IdentifierTag, HitboxComponent);
}

UCFR_HitboxComponent* UCFR_HitboxesManagerComponent::GetHitboxByTag(FGameplayTag IdentifierTag)
{
	UCFR_HitboxComponent* ComponentToReturn = nullptr;

	UCFR_HitboxComponent** FoundComponent = HitboxesMap.Find(IdentifierTag);
	if (FoundComponent)
	{
		ComponentToReturn = *FoundComponent;
	}

	return ComponentToReturn;
}
