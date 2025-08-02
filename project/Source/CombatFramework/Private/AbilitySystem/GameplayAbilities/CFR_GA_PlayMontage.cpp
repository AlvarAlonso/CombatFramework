// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h"
#include "Characters/CFR_CharacterBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AbilityTasks/CFR_PlayMontageAndWaitForEvent.h"
#include "AbilitySystem/CFR_AbilitySystemGlobals.h"

bool UCFR_GA_PlayMontage::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
}

void UCFR_GA_PlayMontage::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	PlayMontageAndWaitForEventTask = UCFR_PlayMontageAndWaitForEvent::PlayMontageAndWaitForEvent(
		this, NAME_None, MontageToPlay, EventTagContainer, PlayRate, StartSectionName, true);
	PlayMontageAndWaitForEventTask->OnInterrupted.AddDynamic(this, &UCFR_GA_PlayMontage::OnMontageInterrupted);
	PlayMontageAndWaitForEventTask->OnBlendOut.AddDynamic(this, &UCFR_GA_PlayMontage::OnMontageBlendOut);
	PlayMontageAndWaitForEventTask->OnCancelled.AddDynamic(this, &UCFR_GA_PlayMontage::OnMontageCancelled);
	PlayMontageAndWaitForEventTask->OnCompleted.AddDynamic(this, &UCFR_GA_PlayMontage::OnMontageCompleted);
	PlayMontageAndWaitForEventTask->OnEventReceived.AddDynamic(this, &UCFR_GA_PlayMontage::OnReceivedEvent);
	PlayMontageAndWaitForEventTask->ReadyForActivation();
}

void UCFR_GA_PlayMontage::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	if (bWasCancelled)
	{
		UE_LOG(LogTemp, Warning, TEXT("WAS CANCELLED"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("WAS NOT CANCELLED"));
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UCFR_GA_PlayMontage::OnMontageInterrupted(FGameplayTag EventTag, FGameplayEventData EventData)
{
	HandleMontageFinished(EventTag, EventData);
}

void UCFR_GA_PlayMontage::OnMontageBlendOut(FGameplayTag EventTag, FGameplayEventData EventData)
{
	HandleMontageFinished(EventTag, EventData);
}

void UCFR_GA_PlayMontage::OnMontageCancelled(FGameplayTag EventTag, FGameplayEventData EventData)
{
	HandleMontageFinished(EventTag, EventData);
}

void UCFR_GA_PlayMontage::OnMontageCompleted(FGameplayTag EventTag, FGameplayEventData EventData)
{
	HandleMontageFinished(EventTag, EventData);
}

void UCFR_GA_PlayMontage::HandleMontageFinished(FGameplayTag EventTag, FGameplayEventData EventData)
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, false, false);
}

void UCFR_GA_PlayMontage::OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData)
{
	const auto* OwnerActor = GetOwningActorFromActorInfo();
	const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OwnerActor);
	if (AbilitySystemInterface != nullptr)
	{
		const auto* OwnerCharacter = Cast<ACFR_CharacterBase>(GetAvatarActorFromActorInfo());
		UAbilitySystemComponent* OwnerASC = AbilitySystemInterface->GetAbilitySystemComponent();
		const ACFR_CharacterBase* TargetCharacter = Cast<ACFR_CharacterBase>(EventData.Target);
		UAbilitySystemComponent* TargetASC = TargetCharacter ? TargetCharacter->GetAbilitySystemComponent() : nullptr;
		
		if (EffectsMap.Contains(EventTag) && IsValid(OwnerASC) && IsValid(TargetASC))
		{
			if (const auto EffectContexts = EffectsMap.Find(EventTag))
			{
				for (const auto& ContextContainer : EffectContexts->ContextsContainer)
				{
					TSubclassOf<UGameplayEffect> GameplayEffectToApply = ContextContainer.EffectToApply;
					if (GameplayEffectToApply.Get() != nullptr)
					{
						FGameplayEffectSpecHandle GameplayEffectSpecHandle = MakeOutgoingGameplayEffectSpec(GameplayEffectToApply, OwnerCharacter->GetCharacterLevel());

						FGameplayEffectContextHandle EffectContextHandle = MakeEffectContext(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo());
						FCFR_GameplayEffectContext* CFREffectContext = static_cast<FCFR_GameplayEffectContext*>(EffectContextHandle.Get());

						CFREffectContext->AbilitySourceData = IsValid(ContextContainer.Payload) ? MakeWeakObjectPtr<const UObject>(ContextContainer.Payload) : nullptr;
						UE_LOG(LogTemp, Warning, TEXT("Assign payload!"));

						FGameplayEffectSpec* GESpec = GameplayEffectSpecHandle.Data.Get();
						GESpec->SetContext(EffectContextHandle);
						UE_LOG(LogTemp, Warning, TEXT("Set Context"));

						OwnerASC->ApplyGameplayEffectSpecToTarget(*GESpec, TargetASC);
						UE_LOG(LogTemp, Warning, TEXT("ApplyGameplayEffectSpecToTarget"));
					}
					else
					{
						UE_LOG(LogTemp, Error, TEXT("EffectToApply was nullptr!"));
					}
				}
			}
		}
		
		BP_OnReceivedEvent(EventTag, EventData);
	}
}
