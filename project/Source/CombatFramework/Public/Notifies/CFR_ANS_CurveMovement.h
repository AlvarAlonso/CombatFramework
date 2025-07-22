// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "CFR_ANS_CurveMovement.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_ANS_CurveMovement : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUseTick = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AirMultiplier = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Magnitude = 0.0f;

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

private:
	float GetSpeed(USkeletalMeshComponent* MeshComp) const;
};
