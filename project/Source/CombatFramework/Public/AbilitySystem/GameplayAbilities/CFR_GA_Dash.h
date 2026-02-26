// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h"

#include "CFR_GA_Dash.generated.h"

UCLASS()
class COMBATFRAMEWORK_API UCFR_GA_Dash : public UCFR_GA_PlayMontage
{
	GENERATED_BODY()

public:
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> InvulnerabilityEffect;

	UPROPERTY(EditAnywhere)
	float DashForce = 1000.0f;

private:
	float FrictionFactor;
	float GroundFriction;
	float BrakingDecelerationWalking;
};
