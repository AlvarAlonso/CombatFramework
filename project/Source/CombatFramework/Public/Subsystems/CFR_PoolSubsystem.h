#pragma once

#include "CFR_PoolSubsystem.generated.h"

USTRUCT()
struct FActorPool
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TObjectPtr<AActor>> Actors;
};

UCLASS(Blueprintable)
class UCFR_PoolSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UCFR_PoolSubsystem() = default;

	// USubsystem interface
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	// UWorldSubsystem interface
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	// UCFR_PoolSubsystem
	static AActor* GetActor(UWorld* InWorld, TSubclassOf<AActor> InClassType);
	static void ReleaseActor(AActor* InActor);

private:
	void InitPool(TSubclassOf<AActor> InActorClass, int32 InPoolSize);
	AActor* GetActor(TSubclassOf<AActor> InClassType);
	void ReleaseActor_Internal(AActor* InActor);

	UPROPERTY(EditDefaultsOnly)
	TMap<TSubclassOf<AActor>, int32> PoolActors;
	TMap<TSubclassOf<AActor>, FActorPool> Pools;
};
