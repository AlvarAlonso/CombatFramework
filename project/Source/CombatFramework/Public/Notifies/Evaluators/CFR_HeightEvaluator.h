// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Interfaces/CFR_EvaluatorInterface.h"

#include "CFR_HeightEvaluator.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_HeightEvaluator : public UCFR_EvaluatorBase
{
	GENERATED_BODY()
	
public:
	virtual bool Evaluate_Implementation(AActor* Actor) const override;
};
