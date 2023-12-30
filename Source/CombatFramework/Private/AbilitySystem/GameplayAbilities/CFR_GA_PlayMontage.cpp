// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h"

#include "AbilitySystem/AbilityTasks/CFR_PlayMontageAndWaitForEvent.h"

bool UCFR_GA_PlayMontage::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
}

void UCFR_GA_PlayMontage::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	PlayMontageAndWaitForEventTask = UCFR_PlayMontageAndWaitForEvent::PlayMontageAndWaitForEvent(
		this, NAME_None, MontageToPlay, EventTagContainer, PlayRate, StartSectionName, true);
	PlayMontageAndWaitForEventTask->OnInterrupted.AddDynamic(this, &UCFR_GA_PlayMontage::OnMontageFinished);
	PlayMontageAndWaitForEventTask->OnBlendOut.AddDynamic(this, &UCFR_GA_PlayMontage::OnMontageFinished);
	PlayMontageAndWaitForEventTask->OnCancelled.AddDynamic(this, &UCFR_GA_PlayMontage::OnMontageFinished);
	PlayMontageAndWaitForEventTask->OnCompleted.AddDynamic(this, &UCFR_GA_PlayMontage::OnMontageFinished);
	PlayMontageAndWaitForEventTask->OnEventReceived.AddDynamic(this, &UCFR_GA_PlayMontage::OnReceivedEvent);
	PlayMontageAndWaitForEventTask->ReadyForActivation();
}

void UCFR_GA_PlayMontage::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UCFR_GA_PlayMontage::OnMontageFinished(FGameplayTag EventTag, FGameplayEventData EventData)
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, false, false);
}

void UCFR_GA_PlayMontage::OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData)
{
	BP_OnReceivedEvent(EventTag, EventData);
}
