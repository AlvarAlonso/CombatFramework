// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CFR_InteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCFR_InteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COMBATFRAMEWORK_API ICFR_InteractionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Interact(AActor* ActorInteracting);
	virtual void Interact_Implementation(AActor* ActorInteracting) {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartCanInteract(AActor* ActorInteracting);
	virtual void StartCanInteract_Implementation(AActor* ActorInteracting) {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StopCanInteract(AActor* ActorInteracting);
	virtual void StopCanInteract_Implementation(AActor* ActorInteracting) {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanBeInteractedWith(AActor* ActorInteracting);
	virtual bool CanBeInteractedWith_Implementation(AActor* ActorInteracting) { return true; };
};
