// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameFramework/CFR_MainGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_MainGameMode_generated_h
#error "CFR_MainGameMode.generated.h already included, missing '#pragma once' in CFR_MainGameMode.h"
#endif
#define COMBATFRAMEWORK_CFR_MainGameMode_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACFR_MainGameMode(); \
	friend struct Z_Construct_UClass_ACFR_MainGameMode_Statics; \
public: \
	DECLARE_CLASS(ACFR_MainGameMode, ACFR_IGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(ACFR_MainGameMode)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACFR_MainGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACFR_MainGameMode(ACFR_MainGameMode&&); \
	ACFR_MainGameMode(const ACFR_MainGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACFR_MainGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACFR_MainGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACFR_MainGameMode) \
	NO_API virtual ~ACFR_MainGameMode();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h_11_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h_14_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class ACFR_MainGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
