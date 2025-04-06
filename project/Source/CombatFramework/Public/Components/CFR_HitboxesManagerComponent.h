// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTags.h"
#include "CFR_HitboxesManagerComponent.generated.h"

class UCFR_HitboxComponent;

UCLASS(BlueprintType, Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATFRAMEWORK_API UCFR_HitboxesManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCFR_HitboxesManagerComponent();

	UFUNCTION(BlueprintCallable)
	void AddHitboxToMap(FGameplayTag IdentifierTag, UCFR_HitboxComponent* HitboxComponent);

	UFUNCTION(BlueprintPure)
	UCFR_HitboxComponent* GetHitboxByTag(FGameplayTag IdentifierTag);

protected:
	UPROPERTY()
	TMap<FGameplayTag, UCFR_HitboxComponent*> HitboxesMap;
		
};
