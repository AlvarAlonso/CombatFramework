// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTags.h"
#include "CFR_ANS_ActivateHitbox.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_ANS_ActivateHitbox : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag HitboxTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag EffectTag;
};
