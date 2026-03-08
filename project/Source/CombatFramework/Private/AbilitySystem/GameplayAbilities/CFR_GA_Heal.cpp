
#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/GameplayEffects/CFR_HealEffect.h"
#include "Characters/CFR_PlayerCharacter.h"

#include "AbilitySystem/GameplayAbilities/CFR_GA_Heal.h"

void UCFR_GA_Heal::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		constexpr bool bReplicateEndAbility = true;
		constexpr bool bWasCancelled = true;
		EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	}

	const auto PlayerCharacter = Cast<ACFR_PlayerCharacter>(ActorInfo->AvatarActor);
	const auto ASC = Cast<UCFR_AbilitySystemComponent>(PlayerCharacter->GetAbilitySystemComponent());

	auto GEHealEffect = NewObject<UCFR_HealEffect>();
	GEHealEffect->HealAmount = 50.0f;
	ASC->ApplyGameplayEffectToSelf(GEHealEffect, 0.5f, ASC->MakeEffectContext());

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
