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
	UE_LOG(LogTemp, Warning, TEXT("Activate Jump"));
	AActor* OwnerActor = GetOwningActorFromActorInfo();
	ACFR_CharacterBase* OwnerCharacter = Cast<ACFR_CharacterBase>(OwnerActor);
	
	const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OwnerActor);
	if (AbilitySystemInterface != nullptr)
	{
		UAbilitySystemComponent* OwnerASC = AbilitySystemInterface->GetAbilitySystemComponent();
		FGameplayTagContainer CancellingTags = FGameplayTagContainer(FGameplayTag::RequestGameplayTag("GameplayAbility.Montage"));
		OwnerASC->CancelAbilities(&CancellingTags, nullptr, nullptr);
		UE_LOG(LogTemp, Warning, TEXT("HIHI"));
	}

	if (IsValid(OwnerCharacter))
	{
		OwnerCharacter->Jump();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Jump Ability was used with a non ACFR_Character AActor!"));
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}

void UCFR_GA_Jump::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	UE_LOG(LogTemp, Warning, TEXT("End Jump"));
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
