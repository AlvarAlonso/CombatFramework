// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CFR_AN_ChangeCollisionPreset.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_AN_ChangeCollisionPreset : public UAnimNotify
{
	GENERATED_BODY()
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<ECollisionChannel> NewCollisionChannel;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<ECollisionResponse> NewCollisionResponse;
};
