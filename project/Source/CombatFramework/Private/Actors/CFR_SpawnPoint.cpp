#include "Actors/CFR_SpawnPoint.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
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

	const auto world = GetWorld();
	const auto player = UGameplayStatics::GetPlayerCharacter(world, 0);
	check(player);

	const auto location = GetActorLocation();
	const auto vectorToPlayer = player->GetActorLocation() - location;
	const auto rotation = vectorToPlayer.Rotation();

	const auto RandomSpawnInSphere = [&](AActor* InActor) -> bool
		{
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

				InActor->SetActorLocation(outLocation.Location);
				InActor->SetActorRotation(rotation);
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