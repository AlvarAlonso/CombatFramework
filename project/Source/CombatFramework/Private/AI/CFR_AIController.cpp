// Fill out your copyright notice in the Description page of Project Settings.
#include "AI/CFR_AIController.h"

#include "BehaviorTree/BehaviorTree.h"
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

	if (const auto world = GetWorld())
	{
		CombatManagerSubsystem = world->GetSubsystem<UCFR_CombatManagerSubsystem>();
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

	Agent = Cast<ACFR_AICharacter>(InPawn);

	if (!Agent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessed Pawn is not of type ACFR_AICharacter!"));
		return;
	}

	if (Agent->SpawnMontage)
	{
		Agent->PlayAnimMontage(Agent->SpawnMontage);

		FOnMontageEnded SpawnMontageEndedDelegate;
		SpawnMontageEndedDelegate.BindUObject(this, &ACFR_AIController::HandleOnSpawnMontageEnded);
		Agent->GetMesh()->GetAnimInstance()->Montage_SetEndDelegate(SpawnMontageEndedDelegate);
	}
	else
	{
		StartLogic();
	}
}

ECFR_EnemyAIState ACFR_AIController::GetEnemyAIState() const
{
	if (Blackboard && Blackboard->GetBlackboardAsset())
	{
		return static_cast<ECFR_EnemyAIState>(Blackboard->GetValue<UBlackboardKeyType_Enum>(AIStateKeyId));
	}

	return ECFR_EnemyAIState::None;
}

void ACFR_AIController::SetEnemyAIState(ECFR_EnemyAIState state)
{
	if (Blackboard && Blackboard->GetBlackboardAsset())
	{
		Blackboard->SetValue<UBlackboardKeyType_Enum>(AIStateKeyId, static_cast<uint8>(state));
	}
}

void ACFR_AIController::StartLogic()
{
	if (!Agent->BehaviorTreeTemplate)
	{
		UE_LOG(LogTemp, Warning, TEXT("BehaviorTreeTemplate not set for %s!"), *Agent->GetName());
		return;
	}

	InitializeBlackboard(*Blackboard, *Agent->BehaviorTreeTemplate->BlackboardAsset);

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

	Agent->OnDamageTakenDelegate.AddDynamic(this, &ACFR_AIController::HandleOnDamageTaken);
}

bool ACFR_AIController::InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset)
{
	bool bResult = Super::InitializeBlackboard(BlackboardComp, BlackboardAsset);

	// Set Blackboard Key IDS
	// TODO: Do not hardcode keys.
	TargetKeyId = Blackboard->GetKeyID("TargetActor");
	DistanceToPlayerKeyId = Blackboard->GetKeyID("DistanceToPlayer");
	RandomNumberKeyId = Blackboard->GetKeyID("RandomNumber");
	AIStateKeyId = Blackboard->GetKeyID("AIState");
	ConsecutiveHitsKeyId = Blackboard->GetKeyID("ConsecutiveHits");
	MitigatedHitsKeyId = Blackboard->GetKeyID("MitigatedHits");
	StrafeDirectionKeyId = Blackboard->GetKeyID("StrafeDirection");
	StrafeLocationKeyId = Blackboard->GetKeyID("StrafeLocation");

	// TODO: Dirty.
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);


	BlackboardComp.SetValue<UBlackboardKeyType_Object>(TargetKeyId, PlayerCharacter);
	BlackboardComp.SetValue<UBlackboardKeyType_Enum>(AIStateKeyId, static_cast<uint8>(ECFR_EnemyAIState::Attacking)); // TODO: Change that to None after implementing AI logic.
	BlackboardComp.SetValue<UBlackboardKeyType_Enum>(StrafeDirectionKeyId, static_cast<uint8>(ECFR_StrafeDirection::None));

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

void ACFR_AIController::HandleOnSpawnMontageEnded(UAnimMontage* /*Montage*/, bool /*bInterrupted*/)
{
	StartLogic();
}
