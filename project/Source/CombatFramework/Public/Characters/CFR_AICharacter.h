// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CFR_CharacterBase.h"
#include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "CFR_AICharacter.generated.h"

class UWidgetComponent;

UCLASS()
class COMBATFRAMEWORK_API ACFR_AICharacter : public ACFR_CharacterBase
{
	GENERATED_BODY()
	
public:
	ACFR_AICharacter();

	virtual FGenericTeamId GetGenericTeamId() const override;
	void SetCombatTargetWidgetVisibility(bool bVisible);

protected:
	void BeginPlay() override;
	void InitAbilitySystemInfo() override;
	void HandleHealthChanged(const FOnAttributeChangeData& InData) override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<FCFR_AbilityInitData> DefaultAbilitiesInitData;

	/* Initializer gameplay effects. */
	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	TArray<TSubclassOf<UGameplayEffect>> StartupGameplayEffects;

protected:
	/** Target widget component to notify the player this is the enemy on target. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UWidgetComponent* CombatTargetWidgetComponent = nullptr;
};
