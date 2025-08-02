// Fill out your copyright notice in the Description page of Project Settings.
#include "Components/CFR_InteractionComponent.h"

#include "Components/WidgetComponent.h"
#include "Kismet/KismetSystemLibrary.h"

#include "Interfaces/CFR_InteractionInterface.h"

UCFR_InteractionComponent::UCFR_InteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCFR_InteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	HideInteractWidget();
}

void UCFR_InteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Test a sphere with objects

	AActor* Owner = GetOwner();

	const FVector OwnerLocation = Owner->GetActorLocation();
	const FVector OverlapLocation = OwnerLocation - FVector(0.0f, 0.0f, ZOffset);

	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypes;
	TraceObjectTypes.Add(InteractableObjectType);

	TArray<AActor*> IgnoreActors;

	TArray<AActor*> OutActors;

	bool bHitAnything = UKismetSystemLibrary::SphereOverlapActors(
		GetWorld(), OverlapLocation, Radius, TraceObjectTypes, nullptr, IgnoreActors, OutActors);

	TWeakObjectPtr<AActor> NewActor = nullptr;
	ICFR_InteractionInterface* NewInteract = nullptr;

	for (AActor* HitActor : OutActors)
	{
		if (HitActor->Implements<UCFR_InteractionInterface>())
		{
			bool bCanInteract = ICFR_InteractionInterface::Execute_CanBeInteractedWith(HitActor, Owner);
			if (bCanInteract == true)
			{
				NewActor = HitActor;
				break;
			}
		}
	}

	// Did we change anything?
	if (NewActor == CurrentActor)
	{
		if (NewActor == nullptr)
		{
			HideInteractWidget();
		}

		return;
	}

	// Notify the old actor, we no longer want to interact with him
	if (CurrentActor.IsValid())
	{
		if (CurrentActor->Implements<UCFR_InteractionInterface>())
		{
			ICFR_InteractionInterface::Execute_StopCanInteract(CurrentActor.Get(), Owner);
		}

		CurrentActor = nullptr;
	}

	// If we have something to interact with, notify it to the actor
	if (NewActor.IsValid())
	{
		CurrentActor = NewActor;
		ICFR_InteractionInterface::Execute_StartCanInteract(NewActor.Get(), Owner);
	}
}

void UCFR_InteractionComponent::TryToInteract()
{
	// If CurrentActor is null, CurrentInteract will return null
	if (CurrentActor == nullptr) return;

	if (CurrentActor->Implements<UCFR_InteractionInterface>())
	{
		ICFR_InteractionInterface::Execute_Interact(CurrentActor.Get(), GetOwner());
	}
}

void UCFR_InteractionComponent::ShowInteractWidget()
{
	InteractWidgetComponent->SetVisibility(true);
}

void UCFR_InteractionComponent::HideInteractWidget()
{
	InteractWidgetComponent->SetVisibility(false);
}

void UCFR_InteractionComponent::SetInteractionText(const FText& InteractionText)
{

}

