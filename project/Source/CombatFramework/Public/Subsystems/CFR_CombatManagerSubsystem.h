// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "CFR_CombatManagerSubsystem.generated.h"

class ACFR_AICharacter;
class ACFR_PlayerCharacter;

USTRUCT()
struct COMBATFRAMEWORK_API FCFR_EnemyCombatItem
{
	GENERATED_BODY()

	FCFR_EnemyCombatItem() = default;
	FCFR_EnemyCombatItem(ACFR_AICharacter* enemy)
		: Enemy(enemy)
	{}

	bool IsValid() const { return Enemy.IsValid(); }

	void Reset(ACFR_AICharacter* enemy);

	UPROPERTY()
	TWeakObjectPtr<ACFR_AICharacter> Enemy = nullptr;

	float Distance = 0.0;
	float Scoring = 0.0;
	float LastAttackTime = 0.0;
};

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_CombatManagerSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void Tick(float DeltaTime) override;

private:
	void OnActorSpawned(AActor* actor);
	void OnEnemySpawned(ACFR_AICharacter* Enemy, TArray<FCFR_EnemyCombatItem>& EnemyItems);

	UFUNCTION()
	void OnEnemyDeath(ACFR_AICharacter* enemy);

	void Invalidate();
	void InvalidateImpl(TArray<FCFR_EnemyCombatItem>& EnemyItems);

	void UpdateMeleeEnemies();
	void UpdateDistanceEnemies();

	void UpdateScoring(TArray<FCFR_EnemyCombatItem>& EnemyItems, const std::function<void(FCFR_EnemyCombatItem&)>& ScoringFunction);
	void UpdateSlots(TArray<FCFR_EnemyCombatItem>& EnemyItems, int32 numSlots);
	void PrepareCandidateData(const TArray<FCFR_EnemyCombatItem>& EnemyItems, TArray<int32>& candidates, int32& numAttackers, int32& numRecoveries) const;

	int32 FindBestAttacker(const TArray<int32>& candidates, const TArray<FCFR_EnemyCombatItem>& EnemyItems) const;
	int32 FindNewAttacker(const TArray<int32>& candidates, const TArray<FCFR_EnemyCombatItem>& EnemyItems) const;

private:
	// TODO: Make it data oriented.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float CombatRadius = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int32 NbHoldingEnemies = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int32 MaxMeleeEnemies = 12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int32 MaxRangedEnemies = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int32 NbMeleeSlots = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int32 NbRangedSlots = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float InvalidateOffset = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float DistanceWeight = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float IsNotInFrustumScore = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float IsNotInFrustumWeight = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float LastAttackTimeWeight = 1.0f;

	TArray<FCFR_EnemyCombatItem> EnemyMeleeItems;
	TArray<FCFR_EnemyCombatItem> EnemyRangedItems;

	TWeakObjectPtr<ACFR_PlayerCharacter> Player;

	FVector LastPlayerPosition;

	bool bAddedNewEnemies = false;
	bool bEnemyDead = false;
};
