#pragma once

#include "CFR_SpawnerManager.generated.h"

class ACFR_SpawnPoint;

UCLASS()
class UCFR_SpawnerManager : public UObject
{
    GENERATED_BODY()

public:
    void SpawnActors();

private:
    UPROPERTY(EditAnywhere)
    TArray<ACFR_SpawnPoint *> SpawnPoints;
};
