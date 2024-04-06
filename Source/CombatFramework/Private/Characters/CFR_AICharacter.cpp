// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CFR_AICharacter.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_AttributeSet.h"

void ACFR_AICharacter::BeginPlay()
{
	Super::BeginPlay();
	InitAbilitySystemInfo();
}

void ACFR_AICharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
