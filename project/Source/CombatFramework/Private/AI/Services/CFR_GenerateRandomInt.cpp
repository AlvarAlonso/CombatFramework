// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/CFR_GenerateRandomInt.h"

#include "BehaviorTree/Blackboard/BlackboardKeyType_Int.h"
#include "BehaviorTree/BlackboardComponent.h"

void UCFR_GenerateRandomInt::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	const bool bBlackboardKeyIsValid = OwnerComp.GetBlackboardComponent()->IsValidKey(OwnerComp.GetBlackboardComponent()->GetKeyID(BlackboardKey.SelectedKeyName));
	if (bBlackboardKeyIsValid == false)
	{
		return;
	}

	int32 randomNumber = FMath::RandRange(MinNumber, MaxNumber);
	SetNumberInBlackboard(OwnerComp, randomNumber);
}

void UCFR_GenerateRandomInt::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);

	UBlackboardData* BBAsset = GetBlackboardAsset();
	if (BBAsset)
	{
		BlackboardKey.ResolveSelectedKey(*BBAsset);
	}
	else
	{
		UE_LOG(LogBehaviorTree, Warning, TEXT("Can't initialize task: %s, make sure that behavior tree specifies blackboard asset!"), *GetName());
	}
}

bool UCFR_GenerateRandomInt::SetNumberInBlackboard(UBehaviorTreeComponent& OwnerComp, int32 RandomNumber)
{
	UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent();
	if (MyBlackboard)
	{
		if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Int::StaticClass())
		{
			return MyBlackboard->SetValue<UBlackboardKeyType_Int>(BlackboardKey.GetSelectedKeyID(), RandomNumber);
		}
	}

	return false;
}
