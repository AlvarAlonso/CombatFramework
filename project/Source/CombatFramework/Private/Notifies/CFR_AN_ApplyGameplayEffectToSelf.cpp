// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/CFR_AN_ApplyGameplayEffectToSelf.h"
#include "AbilitySystem/CFR_EventDataPayloads.h"
#include "Characters/CFR_CharacterBase.h"
#include "AbilitySystem/CFR_AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"

void UCFR_AN_ApplyGameplayEffectToSelf::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	AActor* Owner = MeshComp->GetOwner();
	if (Owner)
	{
		ACFR_CharacterBase* CharacterBase = Cast<ACFR_CharacterBase>(Owner);

		UAbilitySystemComponent* ACS = CharacterBase ? CharacterBase->GetAbilitySystemComponent() : nullptr;
		if (ACS)
		{
			// TODO: This can be placed in a function outside this class and be reusable.
			FGameplayEffectContextHandle EffectContextHandle = ACS->MakeEffectContext();
			FGameplayEffectSpecHandle GameplayEffectSpecHandle = ACS->MakeOutgoingSpec(EffectToApply, CharacterBase->GetCharacterLevel(), EffectContextHandle);

			FCFR_GameplayEffectContext* CFRContextHandle = static_cast<FCFR_GameplayEffectContext*>(EffectContextHandle.Get());
			CFRContextHandle->AbilitySourceData = EventPayload;

			FGameplayEffectSpec* GESpec = GameplayEffectSpecHandle.Data.Get();
			ACS->ApplyGameplayEffectSpecToSelf(*GESpec);
		}
	}
}
