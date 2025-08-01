// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/CFR_GA_Jump.h"
#include "AbilitySystem/CFR_GameplayTags.h"
#include "Characters/CFR_CharacterBase.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

UCFR_GA_Jump::UCFR_GA_Jump()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

bool UCFR_GA_Jump::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	const bool bCanActivateAbility = Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);

	bool bIsFalling = false;
	int JumpCount = 0;
	const auto Character = Cast<ACFR_CharacterBase>(GetAvatarActorFromActorInfo());
	if (Character)
	{
		const auto CharacterMovementComponent = Character->GetCharacterMovement();
		if (CharacterMovementComponent)
		{
			bIsFalling = CharacterMovementComponent->IsFalling() && !bIsFalling;
		}
		JumpCount = Character->JumpCurrentCount;
	}

	return bCanActivateAbility && (!bIsFalling || (bIsFalling && JumpCount == 1));
}

void UCFR_GA_Jump::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	AActor* AvatarActor = GetAvatarActorFromActorInfo();
	
	// TODO: Does not cancell abilities if cancelled tags are set in Blueprint. Look at why does this happen.
	const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(AvatarActor);
	if (AbilitySystemInterface != nullptr)
	{
		UAbilitySystemComponent* OwnerASC = AbilitySystemInterface->GetAbilitySystemComponent();
		if (OwnerASC)
		{
			FGameplayTagContainer CancellingTags = FGameplayTagContainer(FCFR_GameplayTags::Get().Ability_Fullbody);
			OwnerASC->CancelAbilities(&CancellingTags, nullptr, nullptr);
			
			ACFR_CharacterBase* AvatarCharacter = Cast<ACFR_CharacterBase>(AvatarActor);
			if (IsValid(AvatarCharacter))
			{
				AvatarCharacter->JumpCurrentCount == 0 ?
					OwnerASC->AddLooseGameplayTag(FCFR_GameplayTags::Get().GameplayEvent_Jumped) :
					OwnerASC->AddLooseGameplayTag(FCFR_GameplayTags::Get().GameplayEvent_DoubleJumped);
				UE_LOG(LogTemp, Warning, TEXT("Activate Jump"));
				AvatarCharacter->Jump();
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Jump Ability was used with a non ACFR_Character AActor!"));
			}
		}
	}
}

void UCFR_GA_Jump::InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	if (ActorInfo != nullptr && ActorInfo->AvatarActor != nullptr)
	{
		CancelAbility(Handle, ActorInfo, ActivationInfo, true);
	}
}

void UCFR_GA_Jump::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	UE_LOG(LogTemp, Warning, TEXT("End Jump"));
	AActor* AvatarActor = GetAvatarActorFromActorInfo();

	const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(AvatarActor);
	if (AbilitySystemInterface != nullptr)
	{
		UAbilitySystemComponent* OwnerASC = AbilitySystemInterface->GetAbilitySystemComponent();
		ACFR_CharacterBase* AvatarCharacter = Cast<ACFR_CharacterBase>(AvatarActor);
		if (OwnerASC && AvatarCharacter)
		{
			OwnerASC->RemoveLooseGameplayTag(FCFR_GameplayTags::Get().GameplayEvent_Jumped);
			OwnerASC->RemoveLooseGameplayTag(FCFR_GameplayTags::Get().GameplayEvent_DoubleJumped);
			AvatarCharacter->StopJumping();
		}
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
