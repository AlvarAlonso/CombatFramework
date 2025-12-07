// Fill out your copyright notice in the Description page of Project Settings.
#include "AI/CFR_AIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Enum.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Int.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "Kismet/GameplayStatics.h"

#include "Characters/CFR_AICharacter.h"
#include "Subsystems/CFR_CombatManagerSubsystem.h"

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
	GetWorld()->GetTimerManager().ClearTimer(DamageTakenTimerHandle);

	Super::EndPlay(EndPlayReason);
}

void ACFR_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	auto* AICharacter = Cast<ACFR_AICharacter>(InPawn);
	if (AICharacter && AICharacter->BehaviorTreeTemplate)
	{
		Agent = AICharacter;
		InitializeBlackboard(*Blackboard, *AICharacter->BehaviorTreeTemplate->BlackboardAsset);
		StartLogic();

		Agent->OnDamageTakenDelegate.AddDynamic(this, &ACFR_AIController::HandleOnDamageTaken);
	}
}

ECFR_EnemyAIState ACFR_AIController::GetEnemyAIState() const
{
	if (Blackboard && Blackboard->GetBlackboardAsset())
	{
		return static_cast<ECFR_EnemyAIState>(Blackboard->GetValue<UBlackboardKeyType_Enum>(AIStateKey));
	}

	return ECFR_EnemyAIState::None;
}

void ACFR_AIController::SetEnemyAIState(ECFR_EnemyAIState state)
{
	if (Blackboard && Blackboard->GetBlackboardAsset())
	{
		Blackboard->SetValueAsEnum(AIStateKey, static_cast<uint8>(state));
	}
}

void ACFR_AIController::StartLogic()
{
	const auto BehaviorTreeTemplate = Agent->BehaviorTreeTemplate;
	const auto BehaviorTreeSubtrees = Agent->BehaviorTreesByState;

	// Start Behavior Tree
	BehaviorTreeComponent->StartTree(*BehaviorTreeTemplate);

	for (auto It = BehaviorTreeSubtrees.CreateConstIterator(); It; ++It)
	{
		if (It)
		{
			BehaviorTreeComponent->SetDynamicSubtree(It->Key, It->Value);
		}
	}

	// TODO: Dynamic phases.
}

bool ACFR_AIController::InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset)
{
	bool bResult = Super::InitializeBlackboard(BlackboardComp, BlackboardAsset);

	// TODO: Dirty.
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	
	// TODO: Do not hardcode keys. Extract them from blackboard.
	BlackboardComp.SetValue<UBlackboardKeyType_Object>("TargetActor", PlayerCharacter);
	BlackboardComp.SetValue<UBlackboardKeyType_Enum>("AIState", static_cast<uint8>(ECFR_EnemyAIState::Attacking)); // TODO: Change that to None after implementing AI logic.

	return bResult;
}

void ACFR_AIController::HandleOnDamageTaken(const float Damage)
{
	DamageTaken();
}

void ACFR_AIController::DamageTaken()
{
	if (Blackboard && Blackboard->GetBlackboardAsset())
	{
		int currentValue = Blackboard->GetValue<UBlackboardKeyType_Int>("ConsecutiveHits");
		Blackboard->SetValue<UBlackboardKeyType_Int>("ConsecutiveHits", ++currentValue);

		GetWorld()->GetTimerManager().ClearTimer(DamageTakenTimerHandle);
		GetWorld()->GetTimerManager().SetTimer(DamageTakenTimerHandle, [this]() {
			if (Blackboard && Blackboard->GetBlackboardAsset())
			{
				Blackboard->SetValue<UBlackboardKeyType_Int>("ConsecutiveHits", 0);
			}
			}, TimeConsecutiveHits, false);
	}
}
