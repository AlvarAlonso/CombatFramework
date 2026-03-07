#include "AbilitySystem/GameplayEffects/CFR_HealEffect.h"

#include "AbilitySystem/CFR_AttributeSet.h"

UCFR_HealEffect::UCFR_HealEffect()
{
	DurationPolicy = EGameplayEffectDurationType::Instant;

	FGameplayEffectModifierMagnitude ModifierMagnitud(HealAmount);

	FGameplayModifierInfo ModifierInfo;
	ModifierInfo.Attribute = UCFR_AttributeSet::GetCurrentHealthAttribute();
	ModifierInfo.ModifierOp = EGameplayModOp::Additive;
	ModifierInfo.ModifierMagnitude = ModifierMagnitud;

	Modifiers.Add(ModifierInfo);
}