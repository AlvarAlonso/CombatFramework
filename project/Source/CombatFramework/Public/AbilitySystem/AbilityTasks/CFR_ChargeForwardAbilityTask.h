// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "CFR_ChargeForwardAbilityTask.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FChargeForwardDelegate);

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_ChargeForwardAbilityTask : public UAbilityTask
{
	GENERATED_BODY()
	
public:
	UCFR_ChargeForwardAbilityTask(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UCFR_ChargeForwardAbilityTask* ChargeForwardAbilityTask(UGameplayAbility* OwningAbility, FName TaskInstanceName, float Duration, FGameplayTag HitboxTag);

	virtual void Activate() override;
	virtual void TickTask(float DeltaTime) override;

private:
	UFUNCTION()
	void OnHitboxOverlap(AActor* OverlappedActor);

	UFUNCTION()
	void OnChargeFinished();

public:
	UPROPERTY(BlueprintAssignable)
	FChargeForwardDelegate OnFinished;

	UPROPERTY(BlueprintAssignable)
	FChargeForwardDelegate OnOverlapped;

private:
	float Duration = 0.0f;
	FGameplayTag HitboxTag; // Stops the charge when this hitbox overlaps.

	FTimerHandle TimerHandle;
};
