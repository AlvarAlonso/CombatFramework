// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CFR_BlueprintFunctionLibrary.h"

#include "Actors/Projectiles/CFR_Projectile.h"
#include "Characters/CFR_AICharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "PhysicsEngine/PhysicsSettings.h"

void UCFR_BlueprintFunctionLibrary::RotateDirectlyTowardsActor(AActor* Source, const AActor* Target, bool bFaceBackwards)
{
	const FRotator selfRotation = Source->GetActorRotation();

	const FVector selfLocation = Source->GetActorLocation();
	const FVector targetLocation = Target->GetActorLocation();
	const FRotator lookRotation = UKismetMathLibrary::FindLookAtRotation(selfLocation, targetLocation);

	const FRotator desiredRotation = FRotator(selfRotation.Pitch, bFaceBackwards ? lookRotation.Yaw + 180.0f : lookRotation.Yaw, selfRotation.Roll);

	Source->SetActorRotation(desiredRotation);
}

bool UCFR_BlueprintFunctionLibrary::IsInFrustum(const ACFR_AICharacter* Character)
{
	ULocalPlayer* LocalPlayer = Character->GetWorld()->GetFirstLocalPlayerFromController();
	if (LocalPlayer != nullptr && LocalPlayer->ViewportClient != nullptr && LocalPlayer->ViewportClient->Viewport)
	{
		FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
			LocalPlayer->ViewportClient->Viewport,
			Character->GetWorld()->Scene,
			LocalPlayer->ViewportClient->EngineShowFlags)
			.SetRealtimeUpdate(true));

		FVector ViewLocation;
		FRotator ViewRotation;
		FSceneView* SceneView = LocalPlayer->CalcSceneView(&ViewFamily, ViewLocation, ViewRotation, LocalPlayer->ViewportClient->Viewport);
		if (SceneView != nullptr)
		{
			return SceneView->ViewFrustum.IntersectSphere(
				Character->GetActorLocation(), Character->GetSimpleCollisionRadius());
		}
	}

	return false;
}

bool UCFR_BlueprintFunctionLibrary::IsGonnaHitGround(const AActor* Actor, const float Distance)
{
	const FVector TraceStart = Actor->GetActorLocation();
	const FVector TraceEnd = TraceStart - FVector(0.0f, 0.0f, Distance);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));

	const TArray<AActor*> ActorsToIgnore;
	FHitResult OutHit;
	UWorld* World = Actor->GetWorld();

	return UKismetSystemLibrary::LineTraceSingleForObjects(
		World, TraceStart, TraceEnd, ObjectTypes, false, ActorsToIgnore,
		EDrawDebugTrace::ForDuration, OutHit, true, FLinearColor::Red, FLinearColor::Green, 3.0f);
}

ACFR_Projectile* UCFR_BlueprintFunctionLibrary::SpawnProjectile(UWorld* World, const TSubclassOf<ACFR_Projectile> ProjectileToSpawn, const FTransform SpawnTransform, AActor* Instigator, const FGenericTeamId TeamId)
{
	check(World);
	ACFR_Projectile* Projectile = World->SpawnActor<ACFR_Projectile>(ProjectileToSpawn, SpawnTransform);
	if (Projectile)
	{
		Projectile->SetGenericTeamId(TeamId);
		Projectile->Instigator = Instigator;
	}

	return Projectile;
}

void UCFR_BlueprintFunctionLibrary::LaunchCharacterToLocation(ACFR_CharacterBase* CharacterBase, const FVector& TargetLocation, float GravityScaleMultiplier, float LaunchAngle)
{
	if (CharacterBase == nullptr) return;

	const FVector CurrentLocation = CharacterBase->GetActorLocation();

	const float HorizontalDistance = FVector::Distance(FVector(CurrentLocation.X, CurrentLocation.Y, 0.0f), FVector(TargetLocation.X, TargetLocation.Y, 0.0f));
	const float PhysicsSettingsGravity = UPhysicsSettings::Get()->DefaultGravityZ;
	float CharacterGravityScale = 1.0f;

	UCharacterMovementComponent* CharacterMovementComponent = CharacterBase->GetCharacterMovement();
	if (CharacterMovementComponent)
	{
		CharacterMovementComponent->GravityScale *= GravityScaleMultiplier;
		CharacterGravityScale = CharacterMovementComponent->GravityScale;
	}
	else
	{
		CharacterGravityScale = 3.0f; // TODO: This should be a project global constant.
	}

	const float Gravity = PhysicsSettingsGravity * CharacterGravityScale;
	const float Sin = FMath::Sin(LaunchAngle * 2.0f);

	const float Velocity = FMath::Sqrt((HorizontalDistance * FMath::Abs(Gravity)) / FMath::Abs(Sin));

	const float xVelocity = Velocity * FMath::Abs(FMath::Sin(LaunchAngle));
	const float zVelocity = Velocity * FMath::Abs(FMath::Cos(LaunchAngle));

	FVector Direction = TargetLocation - CurrentLocation;
	Direction.Z = 0.0f;
	Direction.Normalize();
	const FVector HorizontalLaunchForce = Direction * xVelocity;

	const FVector LaunchVelocity = FVector(HorizontalLaunchForce.X, HorizontalLaunchForce.Y, zVelocity);

	CharacterBase->LaunchCharacter(LaunchVelocity, true, true);
}
