#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "CFR_WaveData.generated.h"

class ACFR_AICharacter;

UCLASS(Blueprintable, BlueprintType)
class UCFR_WaveDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("WaveType", GetFName());
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<TSubclassOf<ACFR_AICharacter>, int> Enemies;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UCFR_WaveDataAsset> NextWave;

	// TODO: Add level to load ?
};
