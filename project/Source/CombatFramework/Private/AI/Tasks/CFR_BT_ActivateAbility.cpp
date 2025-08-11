// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/CFR_BT_ActivateAbility.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystemGlobals.h"
#include "AIController.h"

UCFR_BT_ActivateAbility::UCFR_BT_ActivateAbility()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UCFR_BT_ActivateAbility::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = EBTNodeResult::Failed;

	const AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* Pawn = AIController->GetPawn();

	UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Pawn);
	if (ASC->TryActivateAbilityByClass(AbilityToActivate))
	{
		const FGameplayAbilitySpec* AbilitySpec = ASC->FindAbilitySpecFromClass(AbilityToActivate);

		UGameplayAbility* AbilityInstance = AbilitySpec->GetPrimaryInstance();
		if (AbilityInstance->IsActive())
		{
			AbilityInstance->OnGameplayAbilityEnded.AddUObject(this, &UCFR_BT_ActivateAbility::OnAbilityEnded);
			Result = EBTNodeResult::InProgress;
		}
		else
		{
			Result = EBTNodeResult::Succeeded;
		}
	}

	return Result;
}

void UCFR_BT_ActivateAbility::OnAbilityEnded(UGameplayAbility* EndedAbility)
{
	UBehaviorTreeComponent* OwnerComp = Cast<UBehaviorTreeComponent>(GetOuter());
	FinishLatentTask(*OwnerComp, EBTNodeResult::Succeeded);
}
