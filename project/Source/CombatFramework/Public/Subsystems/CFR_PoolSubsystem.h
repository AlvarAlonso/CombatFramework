#pragma once

#include "Characters/CFR_AICharacter.h"

#include "CFR_PoolSubsystem.generated.h"

USTRUCT()
struct FActorPool
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TObjectPtr<ACFR_AICharacter>> Actors;
};

UCLASS()
class UCFR_PoolSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UCFR_PoolSubsystem() = default;

	static AActor* GetActor(UWorld* InWorld, TSubclassOf<ACFR_AICharacter> InClassType);
	static void ReleaseActor(ACFR_AICharacter* InActor);

	void InitPool(TSubclassOf<ACFR_AICharacter> InActorClass, int32 InPoolSize);

private:
	AActor* GetActor(TSubclassOf<ACFR_AICharacter> InClassType);
	void ReleaseActor_Internal(ACFR_AICharacter* InActor);

	UPROPERTY()
	TMap<TSubclassOf<ACFR_AICharacter>, FActorPool> ActorPools;
};
