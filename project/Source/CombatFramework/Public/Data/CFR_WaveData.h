#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "CFR_WaveData.generated.h"

UCLASS()
class UCFR_WaveDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("WaveType", GetFName());
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<TSubclassOf<AActor>, int> Enemies;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UCFR_WaveDataAsset> NextWave;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName LevelName;
};
