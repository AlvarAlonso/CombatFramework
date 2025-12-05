#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ECFR_EnemyAIState : uint8
{
	None		UMETA(DisplayName = "None"),
	Attacking	UMETA(DisplayName = "Attacking"),
	Holding		UMETA(DisplayName = "Holding"),
	Waiting		UMETA(DisplayName = "Waiting"),
	Recovering	UMETA(DisplayName = "Recovering"),
	WasHit		UMETA(DisplayName = "WasHit")
};

UENUM(BlueprintType)
enum class ECFR_StrafeDirection : uint8
{
	None		UMETA(DisplayName = "None"),
	Forward		UMETA(DisplayName = "Forward"),
	Backward	UMETA(DisplayName = "Backward"),
	Right		UMETA(DisplayName = "Right"),
	Left		UMETA(DisplayName = "Left")
};