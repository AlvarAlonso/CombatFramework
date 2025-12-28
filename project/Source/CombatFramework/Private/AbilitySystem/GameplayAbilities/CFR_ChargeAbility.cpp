// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/CFR_ChargeAbility.h"
#include "AbilitySystem/CFR_GameplayTags.h"
#include "AbilitySystem/AbilityTasks/CFR_ChargeForwardAbilityTask.h"

void UCFR_ChargeAbility::OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData)
{
	Super::OnReceivedEvent(EventTag, EventData);

	if(EventTag.MatchesTagExact(FCFR_GameplayTags::Get().GameplayEvent_StartedCharge))
	{
		StartCharge();
	}
}

void UCFR_ChargeAbility::StartCharge()
{
	UCFR_ChargeForwardAbilityTask* Task = UCFR_ChargeForwardAbilityTask::ChargeForwardAbilityTask(this, NAME_None, ChargeDuration, HitboxTag);
	Task->OnFinished.AddDynamic(this, &UCFR_ChargeAbility::OnChargeFinished);
	Task->OnOverlapped.AddDynamic(this, &UCFR_ChargeAbility::OnOverlapped);
	Task->ReadyForActivation();
}

void UCFR_ChargeAbility::OnChargeFinished()
{
	EndAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), false, false);
}

void UCFR_ChargeAbility::OnOverlapped()
{
	MontageJumpToSection(ResolutionMontageSection);
}
