// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputTriggers.h"
#include "CFR_InputTriggerHoldWithReset.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_InputTriggerHoldWithReset : public UInputTrigger
{
	GENERATED_BODY()

public:
    UCFR_InputTriggerHoldWithReset();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger")
    float HoldTimeThreshold;

protected:
    float HeldDuration = 0.f;
    bool bHasBeenReleased = true;
    bool bWasActuatedLastFrame = false;

    virtual ETriggerState UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime) override;
};
