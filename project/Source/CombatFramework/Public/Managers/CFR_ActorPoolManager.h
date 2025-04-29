#pragma once

#include "Characters/CFR_CharacterBase.h"

class UCFR_ActorPoolManager : public UObject
{
public:
	void InitPool(TSubclassOf<ACFR_CharacterBase> InActorClass, int32 InPoolSize);

	template <typename T>
	T* GetActor() const
	{
		auto pool = ActorPools.Find(T::StaticClass());

		if (!pool)
		{
			return nullptr;
		}

		// TODO Add more actors if empty()

		for (auto actor : *pool)
		{
			if (actor->bIsActive)
			{
				continue;
			}

			actor->SetActorHiddenInGame(false);
			actor->SetActorEnableCollision(true);
			actor->bIsActive = true;

			return Cast<T>(actor);
		}

		return nullptr;
	}

	void ReturnActor(ACFR_CharacterBase* InActor, TSubclassOf<ACFR_CharacterBase> InClass);

private:
	TMap<TSubclassOf<ACFR_CharacterBase>, TArray<ACFR_CharacterBase*>> ActorPools;
};
