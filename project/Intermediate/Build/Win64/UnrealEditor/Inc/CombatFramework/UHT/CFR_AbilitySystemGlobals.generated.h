// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/CFR_AbilitySystemGlobals.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_AbilitySystemGlobals_generated_h
#error "CFR_AbilitySystemGlobals.generated.h already included, missing '#pragma once' in CFR_AbilitySystemGlobals.h"
#endif
#define COMBATFRAMEWORK_CFR_AbilitySystemGlobals_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_AbilitySystemGlobals(); \
	friend struct Z_Construct_UClass_UCFR_AbilitySystemGlobals_Statics; \
public: \
	DECLARE_CLASS(UCFR_AbilitySystemGlobals, UAbilitySystemGlobals, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_AbilitySystemGlobals)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCFR_AbilitySystemGlobals(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_AbilitySystemGlobals(UCFR_AbilitySystemGlobals&&); \
	UCFR_AbilitySystemGlobals(const UCFR_AbilitySystemGlobals&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_AbilitySystemGlobals); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_AbilitySystemGlobals); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_AbilitySystemGlobals) \
	NO_API virtual ~UCFR_AbilitySystemGlobals();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_13_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_16_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_AbilitySystemGlobals>();

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_30_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FGameplayEffectContext Super;


template<> COMBATFRAMEWORK_API UScriptStruct* StaticStruct<struct FCFR_GameplayEffectContext>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
