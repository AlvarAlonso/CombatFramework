// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "CFR_AssetManager.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCFR_AssetManager : public UAssetManager
{
	GENERATED_BODY()

public:

	static UCFR_AssetManager& Get();

protected:

	virtual void StartInitialLoading() override;
};
