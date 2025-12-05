// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/CFR_BT_EnemyOrbit.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Enum.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/CFR_AICharacter.h"

EBTNodeResult::Type UCFR_BT_EnemyOrbit::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	bNotifyTick = true;

	const AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	ACFR_AICharacter* Enemy = Cast<ACFR_AICharacter>(ControlledPawn);
	Enemy->bOrbiting = true;

	KeyValue = GetKeyValue(OwnerComp);

	return EBTNodeResult::InProgress;
}

void UCFR_BT_EnemyOrbit::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	ACFR_AICharacter* Enemy = Cast<ACFR_AICharacter>(ControlledPawn);

	if (Enemy->TargetActor == nullptr)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	FVector direction;
	switch (KeyValue)
	{
	case ECFR_StrafeDirection::Right: // Right
		direction = ControlledPawn->GetActorRightVector();
		break;
	case ECFR_StrafeDirection::Left:
		direction = -ControlledPawn->GetActorRightVector();
		break;
	default:
		direction = FVector::ZeroVector;
	}

	ControlledPawn->AddMovementInput(direction);

	FinishLatentTask(OwnerComp, EBTNodeResult::InProgress);
}

EBTNodeResult::Type UCFR_BT_EnemyOrbit::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	if (ACFR_AICharacter* Enemy = Cast<ACFR_AICharacter>(ControlledPawn))
	{
		Enemy->bOrbiting = false;
	}

	return EBTNodeResult::Aborted;
}

ECFR_StrafeDirection UCFR_BT_EnemyOrbit::GetKeyValue(UBehaviorTreeComponent& OwnerComp) const
{
	const UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent();
	if (MyBlackboard)
	{
		if (DirectionKey.SelectedKeyType == UBlackboardKeyType_Enum::StaticClass())
		{
			return (ECFR_StrafeDirection)MyBlackboard->GetValue<UBlackboardKeyType_Enum>(DirectionKey.GetSelectedKeyID());
		}
	}

	return ECFR_StrafeDirection::None;
}
