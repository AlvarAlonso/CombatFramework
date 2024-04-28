// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayEffects/CFR_Execution_Damage.h"
#include "AbilitySystem/CFR_AttributeSet.h"
#include "AbilitySystem/CFR_AbilitySystemGlobals.h"
#include "AbilitySystem/CFR_EventDataPayloads.h"

struct CFR_DamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Strength)
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage)

	CFR_DamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCFR_AttributeSet, Strength, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCFR_AttributeSet, Damage, Source, true);
	}
};

static const CFR_DamageStatics& DamageStatics()
{
	static CFR_DamageStatics DamageStatics;
	return DamageStatics;
}

UCFR_Execution_Damage::UCFR_Execution_Damage()
{
	RelevantAttributesToCapture.Add(DamageStatics().StrengthDef);
	RelevantAttributesToCapture.Add(DamageStatics().DamageDef);
}

void UCFR_Execution_Damage::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	// Extract ASC.
	const UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
	const UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();

	// Extract avatar actors.
	AActor* TargetActor = TargetASC ? TargetASC->GetAvatarActor() : nullptr;
	AActor* SourceActor = SourceASC ? SourceASC->GetAvatarActor() : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	// Extract tags.
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	// TODO: Checks (ex: if invulnerable or already dead, do not apply damage and return).

	// Read EventData from GameplayEffectContext.
	const auto GEContextHandle = Spec.GetContext();
	const auto CFR_GEContext = static_cast<const FCFR_GameplayEffectContext*>(GEContextHandle.Get());

	const auto DamageEventData = Cast<UCFR_DamageEventDataAsset>(CFR_GEContext->OptionalObject);
	if (DamageEventData != nullptr)
	{
		FAggregatorEvaluateParameters EvaluationParameters;
		EvaluationParameters.TargetTags = TargetTags;
		EvaluationParameters.SourceTags = SourceTags;

		float Strength = 0.0f;
		ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().StrengthDef, EvaluationParameters, Strength);

		// TODO: Damage calculation function. Ex: GE BaseDamage + Strength * StrengthFactor - TargetDef.
		float FinalDamage = 0.0f;
		FinalDamage = Strength + DamageEventData->Damage;

		if (FinalDamage > 0.0f)
		{
			OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(CFR_DamageStatics().DamageProperty, EGameplayModOp::Additive, FinalDamage));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Wrong payload type! Expected UCFR_DamageEventDataAsset."));
	}
}
