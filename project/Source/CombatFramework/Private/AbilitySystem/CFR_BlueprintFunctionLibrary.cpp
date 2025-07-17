// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CFR_BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"

void UCFR_BlueprintFunctionLibrary::RotateDirectlyTowardsActor(AActor* Source, const AActor* Target, bool bFaceBackwards)
{
	const FRotator selfRotation = Source->GetActorRotation();

	const FVector selfLocation = Source->GetActorLocation();
	const FVector targetLocation = Target->GetActorLocation();
	const FRotator lookRotation = UKismetMathLibrary::FindLookAtRotation(selfLocation, targetLocation);

	const FRotator desiredRotation = FRotator(selfRotation.Pitch, bFaceBackwards ? lookRotation.Yaw + 180.0f : lookRotation.Yaw, selfRotation.Roll);

	Source->SetActorRotation(desiredRotation);
}
