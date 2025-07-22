// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/CFR_InputTriggerHoldWithReset.h"

UCFR_InputTriggerHoldWithReset::UCFR_InputTriggerHoldWithReset()
{
    HoldTimeThreshold = 0.5f;
    HeldDuration = 0.f;
    bHasBeenReleased = true;
    bWasActuatedLastFrame = false;
}

ETriggerState UCFR_InputTriggerHoldWithReset::UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime)
{
    const bool bIsActuated = IsActuated(ModifiedValue);
    ETriggerState State = ETriggerState::None;

    // Detect key release
    if (!bIsActuated && bWasActuatedLastFrame)
    {
        bHasBeenReleased = true;
        HeldDuration = 0.f;
    }

    // If currently held
    if (bIsActuated)
    {
        if (bHasBeenReleased)
        {
            HeldDuration += DeltaTime;

            if (HeldDuration >= HoldTimeThreshold)
            {
                bHasBeenReleased = false; // block further triggers until released
                State = ETriggerState::Triggered;
            }
            else
            {
                State = ETriggerState::Ongoing;
            }
        }
    }

    bWasActuatedLastFrame = bIsActuated;
    return State;
}
