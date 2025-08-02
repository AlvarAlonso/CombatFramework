// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/CFR_PlayerState.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_AttributeSet.h"

ACFR_PlayerState::ACFR_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCFR_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UCFR_AttributeSet>("AttributeSet");

	CharacterLevel = 1.0f;

	SetNetUpdateFrequency(100.0f);
}

UAbilitySystemComponent* ACFR_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
