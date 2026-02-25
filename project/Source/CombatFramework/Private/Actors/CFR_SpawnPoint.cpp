#include "Actors/CFR_SpawnPoint.h"

#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "NavigationSystem.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


ACFR_SpawnPoint::ACFR_SpawnPoint()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SpawnArea"));
	RootComponent = SphereComponent;
}

bool ACFR_SpawnPoint::FindSpawnPoint(UCapsuleComponent* InCapsuleComponent, FVector& OutLocation)
{
	auto navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (!navSystem)
	{
		return false;
	}

	const auto actorLocation = GetActorLocation();
	const auto radius = SphereComponent->GetScaledSphereRadius();
	const auto collisionShape = FCollisionShape::MakeCapsule(InCapsuleComponent->GetScaledCapsuleRadius(), InCapsuleComponent->GetScaledCapsuleHalfHeight());

	for (int attempt = 0; attempt < MaxAttempts; ++attempt)
	{
		FNavLocation navLocation;
		if (!navSystem->GetRandomReachablePointInRadius(actorLocation, radius, navLocation))
		{
			continue;
		}

		const auto candidateLocation = navLocation.Location;

		if (!IsLocationValid(candidateLocation, collisionShape))
		{
			return false;
		}

		OutLocation = candidateLocation;
		return true;
	}

	return false;
}

bool ACFR_SpawnPoint::IsLocationValid(const FVector& InLocation, const FCollisionShape& InCollisionShape) const
{
	FHitResult hitResult;
	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(this);
	queryParams.AddIgnoredComponent(SphereComponent);

	const auto world = GetWorld();
	const auto collisionRadius = SphereComponent->GetScaledSphereRadius();
	auto location = InLocation;
	location.Z += InCollisionShape.GetCapsuleHalfHeight();

	DrawDebugCapsule(
		world,
		location,
		InCollisionShape.GetCapsuleHalfHeight(),
		InCollisionShape.GetCapsuleRadius(),
		FQuat::Identity,
		FColor::Red,
		false,
		2.0f
	);

	return !world->OverlapBlockingTestByChannel(
		location,
		FQuat::Identity,
		ECC_Pawn,
		InCollisionShape,
		queryParams);
}
