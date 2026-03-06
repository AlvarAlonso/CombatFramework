// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h"
#include "CFR_GA_SuicidalFrenzie.generated.h"

class UMaterialInstance;

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_GA_SuicidalFrenzie : public UCFR_GA_PlayMontage
{
	GENERATED_BODY()

protected:
	bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;

	void OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData) override;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float FrenzieSpeedMultiplier = 2.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UMaterialInstance* FrenziedMaterial;
};
