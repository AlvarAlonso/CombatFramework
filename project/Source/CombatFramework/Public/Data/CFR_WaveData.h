#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "CFR_WaveData.generated.h"

UCLASS(BlueprintType)
class UCFR_ArenaDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("WaveType", GetFName());
	}

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<TSubclassOf<AActor>, int> Enemies;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<ULevel> Level;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName LevelName;
};
