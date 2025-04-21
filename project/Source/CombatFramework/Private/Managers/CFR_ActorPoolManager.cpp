#include "Managers/CFR_ActorPoolManager.h"

#include "Characters/CFR_CharacterBase.h"

void UCFR_ActorPoolManager::InitPool(TSubclassOf<ACFR_CharacterBase> InActorClass, int32 InPoolSize)
{
	check(InActorClass);
	check(InPoolSize > 0);

	const auto world = GetWorld();
	check(world);

	auto pool = ActorPools.FindOrAdd(InActorClass);

	for (int32 index = 0; index < InPoolSize; ++index)
	{
		auto actor = Cast<ACFR_CharacterBase>(world->SpawnActor(InActorClass));
		actor->SetActorHiddenInGame(true);
		actor->SetActorEnableCollision(false);

		pool.Add(actor);
	}
}

void UCFR_ActorPoolManager::ReturnActor(ACFR_CharacterBase* InActor, TSubclassOf<ACFR_CharacterBase> InClass)
{
	auto pool = ActorPools.Find(InClass);

	if (!pool)
	{
		UE_LOG(LogTemp, Error, TEXT("Pool of type %s"), *InClass->GetName())
	}

	InActor->SetActorHiddenInGame(true);
	InActor->SetActorEnableCollision(false);
	InActor->bIsActive = false;

	pool->Add(InActor);
}
