#include "Utils/CFR_CheatManager.h"

#include "EngineUtils.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/GameplayEffects/CFR_DamageEffect.h"
#include "AbilitySystem/GameplayEffects/CFR_HealEffect.h"
#include "AbilitySystem/GameplayEffects/CFR_InstantDeathEffect.h"
#include "Characters/CFR_PlayerCharacter.h"
#include "Characters/CFR_AICharacter.h"

void UCFR_CheatManager::KillPlayer()
{
	const auto PlayerCharacter = Cast<ACFR_PlayerCharacter>(GetPlayerController()->GetPawn());
	check(PlayerCharacter);

	const auto ASC = Cast<UCFR_AbilitySystemComponent>(PlayerCharacter->GetAbilitySystemComponent());
	check(ASC);

	auto GEInstantDeathEffect = NewObject<UCFR_InstantDeathEffect>();
	ASC->ApplyGameplayEffectToSelf(GEInstantDeathEffect, 1.0f, ASC->MakeEffectContext());
}

void UCFR_CheatManager::Hurt()
{
	const auto PlayerCharacter = Cast<ACFR_PlayerCharacter>(GetPlayerController()->GetPawn());
	check(PlayerCharacter);

	const auto ASC = Cast<UCFR_AbilitySystemComponent>(PlayerCharacter->GetAbilitySystemComponent());
	check(ASC);

	auto GEDamageEffect = NewObject<UCFR_DamageEffect>();
	ASC->ApplyGameplayEffectToSelf(GEDamageEffect, 1.0f, ASC->MakeEffectContext());
}

void UCFR_CheatManager::Heal()
{
	const auto PlayerCharacter = Cast<ACFR_PlayerCharacter>(GetPlayerController()->GetPawn());
	check(PlayerCharacter);

	const auto ASC = Cast<UCFR_AbilitySystemComponent>(PlayerCharacter->GetAbilitySystemComponent());
	check(ASC);

	auto GEHealEffect = NewObject<UCFR_HealEffect>();
	ASC->ApplyGameplayEffectToSelf(GEHealEffect, 1.0f, ASC->MakeEffectContext());
}

void UCFR_CheatManager::KillAllEnemies()
{
	auto world = GetWorld();
	check(world);

	for (TActorIterator<ACFR_AICharacter> it(world, ACFR_AICharacter::StaticClass()); it; ++it)
	{
		if (auto character = *it)
		{
			const auto ASC = character->GetAbilitySystemComponent();
			check(ASC);

			auto GEInstantDeathEffect = NewObject<UCFR_InstantDeathEffect>();
			ASC->ApplyGameplayEffectToSelf(GEInstantDeathEffect, 1.0f, ASC->MakeEffectContext());
		}
	}

}
