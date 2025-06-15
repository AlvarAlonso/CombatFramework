#pragma once

#include "Characters/CFR_AICharacter.h"

#include "CFR_ActorPoolManager.generated.h"

USTRUCT()
struct FActorPool
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<ACFR_AICharacter*> Actors;
};

UCLASS(DefaultToInstanced, EditInlineNew)
class UCFR_ActorPoolManager : public UObject
{
	GENERATED_BODY()

public:
	UCFR_ActorPoolManager() = default;

	void Init();

	template <typename T>
	T* GetActor() const
	{
		return Cast<T>(GetActor(T::StaticClass()));
	}

	AActor* GetActor(TSubclassOf<ACFR_AICharacter> InClassType) const;

	void ReturnActor(ACFR_AICharacter* InActor, TSubclassOf<ACFR_AICharacter> InClass);

private:
	void InitPool(TSubclassOf<ACFR_AICharacter> InActorClass, int32 InPoolSize);

	UPROPERTY(EditDefaultsOnly)
	TMap<TSubclassOf<ACFR_AICharacter>, uint32> ActorPoolMap;

	UPROPERTY()
	TMap<TSubclassOf<ACFR_AICharacter>, FActorPool> ActorPools;
};
