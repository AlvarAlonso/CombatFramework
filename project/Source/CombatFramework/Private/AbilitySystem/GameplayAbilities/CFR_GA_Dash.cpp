// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/GameplayAbilities/CFR_GA_Dash.h"

#include "Components/CapsuleComponent.h"

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

	if (auto capsuleComponent = character->GetCapsuleComponent())
	{
		capsuleComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
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

	BrakingDecelerationWalking = movementComponent->BrakingDecelerationWalking;
	GroundFriction = movementComponent->GroundFriction;
	FrictionFactor = movementComponent->BrakingFrictionFactor;

	movementComponent->BrakingDecelerationWalking = 0.f;
	movementComponent->GroundFriction = 0.f;
	movementComponent->BrakingFrictionFactor = 0.f;

	character->LaunchCharacter(character->GetActorForwardVector() * DashForce, true, true);
}

void UCFR_GA_Dash::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (auto character = Cast<ACFR_CharacterBase>(ActorInfo->AvatarActor))
	{

		if (auto capsuleComponent = character->GetCapsuleComponent())
		{
			capsuleComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
		}

		auto movementComponent = character->GetCharacterMovement();

		if (!movementComponent)
		{
			return;
		}

		movementComponent->Velocity = FVector::ZeroVector;

		if (movementComponent->IsFalling())
		{
			movementComponent->GravityScale = character->GetDefaultGravityScale();
			character->LaunchCharacter(FVector(100.0f, 0.0f, -0.1f), true, true);
		}

		movementComponent->BrakingDecelerationWalking = BrakingDecelerationWalking;
		movementComponent->GroundFriction = GroundFriction;
		movementComponent->BrakingFrictionFactor = FrictionFactor;

	}
}
