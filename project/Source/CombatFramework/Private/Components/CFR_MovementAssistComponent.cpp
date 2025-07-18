// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CFR_MovementAssistComponent.h"

UCFR_MovementAssistComponent::UCFR_MovementAssistComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	AcceptanceRadius = 10.0f;
}

void UCFR_MovementAssistComponent::Move(float DeltaTime)
{
	AActor* Owner = GetOwner();
	const FVector NewLocation = Owner->GetActorLocation() + Direction * DeltaTime * MovementSpeed;
	Owner->SetActorLocation(NewLocation, true);
}

bool UCFR_MovementAssistComponent::ArrivedToGoalLocation()
{
	const AActor* Owner = GetOwner();
	const float DistanceToGoal = FVector::Distance(Owner->GetActorLocation(), GoalPoint);
	if (DistanceToGoal < AcceptanceRadius)
	{
		return true;
	}

	return false;
}


void UCFR_MovementAssistComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bIsMoving)
		return;

	if (ArrivedToGoalLocation())
	{
		bIsMoving = false;
		return;
	}

	Move(DeltaTime);
}

void UCFR_MovementAssistComponent::SetDirection(const FVector NewDirection)
{
	Direction = NewDirection;
}

void UCFR_MovementAssistComponent::SetMagnitudeAndSpeed(float Magnitude, float Speed)
{
	ForwardMagnitude = Magnitude;

	MovementSpeed = Speed;
	AActor* Owner = GetOwner();
	if (Owner == nullptr) return;

	if (Direction == FVector(0.0f))
		Direction = Owner->GetActorForwardVector();
	GoalPoint = Owner->GetActorLocation() + Direction * ForwardMagnitude;
}

void UCFR_MovementAssistComponent::SetEnableMovementAssist(bool bEnable)
{
	bIsMoving = bEnable;
}
