// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Enums/CFR_AIEnums.h"
#include "CFR_AIController.generated.h"

class UBehaviorTreeComponent;
class UBlackboardComponent;
class ACFR_AICharacter;
class UCFR_CombatManagerSubsystem;

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API ACFR_AIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ACFR_AIController(const FObjectInitializer& ObjectInitializer);

	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void OnPossess(APawn* InPawn) override;

	UFUNCTION(BlueprintCallable)
	ECFR_EnemyAIState GetEnemyAIState() const;

	UFUNCTION(BlueprintCallable)
	void SetEnemyAIState(ECFR_EnemyAIState state);

	UFUNCTION(BlueprintCallable)
	void StartLogic();

protected:
	virtual bool InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset) override;
	UFUNCTION()
	void HandleOnDamageTaken(const float Damage);
	void DamageTaken();

public:
	UPROPERTY(transient)
	UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(transient)
	UBlackboardComponent* BlackboardComponent;

	UPROPERTY(EditAnywhere)
	float TimeConsecutiveHits = 1.0f;

	TObjectPtr<ACFR_AICharacter> Agent = nullptr;
	TObjectPtr<UCFR_CombatManagerSubsystem> CombatManagerSubsystem = nullptr;

	FName AIStateKey;

private:
	uint32 BehaviorPhaseIndex = 0;
	FTimerHandle TimerHandle;
};
