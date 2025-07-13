#pragma once

#include "CoreMinimal.h"

#include "CFR_EnemyData.generated.h"

UENUM(BlueprintType)
enum class EEnemyType : uint8
{
	PEASANT UMETA(DisplayName = "Peasant"),
	DISTANCE_PEASANT UMETA(DisplayName = "DistancePeasant"),
	SHIELD_PEASANT UMETA(DisplayName = "ShieldPeasant"),
};