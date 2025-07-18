// Fill out your copyright notice in the Description page of Project Settings.


#include "CFR_AssetManager.h"

#include "AbilitySystem/CFR_GameplayTags.h"

UCFR_AssetManager& UCFR_AssetManager::Get()
{
	check(GEngine);

	UCFR_AssetManager* CFR_AssetManager = Cast<UCFR_AssetManager>(GEngine->AssetManager);
	return *CFR_AssetManager;
}

void UCFR_AssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FCFR_GameplayTags::InitializeNativeGameplayTags();
}
