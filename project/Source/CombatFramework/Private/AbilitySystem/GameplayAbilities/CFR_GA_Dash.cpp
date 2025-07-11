// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/CFR_GA_Dash.h"
#include "Characters/CFR_CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

bool UCFR_GA_Dash::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	ACFR_CharacterBase* CharacterBase = Cast<ACFR_CharacterBase>(ActorInfo->AvatarActor);
	UCharacterMovementComponent* CharacterMovementComponent = CharacterBase->GetCharacterMovement();

	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags) && CharacterBase && CharacterMovementComponent;
}

void UCFR_GA_Dash::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	ACFR_CharacterBase* CharacterBase = Cast<ACFR_CharacterBase>(ActorInfo->AvatarActor);
	UCharacterMovementComponent* CharacterMovementComponent = CharacterBase->GetCharacterMovement();
	if (CharacterBase && CharacterMovementComponent)
	{
		// TODO: Maybe return to default values after dash ends. 
		// Default values should be stored somewhere accessible by CharacterBase.
		PreviousMaxAcceleration = CharacterMovementComponent->MaxAcceleration;
		PreviousGravityScale = CharacterMovementComponent->GravityScale;

		CharacterMovementComponent->MaxAcceleration = 99999999.0f;
		CharacterMovementComponent->GravityScale = 0.0f;

		if (CharacterMovementComponent->IsFalling())
		{
			// TODO: Ensure it can only air dash once. Probably can be done by tag.

			// Performs the dash.
			CharacterBase->StopJumping();
			// INVESTIGATE: Why the -0.1f?
			CharacterBase->LaunchCharacter(FVector(0.0f, 0.0f, -0.1f), false, true);
		}
	}
	else 
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
	}
}

void UCFR_GA_Dash::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	ACFR_CharacterBase* CharacterBase = Cast<ACFR_CharacterBase>(ActorInfo->AvatarActor);
	UCharacterMovementComponent* CharacterMovementComponent = CharacterBase->GetCharacterMovement();
	if (CharacterBase && CharacterMovementComponent)
	{
		CharacterMovementComponent->MaxAcceleration = PreviousMaxAcceleration;
		CharacterMovementComponent->GravityScale = PreviousGravityScale;

		if (CharacterMovementComponent->IsFalling())
		{
			CharacterBase->LaunchCharacter(FVector(0.0f, 0.0f, -0.1f), true, true);
		}
	}
}
