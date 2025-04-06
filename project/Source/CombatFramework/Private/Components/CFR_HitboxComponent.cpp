// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CFR_HitboxComponent.h"
#include "Components/ShapeComponent.h"
#include "Characters/CFR_CharacterBase.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"
#include "GenericTeamAgentInterface.h"

UCFR_HitboxComponent::UCFR_HitboxComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UCFR_HitboxComponent::BeginPlay()
{
	Super::BeginPlay();

	// TODO: Try to attach the colliders in the editor instead of begin play.
	// Get references to all children colliders (colliders that represent the hitbox).
	TArray<USceneComponent*> Children;
	GetChildrenComponents(false, Children);
	for (USceneComponent* Child : Children)
	{
		UShapeComponent* ShapeComponent = Cast<UShapeComponent>(Child);
		if (ShapeComponent)
		{
			Shapes.Add(ShapeComponent);
		}
	}

	// Delegate Shape OnComponentBeginOverlap to custom OnComponentOverlap.
	for (UShapeComponent* Shape : Shapes)
	{
		Shape->OnComponentBeginOverlap.AddDynamic(this, &UCFR_HitboxComponent::OnComponentOverlap);
	}

	DeactivateHitbox();
}

void UCFR_HitboxComponent::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	for (UShapeComponent* Shape : Shapes)
	{
		Shape->OnComponentBeginOverlap.RemoveDynamic(this, &UCFR_HitboxComponent::OnComponentOverlap);
	}
}

void UCFR_HitboxComponent::OnComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Should not be hardcoded to hostile. An ability should be able to activate a hitbox especifying whose the target.
	ETeamAttitude::Type Attitude = FGenericTeamId::GetAttitude(this->GetOwner(), OtherActor);
	if (Attitude == ETeamAttitude::Hostile)
	{
		// If checks are passed, handle the collision.
		HandleOverlappedActor(OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	}
}

void UCFR_HitboxComponent::HandleOverlappedActor(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleOverlappedActor"));
	SendCollisionEvents(OtherActor);
}

void UCFR_HitboxComponent::ActivateHitbox()
{
	for (UShapeComponent* Shape : Shapes)
	{
		Shape->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
}

void UCFR_HitboxComponent::DeactivateHitbox()
{
	for (UShapeComponent* Shape : Shapes)
	{
		Shape->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void UCFR_HitboxComponent::SetEffectTag(FGameplayTag Tag)
{
	EffectTag = Tag;
}

FGameplayTag UCFR_HitboxComponent::GetEffectTag() const
{
	return EffectTag;
}

void UCFR_HitboxComponent::SendCollisionEvents(AActor* TargetActor)
{
	const AActor* Owner = GetOwner();
	const ACFR_CharacterBase* OwnerCharacter = Cast<ACFR_CharacterBase>(Owner);
	
	if (OwnerCharacter)
	{
		UAbilitySystemComponent* OwnerASC = OwnerCharacter->GetAbilitySystemComponent();
		if (OwnerASC)
		{
			FGameplayEventData* EventData = new FGameplayEventData();
			EventData->Instigator = OwnerCharacter;
			EventData->Target = TargetActor;

			// TODO: Send a unique event for all the actors hit.
			OwnerASC->HandleGameplayEvent(EffectTag, EventData);
		}
	}
}

