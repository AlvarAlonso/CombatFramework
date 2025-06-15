#pragma once

#include "CFR_SpawnerManager.generated.h"

class ACFR_SpawnPoint;
class ACFR_AICharacter;

UCLASS(DefaultToInstanced)
class UCFR_SpawnerManager : public UObject
{
	GENERATED_BODY()

public:
	void Init();

	UFUNCTION(BlueprintCallable)
	void SpawnActors(TSubclassOf<ACFR_AICharacter> InActorTypeToSpawn, int InNumberActorsToSpawn);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ACFR_SpawnPoint*> SpawnPoints;
};
