// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h"
#include "CFR_ChargeAbility.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_ChargeAbility : public UCFR_GA_PlayMontage
{
	GENERATED_BODY()

protected:
	void OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData) override;

private:
	void StartCharge();

	UFUNCTION()
	void OnChargeFinished();

	UFUNCTION()
	void OnOverlapped();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ChargeDuration = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag HitboxTag; // Stops the charge when this hitbox overlaps.

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ResolutionMontageSection; // The montage section to play after finishing the charge movement.

private:
	FTimerHandle ChargeTimerHandle;
};
