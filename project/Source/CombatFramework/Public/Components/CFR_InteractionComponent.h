// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CFR_InteractionComponent.generated.h"

class UWidgetComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATFRAMEWORK_API UCFR_InteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCFR_InteractionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TryToInteract();

	UFUNCTION(BlueprintCallable)
	void ShowInteractWidget();

	UFUNCTION(BlueprintCallable)
	void HideInteractWidget();

	UFUNCTION(BlueprintCallable)
	void SetInteractionText(const FText& InteractionText);

protected:
	UWidgetComponent* InteractWidgetComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient)
	TWeakObjectPtr<AActor> CurrentActor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Radius = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float ZOffset = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<EObjectTypeQuery> InteractableObjectType;
};
