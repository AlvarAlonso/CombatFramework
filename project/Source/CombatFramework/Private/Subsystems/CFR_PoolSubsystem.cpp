#include "Subsystems/CFR_PoolSubsystem.h"

#include "Characters/CFR_AICharacter.h"

AActor* UCFR_PoolSubsystem::GetActor(UWorld* InWorld, TSubclassOf<ACFR_AICharacter> InClassType)
{
	if (!InWorld)
	{
		UE_LOG(LogTemp, Warning, TEXT("GetActor received and invalid world."));
		return nullptr;
	}

	auto poolManager = InWorld->GetSubsystem<UCFR_PoolSubsystem>();

	if (!poolManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("World cannot find a valid ActorPoolManager!"));
		return nullptr;
	}

	return poolManager->GetActor(InClassType);
}

void UCFR_PoolSubsystem::ReleaseActor(ACFR_AICharacter* InActor)
{
	auto poolManager = InActor->GetWorld()->GetSubsystem<UCFR_PoolSubsystem>();
	poolManager->ReleaseActor_Internal(InActor);
}

void UCFR_PoolSubsystem::InitPool(TSubclassOf<ACFR_AICharacter> InActorClass, int32 InPoolSize)
{
	check(InActorClass);
	check(InPoolSize > 0);

	const auto world = GetWorld();
	check(world);

	for (int32 index = 0; index < InPoolSize; ++index)
	{
		auto actor = Cast<ACFR_AICharacter>(world->SpawnActor(InActorClass));
		actor->SetActorHiddenInGame(true);
		actor->SetActorEnableCollision(false);

		ReleaseActor(MoveTemp(actor));
	}
}

AActor* UCFR_PoolSubsystem::GetActor(TSubclassOf<ACFR_AICharacter> InClassType)
{
	auto pool = &ActorPools.FindOrAdd(InClassType);
	ACFR_AICharacter* actor{ nullptr };

	if (pool->Actors.IsValidIndex(0))
	{
		actor = Cast<ACFR_AICharacter>(pool->Actors[0]);
		pool->Actors.RemoveAtSwap(0, 1, EAllowShrinking::No);
	}

	if (!actor)
	{
		// Spawn a new actor of type that will eventually return to the pool.
		return GetWorld()->SpawnActor(InClassType);
	}

	actor->SetActorHiddenInGame(false);
	actor->SetActorEnableCollision(true);
	actor->bIsActive = true;

	return actor;
}

void UCFR_PoolSubsystem::ReleaseActor_Internal(ACFR_AICharacter* InActor)
{
	InActor->SetActorHiddenInGame(true);
	InActor->SetActorEnableCollision(false);
	InActor->bIsActive = false;

	auto pool = &ActorPools.FindOrAdd(InActor->GetClass());
	pool->Actors.Add(InActor);
}
