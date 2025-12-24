// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/CFR_BT_FindStrafeDirection.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Float.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Enum.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "AI/CFR_AIController.h"
#include "Characters/CFR_AICharacter.h"
#include "Subsystems/CFR_CombatManagerSubsystem.h"

UCFR_BT_FindStrafeDirection::UCFR_BT_FindStrafeDirection(const FObjectInitializer& ObjectInitializer)
{
	bCreateNodeInstance = true;
	NodeName = "Find Strafe Direction";
}

EBTNodeResult::Type UCFR_BT_FindStrafeDirection::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Controller = Cast<ACFR_AIController>(OwnerComp.GetAIOwner());

	if (Controller && LocationSeekerQuery)
	{
		const float playerDistance = GetDistance(OwnerComp);
		if (playerDistance > 0.0)
		{
			LocationSeekerQueryRequest = FEnvQueryRequest(LocationSeekerQuery, Controller->Agent);
			LocationSeekerQueryRequest.SetFloatParam("OnCircle.CircleRadius", playerDistance);
			LocationSeekerQueryRequest.SetFloatParam("Distance.FloatValueMax", MaxDistanceFromOwner);
			LocationSeekerQueryRequest.Execute(EEnvQueryRunMode::AllMatching, this, &UCFR_BT_FindStrafeDirection::LocationSeekerQueryFinished);
			return EBTNodeResult::InProgress;
		}
	}

	return EBTNodeResult::Failed;
}

void UCFR_BT_FindStrafeDirection::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);

	UBlackboardData* BBAsset = GetBlackboardAsset();
	if (BBAsset)
	{
		DistanceKey.ResolveSelectedKey(*BBAsset);
	}
	else
	{
		UE_LOG(LogBehaviorTree, Warning, TEXT("Can't initialize task: %s, make sure that behavior tree specifies blackboard asset!"), *GetName());
	}
}

void UCFR_BT_FindStrafeDirection::LocationSeekerQueryFinished(TSharedPtr<FEnvQueryResult> Result)
{
	float currentBestScore = 0;
	TArray<FVector> locations;
	Result->GetAllAsLocations(locations);

	TArray<TTuple<FVector, float>> locationsRight;
	TArray<TTuple<FVector, float>> locationsLeft;
	const FVector fromLocation = Controller->Agent->GetActorLocation();
	const FVector rightVector = Controller->Agent->GetActorRightVector();

	int32 index = 0;
	for (auto& loc : locations)
	{
		const FVector direction = (loc - fromLocation).GetSafeNormal2D();
		if (FVector::DotProduct(rightVector, direction) >= 0.0)
		{
			locationsRight.Add(MakeTuple(loc, Result->GetItemScore(index++)));
		}
		else
		{
			locationsLeft.Add(MakeTuple(loc, Result->GetItemScore(index++)));
		}
	}

	auto sortFunction = [fromLocation](const auto& left, const auto& right)
		{
			const float distanceLeft = FVector::Dist2D(fromLocation, left.Key);
			const float distanceRight = FVector::Dist2D(fromLocation, right.Key);
			return distanceLeft < distanceRight;
		};

	locationsRight.Sort(sortFunction);
	locationsLeft.Sort(sortFunction);

	int32 bestLocationRightIndex = BestReachableLocationInDirection(locationsRight);
	int32 bestLocationLeftIndex = BestReachableLocationInDirection(locationsLeft);

	UBehaviorTreeComponent* OwnerComp = Cast<UBehaviorTreeComponent>(GetOuter());
	if (bestLocationRightIndex < 0 && bestLocationLeftIndex < 0)
	{
		FinishLatentTask(*OwnerComp, EBTNodeResult::Failed);
	}
	else if (bestLocationRightIndex < 0)
	{
		const auto& bestLeft = locationsLeft[bestLocationLeftIndex];
		// TODO: Key is hardcoded.
		Controller->BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(Controller->StrafeDirectionKeyId, static_cast<uint8>(ECFR_StrafeDirection::Left));

		FinishLatentTask(*OwnerComp, EBTNodeResult::Succeeded);
	}
	else if (bestLocationLeftIndex < 0)
	{
		const auto& bestRight = locationsRight[bestLocationRightIndex];
		Controller->BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(Controller->StrafeDirectionKeyId, static_cast<uint8>(ECFR_StrafeDirection::Right));
		FinishLatentTask(*OwnerComp, EBTNodeResult::Succeeded);
	}
	else
	{
		const auto& bestLeft = locationsLeft[bestLocationLeftIndex];
		const auto& bestRight = locationsRight[bestLocationRightIndex];

		if (bestRight.Value >= bestLeft.Value)
		{
			Controller->BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(Controller->StrafeDirectionKeyId, static_cast<uint8>(ECFR_StrafeDirection::Right));
		}
		else
		{
			Controller->BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(Controller->StrafeDirectionKeyId, static_cast<uint8>(ECFR_StrafeDirection::Left));
		}

		FinishLatentTask(*OwnerComp, EBTNodeResult::Succeeded);
	}
}

int32 UCFR_BT_FindStrafeDirection::BestReachableLocationInDirection(const TArray<TTuple<FVector, float>>& Locations) const
{
	int32 currentBestIndex = -1;
	float currentBestScore = 0.0;

	int32 index = 0;
	for (const auto& loc : Locations)
	{
		const FVector& location = loc.Key;
		float score = loc.Value;

		if (IsDistanceGreaterThanX(location) && score > currentBestScore)
		{
			currentBestIndex = index;
			currentBestScore = score;
		}
		else
		{
			break;
		}

		++index;
	}

	return currentBestIndex;
}

bool UCFR_BT_FindStrafeDirection::IsDistanceGreaterThanX(const FVector& Location) const
{
	// TODO: Do we want CombatManager dependency in here?

	//for (const auto& item : Controller->CombatManager->EnemyMeleeItems)
	//{
	//	if (item.IsValid() && item.Enemy != Controller->Agent)
	//	{
	//		const float distance = (Location - item.Enemy->GetActorLocation()).Size2D();
	//		if (distance <= MinDistanceToOtherEnemies)
	//		{
	//			return false;
	//		}
	//	}
	//}

	//for (const auto& item : Controller->CombatManager->EnemyRangedItems)
	//{
	//	if (item.IsValid() && item.Enemy != Controller->Agent)
	//	{
	//		const float distance = (Location - item.Enemy->GetActorLocation()).Size2D();
	//		if (distance <= MinDistanceToOtherEnemies)
	//		{
	//			return false;
	//		}
	//	}
	//}

	return true;
}

float UCFR_BT_FindStrafeDirection::GetDistance(UBehaviorTreeComponent& OwnerComp) const
{
	const UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent();
	if (MyBlackboard)
	{
		if (DistanceKey.SelectedKeyType == UBlackboardKeyType_Float::StaticClass())
		{
			return MyBlackboard->GetValue<UBlackboardKeyType_Float>(DistanceKey.GetSelectedKeyID());
		}
	}

	return 0.0f;
}
