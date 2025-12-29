// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/CFR_ANS_CurveMovement.h"

#include "Characters/CFR_CharacterBase.h"
#include "Components/CFR_CombatAssistComponent.h"
#include "Components/CFR_MovementAssistComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

void UCFR_ANS_CurveMovement::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	auto owner = MeshComp->GetOwner();

	if (!owner)
	{
		return;
	}

	if (auto moveAssistComponent = Cast<UCFR_MovementAssistComponent>(owner->GetComponentByClass(UCFR_MovementAssistComponent::StaticClass())))
	{
		const float speed = GetSpeed(MeshComp);

		moveAssistComponent->SetDirection(FVector(0.0, 0.0, 0.0));
		moveAssistComponent->SetMagnitudeAndSpeed(Magnitude, speed);
		moveAssistComponent->SetEnableMovementAssist(true);
	}

	if (auto combatAssistComponent = Cast<UCFR_CombatAssistComponent>(owner->GetComponentByClass(UCFR_CombatAssistComponent::StaticClass())))
	{
		combatAssistComponent->SetAttackMoveDuration(TotalDuration);
	}
}

void UCFR_ANS_CurveMovement::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	auto owner = MeshComp->GetOwner();

	if (!bUseTick || !owner)
	{
		return;
	}

	if (auto moveAssistComponent = Cast<UCFR_MovementAssistComponent>(owner->GetComponentByClass(UCFR_MovementAssistComponent::StaticClass())))
	{
		const float speed = GetSpeed(MeshComp);
		moveAssistComponent->SetMagnitudeAndSpeed(Magnitude, speed);
	}
}

void UCFR_ANS_CurveMovement::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	auto owner = MeshComp->GetOwner();

	if (!owner)
	{
		return;
	}

	if (auto moveAssistComponent = Cast<UCFR_MovementAssistComponent>(owner->GetComponentByClass(UCFR_MovementAssistComponent::StaticClass())))
	{
		moveAssistComponent->SetEnableMovementAssist(false);
	}
}

float UCFR_ANS_CurveMovement::GetSpeed(USkeletalMeshComponent* InMeshComponent) const
{
	if (auto animationInstance = InMeshComponent->GetAnimInstance())
	{
		if (auto characterBase = Cast<ACFR_CharacterBase>(InMeshComponent->GetOwner()))
		{
			float speed = animationInstance->GetCurveValue(FName("Speed"));

			// TODO: Should be IsFallingDown();
			if (characterBase->GetMovementComponent()->IsFalling())
			{
				speed *= AirMultiplier;
			}

			return speed;
		}
	}

	return 0.0f;
}
