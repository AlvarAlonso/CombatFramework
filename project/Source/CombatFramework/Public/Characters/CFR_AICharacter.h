// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CFR_CharacterBase.h"
#include "CFR_AICharacter.generated.h"

UCLASS()
class COMBATFRAMEWORK_API ACFR_AICharacter : public ACFR_CharacterBase
{
	GENERATED_BODY()
	
public:
	ACFR_AICharacter();

	virtual FGenericTeamId GetGenericTeamId() const override;

protected:
	void BeginPlay() override;
	void InitAbilitySystemInfo() override;
	void HandleDeath() override;
	void HandleHealthChanged(const FOnAttributeChangeData& InData) override;
};
