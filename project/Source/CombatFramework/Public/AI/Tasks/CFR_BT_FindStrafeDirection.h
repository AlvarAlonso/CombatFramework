// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "CFR_BT_FindStrafeDirection.generated.h"

class ACFR_AIController;
/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_BT_FindStrafeDirection : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UCFR_BT_FindStrafeDirection(const FObjectInitializer& ObjectInitializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	void InitializeFromAsset(UBehaviorTree& Asset) override;

private:
	void LocationSeekerQueryFinished(TSharedPtr<FEnvQueryResult> Result);
	int32 BestReachableLocationInDirection(const TArray<TTuple<FVector, float>>& Locations) const;
	bool IsDistanceGreaterThanX(const FVector& Location) const;
	float GetDistance(UBehaviorTreeComponent& OwnerComp) const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
	UEnvQuery* LocationSeekerQuery;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector DistanceKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
	float MaxDistanceFromOwner = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
	float MinDistanceToOtherEnemies = 500.0f;

private:
	FEnvQueryRequest LocationSeekerQueryRequest;

	ACFR_AIController* Controller;

	FVector StrafeLocation = FVector::ZeroVector;

};
