// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

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
	}
}

bool ACFR_AIController::InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset)
{
	bool bResult = Super::InitializeBlackboard(BlackboardComp, BlackboardAsset);

	return bResult;
}
