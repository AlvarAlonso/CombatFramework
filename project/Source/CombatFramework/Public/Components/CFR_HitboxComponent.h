// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameplayTagContainer.h"
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
	/** Activate hitbox for detecting overlaps and set collision preset to dodgeable. */
	UFUNCTION(BlueprintCallable)
	void ActivateHitbox();

	/** Deactivate hitbox. */
	UFUNCTION(BlueprintCallable)
	void DeactivateHitbox();

	/** Set the event tag to be sent when the hitbox hits a target actor. */
	UFUNCTION(BlueprintCallable)
	void SetEffectTag(FGameplayTag Tag);

	/** Get the event tag to be sent when the hitbox hits a target actor. */

	UFUNCTION(BlueprintCallable)
	FGameplayTag GetEffectTag() const;

protected:
	void SendCollisionEvents(AActor* TargetActor);

public:
	FCFR_HitboxOverlapDelegate OnHitboxOverlap;

protected:
	/** All shapes forming the hitbox component. */
	UPROPERTY()
	TArray<UShapeComponent*> Shapes;

	/* EffectTag to apply when hitting. */
	FGameplayTag EffectTag;

};
