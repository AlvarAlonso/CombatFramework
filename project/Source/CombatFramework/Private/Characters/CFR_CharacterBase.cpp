// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CFR_CharacterBase.h"
#include "AbilitySystem/CFR_EventDataPayloads.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"

#include "AbilitySystem/CFR_AttributeSet.h"

ACFR_CharacterBase::ACFR_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	CharacterLevel = 1.0f;
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

float ACFR_CharacterBase::GetCharacterLevel() const
{
	return CharacterLevel;
}

void ACFR_CharacterBase::PushCharacter(AActor* ActorInstigator, const UCFR_LaunchEventDataAsset* LaunchPayload)
{
	if (CanBeLaunched(ActorInstigator, LaunchPayload) == false) return;

	// Decompose payload
	const FVector ActorLocation = GetActorLocation();
	float VerticalForce = LaunchPayload->LaunchVerticalForce;
	const float HorizontalForce = LaunchPayload->LaunchHorizontalForce;
	const bool bOverrideXY = LaunchPayload->bOverrideHorizontal;
	const bool bOverrideZ = LaunchPayload->bOverrideVertical;

	FVector LaunchHorizontalDirection;

	// Get force horizontal direction depending on the instigator origin or if the actor applies a force to itself
	if (ActorInstigator && LaunchPayload->bInstigatorOrigin)
	{
		const FVector ForceOrigin = ActorInstigator->GetActorLocation();
		LaunchHorizontalDirection = ActorLocation - ForceOrigin;
		LaunchHorizontalDirection.Z = 0.0f;
		LaunchHorizontalDirection.Normalize();
	}
	else
	{
		LaunchHorizontalDirection = GetActorForwardVector();
	}

	if (bCanBeKnockup == false)
	{
		VerticalForce = 0.0f;
	}

	FVector LaunchForce = LaunchHorizontalDirection * HorizontalForce + FVector(0.0f, 0.0f, 1.0f) * VerticalForce;

	LaunchCharacter(LaunchForce, bOverrideXY, bOverrideZ);

	if (LaunchPayload->bKnockUp == true && bCanBeKnockup == true)
	{
		AbilitySystemComponent->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag(FName("Status.KnockedUp")));
	}
	// TODO: If the character is in air maybe it is mandatory to apply a minimum Z force due to an Unreal bug
}

void ACFR_CharacterBase::Falling()
{
	AbilitySystemComponent->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag("Status.OnAir"));
}

void ACFR_CharacterBase::Landed(const FHitResult& Hit)
{
	AbilitySystemComponent->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("Status.OnAir"));
}

bool ACFR_CharacterBase::CanBeLaunched(AActor* ActorInstigator, const UCFR_LaunchEventDataAsset* LaunchPayload)
{
	return true;
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
