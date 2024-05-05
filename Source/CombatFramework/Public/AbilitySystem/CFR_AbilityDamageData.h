#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/CFR_AbilitySourceDataInterface.h"

#include "CFR_AbilityDamageData.generated.h"

UCLASS()
class UCFR_AbilityDamageData : public UObject, public ICFR_AbilitySourceDataInterface
{
	GENERATED_BODY()

public:
	UCFR_AbilityDamageData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) {}

public:
	float Damage;
};