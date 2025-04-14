#pragma once

#include "CFR_ActorPoolManager.generated.h"

class ACFR_CharacterBase;
UCLASS()
class UCFR_ActorPoolManager : public UObject
{
	GENERATED_BODY()

public:
	void InitPool(TSubclassOf<ACFR_CharacterBase> InActorClass, int32 InPoolSize);

	template <typename T>
	T* GetActor()
	{
		auto pool = ActorPools.Find(T::StaticClass());

		if (!pool)
		{
			return nullptr;
		}

		for (auto actor : pool)
		{
			if (actor && !actor->IsActive())
			{
				actor->SetActorHiddenInGame(false);
				actor->SetActorEnableCollision(true);

				return Cast<T*>(actor);
			}
		}

		return nullptr;
	}

	void ReturnActor(ACFR_CharacterBase* InActor, TSubclassOf<ACFR_CharacterBase> InClass);

private:
	TMap<TSubclassOf<ACFR_CharacterBase>, TArray<ACFR_CharacterBase*>> ActorPools;
};
