// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/CFR_EventDataPayloads.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_EventDataPayloads_generated_h
#error "CFR_EventDataPayloads.generated.h already included, missing '#pragma once' in CFR_EventDataPayloads.h"
#endif
#define COMBATFRAMEWORK_CFR_EventDataPayloads_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_EventDataAsset(); \
	friend struct Z_Construct_UClass_UCFR_EventDataAsset_Statics; \
public: \
	DECLARE_CLASS(UCFR_EventDataAsset, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_EventDataAsset)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCFR_EventDataAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_EventDataAsset(UCFR_EventDataAsset&&); \
	UCFR_EventDataAsset(const UCFR_EventDataAsset&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_EventDataAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_EventDataAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_EventDataAsset) \
	NO_API virtual ~UCFR_EventDataAsset();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_13_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_16_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_EventDataAsset>();

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_29_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics; \
	COMBATFRAMEWORK_API static class UScriptStruct* StaticStruct();


template<> COMBATFRAMEWORK_API UScriptStruct* StaticStruct<struct FCFR_EffectContextContainer>();

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_42_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_DamageEventDataAsset(); \
	friend struct Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics; \
public: \
	DECLARE_CLASS(UCFR_DamageEventDataAsset, UCFR_EventDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_DamageEventDataAsset) \
	virtual UObject* _getUObject() const override { return const_cast<UCFR_DamageEventDataAsset*>(this); }


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_42_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_DamageEventDataAsset(UCFR_DamageEventDataAsset&&); \
	UCFR_DamageEventDataAsset(const UCFR_DamageEventDataAsset&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_DamageEventDataAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_DamageEventDataAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_DamageEventDataAsset) \
	NO_API virtual ~UCFR_DamageEventDataAsset();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_39_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_42_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_42_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_DamageEventDataAsset>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
