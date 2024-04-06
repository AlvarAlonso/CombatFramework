// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CFR_AICharacter.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_AttributeSet.h"

ACFR_AICharacter::ACFR_AICharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCFR_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UCFR_AttributeSet>("AttributeSet");
}

void ACFR_AICharacter::BeginPlay()
{
	Super::BeginPlay();
	InitAbilitySystemInfo();
}

void ACFR_AICharacter::InitAbilitySystemInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
