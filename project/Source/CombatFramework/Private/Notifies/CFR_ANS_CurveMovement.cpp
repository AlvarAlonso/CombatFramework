// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/CFR_ANS_CurveMovement.h"

#include "Characters/CFR_CharacterBase.h"
#include "Components/CFR_CombatAssistComponent.h"
#include "Components/CFR_MovementAssistComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

void UCFR_ANS_CurveMovement::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	AActor* Owner = MeshComp->GetOwner();

	if (UCFR_MovementAssistComponent* MoveAssistComp = Cast<UCFR_MovementAssistComponent>(Owner->GetComponentByClass(UCFR_MovementAssistComponent::StaticClass())))
	{
		const FVector forwardVector = Owner->GetActorForwardVector();
		const float Speed = GetSpeed(MeshComp);

		MoveAssistComp->SetDirection(FVector(0.0, 0.0, 0.0));
		MoveAssistComp->SetMagnitudeAndSpeed(Magnitude, Speed);
		MoveAssistComp->SetEnableMovementAssist(true);
	}

	if (UCFR_CombatAssistComponent* CombatAssistComp = Cast<UCFR_CombatAssistComponent>(Owner->GetComponentByClass(UCFR_CombatAssistComponent::StaticClass())))
	{
		CombatAssistComp->SetAttackMoveDuration(TotalDuration);
	}
}

void UCFR_ANS_CurveMovement::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	if (bUseTick)
	{
		AActor* Owner = MeshComp->GetOwner();
		const float Speed = GetSpeed(MeshComp);

		if (UCFR_MovementAssistComponent* MoveAssistComp = Cast<UCFR_MovementAssistComponent>(Owner->GetComponentByClass(UCFR_MovementAssistComponent::StaticClass())))
		{
			MoveAssistComp->SetMagnitudeAndSpeed(Magnitude, Speed);
		}
	}
}

void UCFR_ANS_CurveMovement::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	AActor* Owner = MeshComp->GetOwner();

	if (UCFR_MovementAssistComponent* MoveAssistComp = Cast<UCFR_MovementAssistComponent>(Owner->GetComponentByClass(UCFR_MovementAssistComponent::StaticClass())))
	{
		MoveAssistComp->SetEnableMovementAssist(false);
	}
}

float UCFR_ANS_CurveMovement::GetSpeed(USkeletalMeshComponent* MeshComp) const
{
	if (UAnimInstance* AnimInstance = MeshComp->GetAnimInstance())
	{
		if (ACFR_CharacterBase* CharacterBase = Cast<ACFR_CharacterBase>(MeshComp->GetOwner()))
		{
			float Speed = AnimInstance->GetCurveValue(FName("Speed"));

			// TODO: Should be IsFallingDown();
			if (CharacterBase->GetMovementComponent()->IsFalling())
			{
				Speed *= AirMultiplier;
			}

			return Speed;
		}
	}

	return 0.0f;
}
