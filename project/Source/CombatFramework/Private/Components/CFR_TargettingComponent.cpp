// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CFR_TargettingComponent.h"
#include "AbilitySystem/CFR_BlueprintFunctionLibrary.h"
#include "AbilitySystem/CFR_GameplayTags.h"
#include "Characters/CFR_AICharacter.h"
#include "Characters/CFR_CharacterBase.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"

UCFR_TargettingComponent::UCFR_TargettingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	AutoAssistCloseRadius = 300.0f;
	AutoAssistMaxRadius = 1000.0f;
	MaxRadiusAngleDiscard = 90.0f;
	TargettingZTopOffset = 200.0f;
	TargettingZBottomOffset = 50.0f;
	CheckCameraAngle = 30.0f;
}


void UCFR_TargettingComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UCFR_TargettingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bShowDebug)
	{
		ShowDebug();
	}

	NumEnemiesInsideFrustum = 0;

	UpdateTarget();
}

TWeakObjectPtr<ACFR_CharacterBase> UCFR_TargettingComponent::GetCurrentTarget() const
{
	return CurrentTarget;
}

void UCFR_TargettingComponent::UpdateTarget()
{
	// TODO: Use combat or target interface. Not necessarily all AICharacter should be enemies
	// and not necessarily all enemies are AICharacter.

	ACFR_AICharacter* NewTarget = nullptr;

	// We check first in a close range.
	TArray<AActor*> PotentialTargets = GetClosestTargetsInRange(AutoAssistCloseRadius, true);
	NewTarget = GetFrontTarget(PotentialTargets);

	for (AActor* Actor : PotentialTargets)
	{
		ACFR_AICharacter* PotentialTarget = Cast<ACFR_AICharacter>(Actor);
		if (UCFR_BlueprintFunctionLibrary::IsInFrustum(PotentialTarget))
		{
			NumEnemiesInsideFrustum++;
		}
	}

	if (NewTarget)
	{
		SetNewTarget(NewTarget);
		return;
	}

	// Check in a longer range.
	PotentialTargets = GetClosestTargetsInRange(AutoAssistMaxRadius, true);
	NewTarget = GetFrontTarget(PotentialTargets, MaxRadiusAngleDiscard);

	if (NewTarget)
	{
		SetNewTarget(NewTarget);
	}
	else if (CurrentTarget.IsValid())
	{
		SetNewTarget(nullptr);
	}
}

TArray<AActor*> UCFR_TargettingComponent::GetClosestTargetsInRange(const float Range, const bool bSameFallingState) const
{
	// Check nearby potential targets
	// TODO: Do not check this every frame.
	AActor* PlayerActor = GetOwner();
	const FVector PlayerLocation = PlayerActor->GetActorLocation();

	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypes;
	TraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	UClass* SeekClass = ACFR_AICharacter::StaticClass();

	TArray<AActor*> IgnoreActors;
	TArray<AActor*> OutActors;

	// Check for nearby targets
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), PlayerLocation, Range, TraceObjectTypes, SeekClass, IgnoreActors, OutActors);

	if (bSameFallingState == false)
		return OutActors;

	// Discard targets that are in a different falling state that the player
	const ACharacter* PlayerCharacter = Cast<ACharacter>(PlayerActor);
	const bool bIsPlayerInAir = PlayerCharacter->GetCharacterMovement()->IsFalling();

	TArray<AActor*> ClosestTargets;
	for (AActor* OutActor : OutActors)
	{
		ACFR_AICharacter* OutTarget = Cast<ACFR_AICharacter>(OutActor);
		UAbilitySystemComponent* TargetACS = OutTarget->FindComponentByClass<UAbilitySystemComponent>();

		if (TargetACS->HasMatchingGameplayTag(FCFR_GameplayTags::Get().Status_Dead))
			continue;

		// If player and target on ground, add target to potential targets
		if (OutTarget->GetCharacterMovement()->IsFalling() == false &&
			bIsPlayerInAir == false)
		{
			ClosestTargets.Add(OutActor);
			continue;
		}

		// If one or both are in the air, add to potential targets if it is inside some Z offset
		float PlayerZLocation = PlayerLocation.Z;
		float TargetZLocation = OutTarget->GetActorLocation().Z;

		if (TargetZLocation > PlayerZLocation - TargettingZBottomOffset &&
			TargetZLocation < PlayerZLocation + TargettingZTopOffset)
		{
			ClosestTargets.Add(OutActor);
		}
	}

	return ClosestTargets;
}

ACFR_AICharacter* UCFR_TargettingComponent::GetFrontTarget(const TArray<AActor*>& Enemies, const float AngleDiscardThreshHold) const
{
	if (Enemies.IsEmpty())
	{
		return nullptr;
	}

	const AActor* PlayerActor = GetOwner();
	const FVector PlayerLocation = PlayerActor->GetActorLocation();
	const FVector PlayerForward = PlayerActor->GetActorForwardVector();

	ACFR_AICharacter* FrontTarget = nullptr;
	TArray<FCFR_ActorAngle> FrontTargets;
	float SmallestAngle = INFINITY;
	for (AActor* Actor : Enemies)
	{
		const FVector EnemyLocation = Actor->GetActorLocation();
		FVector EnemyDirection = EnemyLocation - PlayerLocation;
		EnemyDirection.Z = 0.0f;
		EnemyDirection.Normalize();

		const float OrientationToEnemy = -atan2f(EnemyDirection.Y, EnemyDirection.X);
		const float EnemyDeg = FMath::RadiansToDegrees(OrientationToEnemy);

		const FVector ForwardPoint = PlayerForward;
		const float OrientationToForward = -atan2f(ForwardPoint.Y, ForwardPoint.X);
		const float ForwardDeg = FMath::RadiansToDegrees(OrientationToForward);

		float Angle = FMath::RadiansToDegrees(OrientationToForward) - FMath::RadiansToDegrees(OrientationToEnemy);

		const float OrientationSum = FMath::Abs(FMath::RadiansToDegrees(OrientationToForward)) + FMath::Abs(FMath::RadiansToDegrees(OrientationToEnemy));

		if (OrientationSum > 180.0f)
		{
			float fAngle = ForwardDeg > 0 ? ForwardDeg : 360.0f + ForwardDeg;
			float eAngle = EnemyDeg > 0 ? EnemyDeg : 360.0f + EnemyDeg;

			Angle = fAngle - eAngle;
		}

		const float AbsAngle = FMath::Abs(Angle);

		if (AbsAngle > AngleDiscardThreshHold)
			continue;

		if (AbsAngle < SmallestAngle)
		{
			SmallestAngle = AbsAngle;
			FrontTarget = Cast<ACFR_AICharacter>(Actor);
		}

		FCFR_ActorAngle ActorAngle;
		ActorAngle.Actor = Actor;
		ActorAngle.Angle = AbsAngle;
		FrontTargets.Add(ActorAngle);
	}

	if (FrontTargets.IsEmpty())
		return nullptr;

	if (FrontTargets.Num() == 1)
		return FrontTarget;

	if (UCFR_BlueprintFunctionLibrary::IsInFrustum(FrontTarget))
		return FrontTarget;

	FrontTargets.Sort();

	for (int32 i = 1; i < FrontTargets.Num(); ++i)
	{
		ACFR_AICharacter* PotentialTarget = Cast<ACFR_AICharacter>(FrontTargets[i].Actor);

		if (UCFR_BlueprintFunctionLibrary::IsInFrustum(PotentialTarget) && FrontTargets[i].Angle < CheckCameraAngle == true)
		{
			return PotentialTarget;
		}
	}

	return FrontTarget;
}

void UCFR_TargettingComponent::SetNewTarget(ACFR_AICharacter* NewTarget)
{
	if (CurrentTarget == NewTarget)
		return;

	if (CurrentTarget.IsValid())
	{
		// TODO: Use a combat interface. We should not be interacting with specific character classes.
		if (auto AICharacter = Cast<ACFR_AICharacter>(CurrentTarget))
		{
			AICharacter->SetCombatTargetWidgetVisibility(false);
		}
	}

	if (NewTarget)
	{
		NewTarget->SetCombatTargetWidgetVisibility(true);
	}

	CurrentTarget = NewTarget;
}

void UCFR_TargettingComponent::ShowDebug()
{
	DrawDebugCircle(GetWorld(), GetOwner()->GetActorLocation(), AutoAssistCloseRadius, 24, FColor::Red, false, -1.0F, 0U, 1.0f, FVector(1.0f, 0.0f, 0.0f), FVector(0.0f, 1.0f, 0.0f), true);
}