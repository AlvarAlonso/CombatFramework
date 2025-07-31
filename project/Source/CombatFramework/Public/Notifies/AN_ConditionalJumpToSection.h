// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"

#include "Interfaces/CFR_EvaluatorInterface.h"

#include "AN_ConditionalJumpToSection.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UAN_ConditionalJumpToSection : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:
	UPROPERTY(EditAnywhere)
	FName SectionName;

	UPROPERTY(EditAnywhere, Instanced)
	UCFR_EvaluatorBase* Evaluator;
};
