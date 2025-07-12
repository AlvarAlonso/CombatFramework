// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayEffects/CFR_Execution_Launch.h"
#include "Characters/CFR_CharacterBase.h"
#include "AbilitySystem/CFR_EventDataPayloads.h"
#include "AbilitySystem/CFR_AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"

void UCFR_Execution_Launch::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	ACFR_CharacterBase* TargetCharacter = Cast<ACFR_CharacterBase>(ExecutionParams.GetTargetAbilitySystemComponent()->GetOwner());
	ACFR_CharacterBase* InstigatorCharacter = Cast<ACFR_CharacterBase>(ExecutionParams.GetSourceAbilitySystemComponent()->GetOwner());

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	// Get payload
	FGameplayEffectContextHandle ContextHandle = Spec.GetContext();
	FCFR_GameplayEffectContext* FCFRContext = static_cast<FCFR_GameplayEffectContext*>(ContextHandle.Get());

	const auto LaunchEventData = Cast<UCFR_LaunchEventDataAsset>(FCFRContext->AbilitySourceData.Get());

	if (LaunchEventData == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Wrong payload type"));
		return;
	}

	if (TargetCharacter && InstigatorCharacter)
	{
		TargetCharacter->PushCharacter(InstigatorCharacter, LaunchEventData);
	}
}
