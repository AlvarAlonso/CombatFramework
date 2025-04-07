// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayEventData;
struct FGameplayTag;
#ifdef COMBATFRAMEWORK_CFR_GA_PlayMontage_generated_h
#error "CFR_GA_PlayMontage.generated.h already included, missing '#pragma once' in CFR_GA_PlayMontage.h"
#endif
#define COMBATFRAMEWORK_CFR_GA_PlayMontage_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnReceivedEvent); \
	DECLARE_FUNCTION(execOnMontageFinished);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_16_CALLBACK_WRAPPERS
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_GA_PlayMontage(); \
	friend struct Z_Construct_UClass_UCFR_GA_PlayMontage_Statics; \
public: \
	DECLARE_CLASS(UCFR_GA_PlayMontage, UCFR_GameplayAbility, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_GA_PlayMontage)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCFR_GA_PlayMontage(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_GA_PlayMontage(UCFR_GA_PlayMontage&&); \
	UCFR_GA_PlayMontage(const UCFR_GA_PlayMontage&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_GA_PlayMontage); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_GA_PlayMontage); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_GA_PlayMontage) \
	NO_API virtual ~UCFR_GA_PlayMontage();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_13_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_16_CALLBACK_WRAPPERS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_16_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_GA_PlayMontage>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
