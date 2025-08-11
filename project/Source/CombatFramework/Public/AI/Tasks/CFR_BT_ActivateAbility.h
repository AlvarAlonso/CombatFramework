// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CFR_BT_ActivateAbility.generated.h"

class UGameplayAbility;
/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_BT_ActivateAbility : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UCFR_BT_ActivateAbility();

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UFUNCTION()
	void OnAbilityEnded(UGameplayAbility* EndedAbility);
	
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayAbility> AbilityToActivate;
};
