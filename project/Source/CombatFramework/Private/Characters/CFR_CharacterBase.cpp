// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CFR_CharacterBase.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"

#include "AbilitySystem/CFR_AttributeSet.h"

ACFR_CharacterBase::ACFR_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* ACFR_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

bool ACFR_CharacterBase::IsAlive() const
{
	return GetHealth() > 0.0f;
}

float ACFR_CharacterBase::GetHealth() const
{
	const auto AttrSet = GetAbilitySystemComponent()->GetSet<UCFR_AttributeSet>();
	check(AttrSet);

	return AttrSet->GetCurrentHealth();
}

float ACFR_CharacterBase::GetMaxHealth() const
{
	const auto AttrSet = GetAbilitySystemComponent()->GetSet<UCFR_AttributeSet>();
	check(AttrSet);

	return AttrSet->GetMaxHealth();
}

void ACFR_CharacterBase::Falling()
{
	AbilitySystemComponent->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag("Status.OnAir"));
}

void ACFR_CharacterBase::Landed(const FHitResult& Hit)
{
	AbilitySystemComponent->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("Status.OnAir"));
}

void ACFR_CharacterBase::HandleDeath()
{
	// TODO: Implement Handle death logic
}

void ACFR_CharacterBase::HandleHealthChanged(const FOnAttributeChangeData& InData)
{
	// TODO: Show damage or health received as a widget.

	if (!IsAlive())
	{
		HandleDeath();
	}

}
