#include "AbilitySystem/GameplayEffects/CFR_DamageEffect.h"

#include "AbilitySystem/CFR_AttributeSet.h"

UCFR_DamageEffect::UCFR_DamageEffect()
{
	DurationPolicy = EGameplayEffectDurationType::Instant;

	FGameplayEffectModifierMagnitude ModifierMagnitud(-Damage);

	FGameplayModifierInfo ModifierInfo;
	ModifierInfo.Attribute = UCFR_AttributeSet::GetCurrentHealthAttribute();
	ModifierInfo.ModifierOp = EGameplayModOp::Additive;
	ModifierInfo.ModifierMagnitude = ModifierMagnitud;

	Modifiers.Add(ModifierInfo);
}