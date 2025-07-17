// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CFR_BlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UCFR_BlueprintFunctionLibrary|GameplayMechanics")
	static void RotateDirectlyTowardsActor(AActor* Source, const AActor* Target, bool bFaceBackwards);
};
