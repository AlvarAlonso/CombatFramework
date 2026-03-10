// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CFR_BlueprintFunctionLibrary.generated.h"

class ACFR_CharacterBase;
class ACFR_AICharacter;
class ACFR_Projectile;

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UCFR_BlueprintFunctionLibrary|GameplayUtils")
	static void RotateDirectlyTowardsActor(AActor* Source, const AActor* Target, bool bFaceBackwards);

	UFUNCTION(BlueprintCallable, Category = "UCFR_BlueprintFunctionLibrary|GameplayUtils")
	static bool IsInFrustum(const ACFR_AICharacter* Character);

	UFUNCTION(BlueprintCallable, Category = "UCFR_BlueprintFunctionLibrary|GameplayUtils")
	static bool IsGonnaHitGround(const AActor* Actor, const float Distance);

	UFUNCTION(BlueprintCallable, Category = "UCFR_BlueprintFunctionLibrary|GameplayUtils")
	static ACFR_Projectile* SpawnProjectile(UWorld* World, const TSubclassOf<ACFR_Projectile> ProjectileToSpawn, const FTransform SpawnTransform, AActor* Instigator, const FGenericTeamId TeamId);

	UFUNCTION(BlueprintCallable, Category = "UCFR_BlueprintFunctionLibrary|GameplayUtils")
	static void LaunchCharacterToLocation(ACFR_CharacterBase* CharacterBase, const FVector& TargetLocation, float GravityScaleMultiplier, float LaunchAngle);
};
