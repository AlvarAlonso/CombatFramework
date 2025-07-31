// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/Evaluators/CFR_HeightEvaluator.h"

#include "AbilitySystem/CFR_BlueprintFunctionLibrary.h"

bool UCFR_HeightEvaluator::Evaluate_Implementation(AActor* Actor) const
{
	return UCFR_BlueprintFunctionLibrary::IsGonnaHitGround(Actor, Distance);
}
