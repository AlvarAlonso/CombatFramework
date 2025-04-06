// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameFramework/CFR_IGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_IGameMode_generated_h
#error "CFR_IGameMode.generated.h already included, missing '#pragma once' in CFR_IGameMode.h"
#endif
#define COMBATFRAMEWORK_CFR_IGameMode_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACFR_IGameMode(); \
	friend struct Z_Construct_UClass_ACFR_IGameMode_Statics; \
public: \
	DECLARE_CLASS(ACFR_IGameMode, AGameMode, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(ACFR_IGameMode)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACFR_IGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACFR_IGameMode(ACFR_IGameMode&&); \
	ACFR_IGameMode(const ACFR_IGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACFR_IGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACFR_IGameMode); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACFR_IGameMode) \
	NO_API virtual ~ACFR_IGameMode();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h_10_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h_13_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class ACFR_IGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
