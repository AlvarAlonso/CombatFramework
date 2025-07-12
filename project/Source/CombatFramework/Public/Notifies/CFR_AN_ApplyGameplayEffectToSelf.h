// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GameplayEffect.h"

#include "CFR_AN_ApplyGameplayEffectToSelf.generated.h"

class UCFR_EventDataAsset;
/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_AN_ApplyGameplayEffectToSelf : public UAnimNotify
{
	GENERATED_BODY()
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> EffectToApply;

	UPROPERTY(EditAnywhere)
	UCFR_EventDataAsset* EventPayload;
};
