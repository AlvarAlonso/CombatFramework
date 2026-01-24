// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenericTeamAgentInterface.h"

#include "AbilitySystem/CFR_EventDataPayloads.h"

#include "CFR_Projectile.generated.h"

UCLASS()
class COMBATFRAMEWORK_API ACFR_Projectile : public AActor, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACFR_Projectile();

	/** GenericTeamAgentInterface */
	UFUNCTION(BlueprintCallable)
	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;

	UFUNCTION(BlueprintCallable)
	virtual FGenericTeamId GetGenericTeamId() const override;

public:
	/* Actor who fired the bullet */
	AActor* Instigator = nullptr;

protected:
	/* Effects the projectile applies when hitting a target */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FCFR_EffectContextContainer> EffectContextsToApply;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGenericTeamId ProjectileTeam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BaseSpeed = 500.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Damage = 20.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float LifeSpan = 10.0f;
};
