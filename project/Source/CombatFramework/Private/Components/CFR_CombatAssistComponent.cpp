// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CFR_CombatAssistComponent.h"

#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "AbilitySystem/CFR_BlueprintFunctionLibrary.h"
#include "AbilitySystem/CFR_GameplayTags.h"
#include "Characters/CFR_AICharacter.h"
#include "Characters/CFR_CharacterBase.h"
#include "Characters/CFR_PlayerCharacter.h"
#include "Components/CFR_MovementAssistComponent.h"
#include "Components/CFR_TargettingComponent.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
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

	ACFR_PlayerCharacter* PlayerCharacter = Cast<ACFR_PlayerCharacter>(GetOwner());
	if (PlayerCharacter)
	{
		PlayerCharacter->OnAbilitySystemComponentInitialized.AddUObject(this, &UCFR_CombatAssistComponent::HandlePlayerASCInitialized);
	}
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
		if (bShowDebug)
		{
			ShowDebug();
		}

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

void UCFR_CombatAssistComponent::PerformAttackAutoAssist()
{
	ACFR_PlayerCharacter* PlayerCharacter = Cast<ACFR_PlayerCharacter>(GetOwner());
	if (!PlayerCharacter)
		return;

	if (!TargettingComponent.Get())
		return;

	const auto* Target = TargettingComponent.Get()->GetCurrentTarget().Get();
	if (!Target)
		return;

	const FVector PlayerLocation = PlayerCharacter->GetActorLocation();

	const FVector PlayerToEnemyVector = Target->GetActorLocation() - PlayerLocation;
	FRotator Rotation = UKismetMathLibrary::MakeRotFromX(PlayerToEnemyVector);
	Rotation.Pitch = 0.0f;
	Rotation.Roll = 0.0f;

	PlayerCharacter->SetActorRotation(Rotation);

	const float DistanceToEnemy = FVector::Dist(PlayerLocation, Target->GetActorLocation());

	if (DistanceToEnemy > AutoAssistOffsetToEnemy == false)
		return;

	FVector AssistDirection = FVector(PlayerToEnemyVector.X, PlayerToEnemyVector.Y, 0.0f);
	AssistDirection.Normalize();

	AutoAssistMove = DistanceToEnemy - AutoAssistOffsetToEnemy;

	if (AutoAssistMove > MaxAutoassistMove)
	{
		AutoAssistMove = MaxAutoassistMove;
	}
}

void UCFR_CombatAssistComponent::EndAttackAutoAssist()
{
	ACFR_PlayerCharacter* PlayerCharacter = Cast<ACFR_PlayerCharacter>(GetOwner());
	if (!PlayerCharacter)
		return;

	UCharacterMovementComponent* MoveComponent = PlayerCharacter->GetCharacterMovement();
	if (MoveComponent)
	{
		MoveComponent->MaxAcceleration = PreviousMaxAcceleration;
	}
}

void UCFR_CombatAssistComponent::SetAttackMoveDuration(float TotalDuration)
{
	AttackMoveDuration = TotalDuration;
}

void UCFR_CombatAssistComponent::ShowDebug()
{
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), GetOwner()->GetActorLocation() + GetOwner()->GetActorForwardVector() * 200.0f, FColor::Blue, false, -1.0F, 0U, 2.0f);
}

void UCFR_CombatAssistComponent::HandlePlayerASCInitialized(UCFR_AbilitySystemComponent* ASC)
{
	if (auto abilitySystemInterface = Cast<IAbilitySystemInterface>(GetOwner()))
	{
		if (auto ACS = Cast<UCFR_AbilitySystemComponent>(abilitySystemInterface->GetAbilitySystemComponent()))
		{
			// TODO: Unbind.
			ACS->OnMeleeAbilityActivated.AddUObject(this, &UCFR_CombatAssistComponent::HandleMeleeAbilityActivated);
			ACS->OnMeleeAbilityEnded.AddUObject(this, &UCFR_CombatAssistComponent::HandleMeleeAbilityEnded);
		}
	}
}

void UCFR_CombatAssistComponent::HandleMeleeAbilityActivated(UGameplayAbility* GameplayAbility)
{
	auto PlayerCharacter = Cast<ACFR_PlayerCharacter>(GetOwner());

	if (!PlayerCharacter)
		return;
	
	auto MoveComponent = PlayerCharacter->GetCharacterMovement();

	if (MoveComponent)
	{
		PreviousMaxAcceleration = MoveComponent->MaxAcceleration;
		MoveComponent->MaxAcceleration = 999999999.0f;
	}

	PerformAttackAutoAssist();
}

void UCFR_CombatAssistComponent::HandleMeleeAbilityEnded(UGameplayAbility* GameplayAbility)
{
	EndAttackAutoAssist();
}
