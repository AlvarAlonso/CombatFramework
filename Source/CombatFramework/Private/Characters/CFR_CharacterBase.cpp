// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CFR_CharacterBase.h"

#include "AbilitySystemComponent.h"

ACFR_CharacterBase::ACFR_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* ACFR_CharacterBase::GetAbilitySystemComponent() const 
{
	return AbilitySystemComponent;
}

void ACFR_CharacterBase::InitAbilitySystemInfo()
{
}

void ACFR_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

