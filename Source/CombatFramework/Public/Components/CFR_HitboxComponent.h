// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CFR_HitboxComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCFR_HitboxOverlapDelegate, class AActor*, HitActor);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATFRAMEWORK_API UCFR_HitboxComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UCFR_HitboxComponent();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

private:
	UFUNCTION(BlueprintCallable)
	void OnComponentOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	void HandleOverlappedActor(AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Activate hitbox for detecting overlaps and set collision preset to dodgeable. */
	UFUNCTION(BlueprintCallable)
	void ActivateHitbox(bool bActivateEffect);

	/** Deactivate hitbox. */
	UFUNCTION(BlueprintCallable)
	void DeactivateHitbox();

public:
	FCFR_HitboxOverlapDelegate OnHitboxOverlap;

protected:
	/** All shapes forming the hitbox component. */
	UPROPERTY()
	TArray<UShapeComponent*> Shapes;

};
