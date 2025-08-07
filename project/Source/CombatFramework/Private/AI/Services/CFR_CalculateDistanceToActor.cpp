// Fill out your copyright notice in the Description page of Project Settings.

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Float.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

#include "AI/Services/CFR_CalculateDistanceToActor.h"

void UCFR_CalculateDistanceToActor::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	const bool bTargetKeyIsValid = OwnerComp.GetBlackboardComponent()->IsValidKey(OwnerComp.GetBlackboardComponent()->GetKeyID(TargetKey.SelectedKeyName));
	const bool bBlackboardKeyIsValid = OwnerComp.GetBlackboardComponent()->IsValidKey(OwnerComp.GetBlackboardComponent()->GetKeyID(BlackboardKey.SelectedKeyName));
	if (!bTargetKeyIsValid || !bBlackboardKeyIsValid)
	{
		return;
	}

	const AActor* TargetActor = GetTargetActor(OwnerComp);
	if (TargetActor == nullptr)
	{
		return;
	}

	const float Distance = CalculateDistanceBetweenActors(OwnerComp.GetAIOwner()->GetPawn(), TargetActor);
	SetDistanceInBlackboard(OwnerComp, Distance);
}

void UCFR_CalculateDistanceToActor::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);

	UBlackboardData* BBAsset = GetBlackboardAsset();
	if (BBAsset)
	{
		TargetKey.ResolveSelectedKey(*BBAsset);
		BlackboardKey.ResolveSelectedKey(*BBAsset);
	}
	else
	{
		UE_LOG(LogBehaviorTree, Warning, TEXT("Can't initialize task: %s, make sure that behavior tree specifies blackboard asset!"), *GetName());
	}
}

const AActor* UCFR_CalculateDistanceToActor::GetTargetActor(UBehaviorTreeComponent& OwnerComp) const
{
	const UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent();
	if (MyBlackboard)
	{
		if (TargetKey.SelectedKeyType == UBlackboardKeyType_Object::StaticClass())
		{
			UObject* KeyValue = MyBlackboard->GetValue<UBlackboardKeyType_Object>(TargetKey.GetSelectedKeyID());
			return Cast<AActor>(KeyValue);
		}	
	}

	return nullptr;
}

float UCFR_CalculateDistanceToActor::CalculateDistanceBetweenActors(const AActor* Owner, const AActor* Target) const
{
	const FVector OwnerLocation = Owner->GetActorLocation();
	const FVector TargetLocation = Target->GetActorLocation();

	return FVector::Dist2D(OwnerLocation, TargetLocation);
}

bool UCFR_CalculateDistanceToActor::SetDistanceInBlackboard(UBehaviorTreeComponent& OwnerComp, const float Distance)
{
	UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent();
	if (MyBlackboard)
	{
		if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Float::StaticClass())
		{
			return MyBlackboard->SetValue<UBlackboardKeyType_Float>(BlackboardKey.GetSelectedKeyID(), Distance);
		}
	}

	return false;
}
