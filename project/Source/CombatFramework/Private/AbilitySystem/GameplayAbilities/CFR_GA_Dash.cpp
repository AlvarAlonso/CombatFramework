// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/GameplayAbilities/CFR_GA_Dash.h"
#include "Characters/CFR_CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

bool UCFR_GA_Dash::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	if (auto character = Cast<ACFR_CharacterBase>(ActorInfo->AvatarActor))
	{
		FGameplayTagContainer TagContainer;
		TagContainer.AddTag(FCFR_GameplayTags::Get().Ability_Dash_Cooldown);
		auto bBlockedByTags = character->HasAnyMatchingGameplayTags(TagContainer);
		auto movementComponent = character->GetCharacterMovement();

		return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags) && character && movementComponent && !bBlockedByTags;
	}

	return false;
}

void UCFR_GA_Dash::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{			
		constexpr bool bReplicateEndAbility = true;
		constexpr bool bWasCancelled = true;
		EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	}

	auto character = Cast<ACFR_CharacterBase>(ActorInfo->AvatarActor);

	if (!character)
	{
		UE_LOG(LogTemp, Warning, TEXT("UCFR_GA_Dash::ActivateAbility - Character is null."));
		EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
		return;
	}

	auto movementComponent = character->GetCharacterMovement();

	if (!movementComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("UCFR_GA_Dash::ActivateAbility - MovementComponent is null."));
		EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
		return;
	}

	if (movementComponent->IsFalling())
	{
		character->AddGameplayTag(FCFR_GameplayTags::Get().Status_AirDashed);
		character->StopJumping();
		movementComponent->GravityScale = 0.0f;
	}

	character->LaunchCharacter(character->GetActorForwardVector() * DashForce, true, true);
}

void UCFR_GA_Dash::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	auto character = Cast<ACFR_CharacterBase>(ActorInfo->AvatarActor);
	auto movementComponent = character->GetCharacterMovement();
	if (character && movementComponent)
	{
		movementComponent->MaxAcceleration = character->GetDefaultMaxAcceleration();
		movementComponent->GravityScale = character->GetDefaultGravityScale();

		if (movementComponent->IsFalling())
		{
			character->LaunchCharacter(FVector(0.0f, 0.0f, -0.1f), true, true);
		}
	}
}
