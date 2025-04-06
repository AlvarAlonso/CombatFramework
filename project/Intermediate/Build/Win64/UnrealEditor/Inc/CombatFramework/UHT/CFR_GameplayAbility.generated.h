// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/CFR_GameplayAbility.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_GameplayAbility_generated_h
#error "CFR_GameplayAbility.generated.h already included, missing '#pragma once' in CFR_GameplayAbility.h"
#endif
#define COMBATFRAMEWORK_CFR_GameplayAbility_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_GameplayAbility(); \
	friend struct Z_Construct_UClass_UCFR_GameplayAbility_Statics; \
public: \
	DECLARE_CLASS(UCFR_GameplayAbility, UGameplayAbility, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_GameplayAbility)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCFR_GameplayAbility(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_GameplayAbility(UCFR_GameplayAbility&&); \
	UCFR_GameplayAbility(const UCFR_GameplayAbility&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_GameplayAbility); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_GameplayAbility); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_GameplayAbility) \
	NO_API virtual ~UCFR_GameplayAbility();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h_12_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h_15_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_GameplayAbility>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
