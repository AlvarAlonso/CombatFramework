// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"

#include "CFR_Execution_Damage.generated.h"

/**
 * 
 */
UCLASS()
class UCFR_Execution_Damage : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
	UCFR_Execution_Damage();
	void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
