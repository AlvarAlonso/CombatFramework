// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/CFR_GA_Jump.h"
#include "Characters/CFR_CharacterBase.h"

#include "AbilitySystemComponent.h"

bool UCFR_GA_Jump::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
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
			FGameplayTagContainer CancellingTags = FGameplayTagContainer(FGameplayTag::RequestGameplayTag("GameplayAbility.Montage"));
			OwnerASC->CancelAbilities(&CancellingTags, nullptr, nullptr);
			
			ACFR_CharacterBase* AvatarCharacter = Cast<ACFR_CharacterBase>(AvatarActor);
			if (IsValid(AvatarCharacter))
			{
				AvatarCharacter->JumpCurrentCount == 0 ?
					OwnerASC->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag("GameplayEvent.Jumped")) :
					OwnerASC->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag("GameplayEvent.DoubleJumped"));
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
			if (AvatarCharacter->JumpCurrentCount <= 1)
			{
				OwnerASC->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("GameplayEvent.Jumped"));
			}
			else
			{
				OwnerASC->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("GameplayEvent.DoubleJumped"));
			}

			AvatarCharacter->StopJumping();
		}
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
