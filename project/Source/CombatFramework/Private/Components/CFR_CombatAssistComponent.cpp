// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CFR_CombatAssistComponent.h"

#include "AbilitySystem/CFR_BlueprintFunctionLibrary.h"
#include "AbilitySystem/CFR_GameplayTags.h"
#include "Characters/CFR_AICharacter.h"
#include "Characters/CFR_CharacterBase.h"
#include "Components/CFR_MovementAssistComponent.h"
#include "Components/CFR_TargettingComponent.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"

UCFR_CombatAssistComponent::UCFR_CombatAssistComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	AutoAssistDot = 0.5f;
	AutoAssistOffsetToEnemy = 200.0f;
	MaxAutoassistMove = 200.0f;
	AttackOffsetToEnemy = 150.0f;
}

void UCFR_CombatAssistComponent::BeginPlay()
{
	Super::BeginPlay();

	MovementAssistComponent = GetOwner()->FindComponentByClass<UCFR_MovementAssistComponent>();
	TargettingComponent = GetOwner()->FindComponentByClass<UCFR_TargettingComponent>();
}

void UCFR_CombatAssistComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ACFR_CharacterBase* CharacterBase = Cast<ACFR_CharacterBase>(GetOwner());
	if (!CharacterBase)
		return;

	UCharacterMovementComponent* MoveComponent = CharacterBase->GetCharacterMovement();
	if (!MoveComponent || !CharacterBase->GetAbilitySystemComponent())
		return;
	
	if (!MovementAssistComponent.Get() || !TargettingComponent.Get())
		return;

	if (MovementAssistComponent.Get()->GetEnableMovementAssist())
	{
		const auto* Target = TargettingComponent.Get()->GetCurrentTarget().Get();
		const bool bIsAttacking = CharacterBase->GetAbilitySystemComponent()->HasMatchingGameplayTag(FCFR_GameplayTags::Get().Status_Attacking);
		if (bIsAttacking && Target)
		{
			MovementAssistComponent.Get()->SetEnableMovementAssist(false);
			const FVector MoveVectorDirection = CharacterBase->GetActorForwardVector();
			const float DistanceToTarget = FVector::Distance(CharacterBase->GetActorLocation(), Target->GetActorLocation());
			if (DistanceToTarget > AutoAssistOffsetToEnemy)
			{
				const float NewMoveSpeed = MovementAssistComponent.Get()->GetMovementSpeed() + AutoAssistMove / AttackMoveDuration;
				const FVector NewLocation = CharacterBase->GetActorLocation() + MoveVectorDirection * NewMoveSpeed * DeltaTime;

				// TODO: Should AssistComponent override MovementAssistComponent funcionality or just extend it?
				// Maybe it should override it as long as there is a target.
				if (MoveComponent->IsFalling())
				{
					CharacterBase->SetActorLocation(NewLocation, true);
				}
				else
				{
					CharacterBase->AddMovementInput(MoveVectorDirection, NewMoveSpeed);
				}
			}
			else if (DistanceToTarget > AttackOffsetToEnemy)
			{
				// TODO: Instead of calculating total move left, calculate speed and apply it only if it does not reach the minimum offset
				const float TotalMoveLeft = AttackMoveDurationLeft * MoveVectorSpeed;
				const float MaxMove = DistanceToTarget - AttackOffsetToEnemy;

				if (TotalMoveLeft <= MaxMove)
				{
					if (MoveComponent->IsFalling())
					{
						const FVector NewLocation = CharacterBase->GetActorLocation() + MoveVectorDirection * MoveVectorSpeed * DeltaTime;
						CharacterBase->SetActorLocation(NewLocation, true);

					}
					else
					{
						CharacterBase->AddMovementInput(MoveVectorDirection, MoveVectorSpeed);
					}
				}
			}
		}
		else
		{
			// Movement Assist.
			MovementAssistComponent.Get()->SetEnableMovementAssist(true);
		}
	}

	AttackMoveDurationLeft -= DeltaTime;
}
