#pragma once

#include "CFR_CinematicTriggerType.generated.h"

UENUM(BlueprintType)
enum class ECinematicTriggerType : uint8
{
	BeginPlay UMETA(DisplayName = "Begin Play"),
	Overlap   UMETA(DisplayName = "Trigger"),
	Manual    UMETA(DisplayName = "Manual"),
	EndPlay   UMETA(DisplayName = "End Play"),
};