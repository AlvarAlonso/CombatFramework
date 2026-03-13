#include "AbilitySystem/GameplayEffects/CFR_GE_GainMana.h"
#include "AbilitySystem/CFR_AttributeSet.h"

UCFR_GE_GainMana::UCFR_GE_GainMana()
{
	DurationPolicy = EGameplayEffectDurationType::Instant;

	FGameplayModifierInfo ModifierInfo;
	ModifierInfo.Attribute = UCFR_AttributeSet::GetCurrentManaAttribute();
	ModifierInfo.ModifierOp = EGameplayModOp::Additive;
	ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(FScalableFloat(10.0f));

	Modifiers.Add(ModifierInfo);
}