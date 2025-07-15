#pragma once

#include "CoreMinimal.h"

UENUM()
enum class ECFR_AnimEvent: uint8
{
	None				UMETA(DisplayName = "None"),
	BasicHitReact		UMETA(DisplayName = "BasicHitReact"),
	KnockbackHitReact	UMETA(DisplayName = "KnockbackHitReact"),
	LaunchHitReact		UMETA(DisplayName = "LaunchHitReact"),
	AirHitReact			UMETA(DisplayName = "AirHitReact"),
	Death				UMETA(DisplayName = "Death")
};