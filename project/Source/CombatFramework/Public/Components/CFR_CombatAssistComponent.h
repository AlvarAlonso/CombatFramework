// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CFR_CombatAssistComponent.generated.h"

class UCFR_MovementAssistComponent;
class UCFR_TargettingComponent;
class ACFR_CharacterBase;
class ACFR_AICharacter;
class UGameplayAbility;
class UCFR_AbilitySystemComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATFRAMEWORK_API UCFR_CombatAssistComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCFR_CombatAssistComponent();

private:
	void HandlePlayerASCInitialized(UCFR_AbilitySystemComponent* ASC);
	void HandleMeleeAbilityActivated(UGameplayAbility* GameplayAbility);
	void HandleMeleeAbilityEnded(UGameplayAbility* GameplayAbility);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	void PerformAttackAutoAssist();

	UFUNCTION(BlueprintCallable)
	void EndAttackAutoAssist();

	void SetAttackMoveDuration(float TotalDuration);

	void ShowDebug();

	UPROPERTY(EditAnywhere)
	bool bShowDebug = true;

private:
	/** Auto Assist Attack */
	UPROPERTY(EditAnywhere)
	float AutoAssistDot;

	UPROPERTY(EditAnywhere)
	float AutoAssistOffsetToEnemy;

	UPROPERTY(EditAnywhere)
	float MaxAutoassistMove;

	/** Attack Movement */
	UPROPERTY(EditAnywhere)
	float AttackOffsetToEnemy;

	TWeakObjectPtr<UCFR_MovementAssistComponent> MovementAssistComponent;
	TWeakObjectPtr<UCFR_TargettingComponent> TargettingComponent;

	/* Implementation specific variables */
	float MoveVectorSpeed = 0.0f;
	float AutoAssistMove = 0.0f;
	float AttackMoveDuration = 0.0f;
	float AttackMoveDurationLeft = 0.0f;

	float PreviousMaxAcceleration;
};
