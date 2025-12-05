// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AI/CFR_AIController.h"
#include "CFR_BT_EnemyOrbit.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_BT_EnemyOrbit : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

protected:
	EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	ECFR_StrafeDirection GetKeyValue(UBehaviorTreeComponent& OwnerComp) const;

protected:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector DirectionKey;

private:
	ECFR_StrafeDirection KeyValue = ECFR_StrafeDirection::None;

};
