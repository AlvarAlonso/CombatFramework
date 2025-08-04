#include "Actors/CFR_SpawnPoint.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NavigationSystem.h"

#include "Components/SphereComponent.h"

ACFR_SpawnPoint::ACFR_SpawnPoint()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SpawnArea"));
	RootComponent = SphereComponent;
}

bool ACFR_SpawnPoint::SpawnActor(AActor* InActor)
{
	if (!CanSpawn())
	{
		return false;
	}

	auto world = GetWorld();

	if (auto navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(world))
	{
		FNavLocation outLocation;
		if (!navSystem->GetRandomPointInNavigableRadius(GetActorLocation(), SphereComponent->GetScaledSphereRadius(), outLocation))
		{
			return false;
		}

		if (!GetWorld()->FindTeleportSpot(InActor, outLocation.Location, FRotator{}))
		{
			return false;
		}

		InActor->SetActorLocation(outLocation.Location);

		return true;
	}

	return false;
}

bool ACFR_SpawnPoint::CanSpawn()
{
	return true;
}