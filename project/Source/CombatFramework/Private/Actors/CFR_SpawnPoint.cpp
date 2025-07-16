#include "Components/SphereComponent.h"

#include "Actors/CFR_SpawnPoint.h"

ACFR_SpawnPoint::ACFR_SpawnPoint()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SpawnArea"));
	RootComponent = SphereComponent;
}

void ACFR_SpawnPoint::Spawn(AActor* InActor)
{
	if (!CanSpawn())
	{
		return;
	}

	static constexpr int spawnTries = 5;

	const auto RandomSpawnInSphere = [this](AActor* InActor) -> bool
		{
			const auto randomVector = FMath::VRand();
			const auto randomDistance = FMath::FRandRange(0.0, SphereComponent->GetScaledSphereRadius());
			auto location = GetActorLocation() + randomVector * randomDistance;
			auto rotation = GetActorRotation();

			if (GetWorld()->FindTeleportSpot(InActor, location, rotation))
			{
				InActor->SetActorLocation(location);
				return true;
			}
			else
			{
				return false;
			}
		};

	for (int tries = 0; tries < spawnTries; ++tries)
	{
		if (RandomSpawnInSphere(InActor))
		{
			return;
		}
	}
}

bool ACFR_SpawnPoint::CanSpawn()
{
	return true;
}