// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CFR_EvaluatorInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCFR_EvaluatorInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COMBATFRAMEWORK_API ICFR_EvaluatorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool Evaluate(AActor* Actor) const;
	virtual bool Evaluate_Implementation(AActor* Actor) const = 0;
};

UCLASS(Abstract)
class COMBATFRAMEWORK_API UCFR_EvaluatorBase : public UObject, public ICFR_EvaluatorInterface
{
	GENERATED_BODY()

public:
	virtual bool Evaluate_Implementation(AActor* Actor) const override { return false; };
};
