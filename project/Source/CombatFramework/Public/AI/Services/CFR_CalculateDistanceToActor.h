// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CFR_CalculateDistanceToActor.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_CalculateDistanceToActor : public UBTService
{
	GENERATED_BODY()
	
public:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;

protected:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector TargetKey;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector BlackboardKey;

private:
	const AActor* GetTargetActor(UBehaviorTreeComponent& OwnerComp) const;
	float CalculateDistanceBetweenActors(const AActor* Owner, const AActor* Target) const;
	bool SetDistanceInBlackboard(UBehaviorTreeComponent& OwnerComp, const float Distance);
};
