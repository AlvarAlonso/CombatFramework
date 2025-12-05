// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"

#include "AI/CFR_AIController.h"

#include "CFR_BT_Strafing.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_BT_Strafing : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	/** initialize any asset related data */
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;

protected:
	EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	ECFR_StrafeDirection GetDirection(UBehaviorTreeComponent& OwnerComp) const;

protected:
	UPROPERTY(EditAnywhere, Category = Input)
	ECFR_StrafeDirection StrafeDirection = ECFR_StrafeDirection::None;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector DirectionKey;

private:
	ECFR_StrafeDirection Direction = ECFR_StrafeDirection::None;
};
