#include "Actors/CFR_SpawnPoint.h"

#include "Characters/CFR_CharacterBase.h"

void ACFR_SpawnPoint::Spawn(ACFR_CharacterBase* InActor)
{
	if (!CanSpawn())
	{
		return;
	}

	InActor->SetActorLocation(GetActorLocation());
}

bool ACFR_SpawnPoint::CanSpawn()
{
	return true;
}