// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CFR_BlueprintFunctionLibrary.h"

#include "Characters/CFR_AICharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

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
