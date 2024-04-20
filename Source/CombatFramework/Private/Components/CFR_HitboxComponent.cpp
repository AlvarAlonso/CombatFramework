// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CFR_HitboxComponent.h"
#include "Components/ShapeComponent.h"

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
	// TODO: Here goes the checks.

	// If checks are passed, handle the collision.
	HandleOverlappedActor(OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void UCFR_HitboxComponent::HandleOverlappedActor(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleOverlappedActor"));
}


void UCFR_HitboxComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCFR_HitboxComponent::ActivateHitbox(bool bActivateEffect)
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

