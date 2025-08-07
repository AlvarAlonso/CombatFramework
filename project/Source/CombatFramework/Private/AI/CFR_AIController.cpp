// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Enum.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "Kismet/GameplayStatics.h"

#include "Characters/CFR_AICharacter.h"
#include "Subsystems/CFR_CombatManagerSubsystem.h"

#include "AI/CFR_AIController.h"

ACFR_AIController::ACFR_AIController(const FObjectInitializer& ObjectInitializer)
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree Component"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
}

void ACFR_AIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		CombatManagerSubsystem = GetWorld()->GetSubsystem<UCFR_CombatManagerSubsystem>();
		if (!CombatManagerSubsystem)
		{
			UE_LOG(LogTemp, Warning, TEXT("UCFR_CombatManagerSubsystem not found!"));
		}
	}
}

void ACFR_AIController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ACFR_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	auto* AICharacter = Cast<ACFR_AICharacter>(InPawn);
	if (AICharacter && AICharacter->BehaviorTree)
	{
		Agent = AICharacter;
		InitializeBlackboard(*Blackboard, *AICharacter->BehaviorTree->BlackboardAsset);
		StartLogic();
	}
}

ECFR_EnemyAIState::Type ACFR_AIController::GetEnemyAIState() const
{
	if (Blackboard && Blackboard->GetBlackboardAsset())
	{
		return static_cast<ECFR_EnemyAIState::Type>(Blackboard->GetValue<UBlackboardKeyType_Enum>(AIStateKey));
	}

	return ECFR_EnemyAIState::None;
}

void ACFR_AIController::SetEnemyAIState(ECFR_EnemyAIState::Type state)
{
	if (Blackboard && Blackboard->GetBlackboardAsset())
	{
		Blackboard->SetValueAsEnum(AIStateKey, state);
	}
}

void ACFR_AIController::StartLogic()
{
	// Start Behavior Tree
	BehaviorTreeComponent->StartTree(*Agent->BehaviorTree);

	// TODO: Dynamic phases.
}

bool ACFR_AIController::InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset)
{
	bool bResult = Super::InitializeBlackboard(BlackboardComp, BlackboardAsset);

	// TODO: Dirty.
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	
	// TODO: Do not hardcode keys. Extract them from blackboard.
	BlackboardComp.SetValue<UBlackboardKeyType_Object>("TargetActor", PlayerCharacter);
	BlackboardComp.SetValue<UBlackboardKeyType_Enum>("AIState", ECFR_EnemyAIState::None);

	return bResult;
}
