// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CFR_MovementAssistComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATFRAMEWORK_API UCFR_MovementAssistComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCFR_MovementAssistComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ForwardMagnitude = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 1.0f;

private:
	FVector GoalPoint = FVector(0.0f);
	FVector Direction = FVector(0.0f);
	float DistanceToGoalPoint = 0.0f;
	bool bIsMoving = false;
	float AcceptanceRadius;

protected:
	void Move(float DeltaTime);
	bool ArrivedToGoalLocation();

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetDirection(const FVector NewDirection);

	UFUNCTION(BlueprintCallable)
	void SetMagnitudeAndSpeed(float Magnitude, float Speed);

	UFUNCTION(BlueprintCallable)
	void SetEnableMovementAssist(bool bEnable);
};
