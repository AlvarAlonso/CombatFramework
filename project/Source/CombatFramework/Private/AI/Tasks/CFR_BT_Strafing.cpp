// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/CFR_BT_Strafing.h"
#include "AIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Enum.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Characters/CFR_AICharacter.h"

EBTNodeResult::Type UCFR_BT_Strafing::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	bNotifyTick = true;

	const AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	ACFR_AICharacter* Enemy = Cast<ACFR_AICharacter>(ControlledPawn);
	Enemy->bOrbiting = true;

	Direction = GetDirection(OwnerComp);

	return EBTNodeResult::InProgress;
}

void UCFR_BT_Strafing::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	ACFR_AICharacter* Enemy = Cast<ACFR_AICharacter>(ControlledPawn);

	if (Enemy->TargetActor == nullptr)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	FVector dirStrafe;
	switch (Direction)
	{
	case ECFR_StrafeDirection::Forward:
		dirStrafe = ControlledPawn->GetActorForwardVector();
		break;
	case ECFR_StrafeDirection::Backward:
		dirStrafe = -ControlledPawn->GetActorForwardVector();
		break;
	case ECFR_StrafeDirection::Right:
		dirStrafe = ControlledPawn->GetActorRightVector();
		break;
	case ECFR_StrafeDirection::Left:
		dirStrafe = -ControlledPawn->GetActorRightVector();
		break;
	default:
		dirStrafe = FVector::ZeroVector;
		break;
	}

	ControlledPawn->AddMovementInput(dirStrafe);

	FinishLatentTask(OwnerComp, EBTNodeResult::InProgress);
}

void UCFR_BT_Strafing::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);

	UBlackboardData* BBAsset = GetBlackboardAsset();
	if (BBAsset)
	{
		DirectionKey.ResolveSelectedKey(*BBAsset);
	}
	else
	{
		UE_LOG(LogBehaviorTree, Warning, TEXT("Can't initialize task: %s, make sure that behavior tree specifies blackboard asset!"), *GetName());
	}
}

EBTNodeResult::Type UCFR_BT_Strafing::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	if (ACFR_AICharacter* Enemy = Cast<ACFR_AICharacter>(ControlledPawn))
	{
		Enemy->bOrbiting = false;
	}

	return EBTNodeResult::Aborted;
}

ECFR_StrafeDirection::Type UCFR_BT_Strafing::GetDirection(UBehaviorTreeComponent& OwnerComp) const
{
	const UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent();
	if (MyBlackboard)
	{
		if (DirectionKey.IsNone() == false && DirectionKey.SelectedKeyType == UBlackboardKeyType_Enum::StaticClass())
		{
			return (ECFR_StrafeDirection::Type)MyBlackboard->GetValue<UBlackboardKeyType_Enum>(DirectionKey.GetSelectedKeyID());
		}
		else
		{
			return StrafeDirection;
		}
	}

	return ECFR_StrafeDirection::None;
}

