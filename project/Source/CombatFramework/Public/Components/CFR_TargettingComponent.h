// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CFR_TargettingComponent.generated.h"

class ACFR_CharacterBase;
class ACFR_AICharacter;

USTRUCT()
struct FCFR_ActorAngle
{
	GENERATED_BODY();

public:

	AActor* Actor = nullptr;
	float Angle;
};

FORCEINLINE bool operator< (const FCFR_ActorAngle& lhs, const FCFR_ActorAngle& rhs)
{
	return lhs.Angle < rhs.Angle;
}

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATFRAMEWORK_API UCFR_TargettingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCFR_TargettingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TWeakObjectPtr<ACFR_CharacterBase> GetCurrentTarget() const;

	UPROPERTY(EditAnywhere)
	bool bShowDebug = false;

private:
	void UpdateTarget();
	TArray<AActor*> GetClosestTargetsInRange(const float Range, const bool bSameFallingState) const;
	ACFR_AICharacter* GetFrontTarget(const TArray<AActor*>& Enemies, const float AngleDiscardThreshHold = 180.0f) const;
	void SetNewTarget(ACFR_AICharacter* NewTarget);
	void ShowDebug();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float AutoAssistCloseRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float AutoAssistMaxRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float MaxRadiusAngleDiscard;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float TargettingZTopOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float TargettingZBottomOffset;

	/* Enemies at that angle from player's forward will be checked against the camera frustum to discard
	the ones outside */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float CheckCameraAngle;

	uint32 NumEnemiesInsideFrustum = 0;

	TWeakObjectPtr<ACFR_CharacterBase> CurrentTarget;
};
