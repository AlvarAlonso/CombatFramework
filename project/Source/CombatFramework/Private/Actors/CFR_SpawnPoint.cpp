#include "Actors/CFR_SpawnPoint.h"

#include "NavigationSystem.h"

#include "Components/SphereComponent.h"

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

	const auto RandomSpawnInSphere = [this](AActor* InActor) -> bool
		{
			const auto randomVector = FMath::VRand();
			const auto randomDistance = FMath::FRandRange(0.0, SphereComponent->GetScaledSphereRadius());
			auto location = GetActorLocation() + randomVector * randomDistance;
			auto rotation = GetActorRotation();

			auto world = GetWorld();

			if (auto navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(world))
			{
				FNavLocation outLocation;
				if (!navSystem->GetRandomPointInNavigableRadius(GetActorLocation(), SphereComponent->GetScaledSphereRadius(), outLocation))
				{
					return false;
				}

				if (!GetWorld()->FindTeleportSpot(InActor, outLocation.Location, rotation))
				{
					return false;
				}

				InActor->SetActorLocation(location);
				return true;

			}

			return false;
		};

	if (!RandomSpawnInSphere(InActor))
	{
		FTimerHandle timerHandle;
		GetWorldTimerManager().SetTimer(timerHandle, [this, InActor]()
			{
				Spawn(InActor);
			}, 1.0f, false);
	}
}

bool ACFR_SpawnPoint::CanSpawn()
{
	return true;
}