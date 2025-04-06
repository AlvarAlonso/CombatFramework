#include "AbilitySystem/GameplayEffects/CFR_InstantDeathEffect.h"

#include "AbilitySystem/CFR_AttributeSet.h"

UCFR_InstantDeathEffect::UCFR_InstantDeathEffect()
{
	DurationPolicy = EGameplayEffectDurationType::Instant;

	FGameplayModifierInfo ModifierInfo;
	ModifierInfo.Attribute = UCFR_AttributeSet::GetCurrentHealthAttribute();
	ModifierInfo.ModifierOp = EGameplayModOp::Override;
	ModifierInfo.ModifierMagnitude = { 0 };

	Modifiers.Add(ModifierInfo);
}