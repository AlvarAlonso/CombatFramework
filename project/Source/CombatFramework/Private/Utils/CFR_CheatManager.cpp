#include "Utils/CFR_CheatManager.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/GameplayEffects/CFR_InstantDeathEffect.h"
#include "Characters/CFR_PlayerCharacter.h"

void UCFR_CheatManager::KillPlayer()
{
	const auto PlayerCharacter = Cast<ACFR_PlayerCharacter>(GetPlayerController()->GetPawn());
	check(PlayerCharacter);

	const auto ASC = Cast<UCFR_AbilitySystemComponent>(PlayerCharacter->GetAbilitySystemComponent());
	check(ASC);

	auto GEInstantDeathEffect = NewObject<UCFR_InstantDeathEffect>();
	ASC->ApplyGameplayEffectToSelf(GEInstantDeathEffect, 1.0f, ASC->MakeEffectContext());
}
