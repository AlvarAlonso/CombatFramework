// Fill out your copyright notice in the Description page of Project Settings.
#include "Characters/CFR_PeasantAnimInstance.h"

#include "KismetAnimationLibrary.h"

#include "Characters/CFR_AICharacter.h"

void UCFR_PeasantAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	AICharacter = Cast<ACFR_AICharacter>(TryGetPawnOwner());
}

void UCFR_PeasantAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (AICharacter == nullptr)
	{
		AICharacter = Cast<ACFR_AICharacter>(TryGetPawnOwner());
	}

	if (AICharacter == nullptr)
	{
		return;
	}

	const auto Velocity = AICharacter->GetVelocity();
	MovementSpeed = Velocity.Size2D();

	CharacterDirection = UKismetAnimationLibrary::CalculateDirection(Velocity, AICharacter->GetActorRotation());
}
