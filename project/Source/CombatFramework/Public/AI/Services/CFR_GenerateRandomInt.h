// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CFR_GenerateRandomInt.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_GenerateRandomInt : public UBTService
{
	GENERATED_BODY()
	
public:
	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	void InitializeFromAsset(UBehaviorTree& Asset) override;

private:
	bool SetNumberInBlackboard(UBehaviorTreeComponent& OwnerComp, int32 RandomNumber);

protected:
	UPROPERTY(EditAnywhere)
	int32 MinNumber = 0;

	UPROPERTY(EditAnywhere)
	int32 MaxNumber = 100;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector BlackboardKey;
};
