// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h"
#include "CFR_GA_SuicidalExplosion.generated.h"

class UCFR_LaunchEventDataAsset;

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_GA_SuicidalExplosion : public UCFR_GA_PlayMontage
{
	GENERATED_BODY()
	
protected:
	bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;
	void OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData) override;

private:
	void Explode();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ExplosionRadius = 200.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UCFR_LaunchEventDataAsset* LaunchEventData;

	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* ExplosionVFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayEffect> InstantDeathEffect;
};
