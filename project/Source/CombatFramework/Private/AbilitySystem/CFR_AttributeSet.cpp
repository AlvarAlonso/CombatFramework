// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/CFR_AttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

#include "Characters/CFR_CharacterBase.h"

UCFR_AttributeSet::UCFR_AttributeSet()
{
	InitCurrentHealth(100.0f);
	InitMaxHealth(100.0f);
	InitCurrentMana(100.0f);
	InitMaxMana(100.0f);
	InitStrength(10.0f);
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
	if (Attribute == GetDamageAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, FLT_MAX);
	}
}

void UCFR_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	const UAbilitySystemComponent* SourceASC = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();

	UE_LOG(LogTemp, Warning, TEXT("PostGameplayEffectExecute"));


	if (Data.EvaluatedData.Attribute == GetDamageAttribute() &&
		SourceASC && SourceASC->AbilityActorInfo.IsValid() && SourceASC->AbilityActorInfo->AvatarActor.IsValid() &&
		Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("SetCurrentHealth"));

		const float OldHealth = GetCurrentHealth();
		SetCurrentHealth(FMath::Clamp(OldHealth - GetDamage(), 0.0f, GetMaxHealth()));

		SetDamage(0.0f);
	}
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
