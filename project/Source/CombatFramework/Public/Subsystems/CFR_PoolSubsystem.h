#pragma once

#include "CFR_PoolSubsystem.generated.h"

USTRUCT()
struct FActorPool
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TObjectPtr<AActor>> Actors;
};

UCLASS()
class UCFR_PoolSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UCFR_PoolSubsystem() = default;

	static AActor* GetActor(UWorld* InWorld, TSubclassOf<AActor> InClassType);
	static void ReleaseActor(AActor* InActor);

	void InitPool(TSubclassOf<AActor> InActorClass, int32 InPoolSize);

private:
	AActor* GetActor(TSubclassOf<AActor> InClassType);
	void ReleaseActor_Internal(AActor* InActor);

	UPROPERTY()
	TMap<TSubclassOf<AActor>, FActorPool> ActorPools;
};
