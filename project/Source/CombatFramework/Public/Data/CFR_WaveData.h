#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "Data/CFR_EnemyData.h"

#include "CFR_WaveData.generated.h"

UCLASS(BlueprintType)
class UCFR_WaveDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("WaveType", GetFName());
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EEnemyType, int> Enemies;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UCFR_WaveDataAsset> NextWave;

	// TODO: Add level to load ?
};
