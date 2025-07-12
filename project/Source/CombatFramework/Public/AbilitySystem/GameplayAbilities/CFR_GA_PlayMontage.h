// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/CFR_GameplayAbility.h"
#include "AbilitySystem/CFR_EventDataPayloads.h"
#include "CFR_GA_PlayMontage.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_GA_PlayMontage : public UCFR_GameplayAbility
{
	GENERATED_BODY()
	
protected:
	bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const;

	void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	UFUNCTION()
	virtual void OnMontageInterrupted(FGameplayTag EventTag, FGameplayEventData EventData);

	UFUNCTION()
	virtual void OnMontageBlendOut(FGameplayTag EventTag, FGameplayEventData EventData);

	UFUNCTION()
	virtual void OnMontageCancelled(FGameplayTag EventTag, FGameplayEventData EventData);

	UFUNCTION()
	virtual void OnMontageCompleted(FGameplayTag EventTag, FGameplayEventData EventData);

	virtual void HandleMontageFinished(FGameplayTag EventTag, FGameplayEventData EventData);

	UFUNCTION()
	virtual void OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData);

protected:
	UPROPERTY()
	class UCFR_PlayMontageAndWaitForEvent* PlayMontageAndWaitForEventTask = nullptr;

	// Montage ability will play.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimMontage* MontageToPlay;

	// Section of the montage in case we do not want to play from the beginning.
	UPROPERTY(EditAnywhere)
	FName StartSectionName;

	UPROPERTY(EditAnywhere)
	float PlayRate = 1.0f;

	// The Tag for the montage to wait for.
	UPROPERTY(EditAnywhere)
	FGameplayTagContainer EventTagContainer;

	// Effects to apply to target actor when the events are received.
	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FCFR_EffectContextContainer> EffectsToApply;
};
