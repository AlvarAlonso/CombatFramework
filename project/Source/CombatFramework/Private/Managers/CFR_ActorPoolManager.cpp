#include "Managers/CFR_ActorPoolManager.h"

#include "Characters/CFR_CharacterBase.h"

void UCFR_ActorPoolManager::Init()
{
	for (const auto actorType : ActorPoolMap)
	{
		InitPool(actorType.Key, actorType.Value);
	}
}

AActor* UCFR_ActorPoolManager::GetActor(TSubclassOf<ACFR_AICharacter> InClassType) const
{
	auto pool = ActorPools.Find(InClassType);

	if (!pool)
	{
		return nullptr;
	}

	// TODO Add more actors if empty()
	for (auto actor : pool->Actors)
	{
		if (actor->bIsActive)
		{
			continue;
		}

		actor->SetActorHiddenInGame(false);
		actor->SetActorEnableCollision(true);
		actor->bIsActive = true;

		return actor;
	}

	return nullptr;
}

void UCFR_ActorPoolManager::ReturnActor(ACFR_AICharacter* InActor, TSubclassOf<ACFR_AICharacter> InClass)
{
	auto pool = ActorPools.Find(InClass);

	if (!pool)
	{
		UE_LOG(LogTemp, Error, TEXT("Pool of type %s"), *InClass->GetName())
	}

	InActor->SetActorHiddenInGame(true);
	InActor->SetActorEnableCollision(false);
	InActor->bIsActive = false;

	pool->Actors.Add(InActor);
}

void UCFR_ActorPoolManager::InitPool(TSubclassOf<ACFR_AICharacter> InActorClass, int32 InPoolSize)
{
	check(InActorClass);
	check(InPoolSize > 0);

	const auto world = GetWorld();
	check(world);

	auto& pool = ActorPools.FindOrAdd(InActorClass);

	for (int32 index = 0; index < InPoolSize; ++index)
	{
		auto actor = Cast<ACFR_AICharacter>(world->SpawnActor(InActorClass));
		actor->SetActorHiddenInGame(true);
		actor->SetActorEnableCollision(false);

		pool.Actors.Add(actor);
	}
}
