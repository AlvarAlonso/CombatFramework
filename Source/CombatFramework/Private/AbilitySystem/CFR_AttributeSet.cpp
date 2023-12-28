// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CFR_AttributeSet.h"

#include "Net/UnrealNetwork.h"

UCFR_AttributeSet::UCFR_AttributeSet()
{
	InitCurrentHealth(100.0f);
	InitMaxHealth(100.0f);
	InitCurrentMana(100.0f);
	InitMaxMana(100.0f);
}

void UCFR_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION_NOTIFY(UCFR_AttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCFR_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCFR_AttributeSet, CurrentMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCFR_AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCFR_AttributeSet, Strength, COND_None, REPNOTIFY_Always);
}

void UCFR_AttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetCurrentHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	if (Attribute == GetCurrentManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxMana());
	}
	if (Attribute == GetStrengthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, FLT_MAX);
	}
}

void UCFR_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}

void UCFR_AttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData OldCurrentHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCFR_AttributeSet, CurrentHealth, OldCurrentHealth);
}

void UCFR_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCFR_AttributeSet, MaxHealth, OldMaxHealth);
}

void UCFR_AttributeSet::OnRep_CurrentMana(const FGameplayAttributeData OldCurrentMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCFR_AttributeSet, CurrentMana, OldCurrentMana);
}

void UCFR_AttributeSet::OnRep_MaxMana(const FGameplayAttributeData OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCFR_AttributeSet, MaxMana, OldMaxMana);
}

void UCFR_AttributeSet::OnRep_Strength(const FGameplayAttributeData OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCFR_AttributeSet, Strength, OldStrength);
}
