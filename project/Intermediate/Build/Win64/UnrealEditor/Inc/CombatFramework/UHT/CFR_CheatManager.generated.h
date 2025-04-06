// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Utils/CFR_CheatManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_CheatManager_generated_h
#error "CFR_CheatManager.generated.h already included, missing '#pragma once' in CFR_CheatManager.h"
#endif
#define COMBATFRAMEWORK_CFR_CheatManager_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execKillPlayer);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_9_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_CheatManager(); \
	friend struct Z_Construct_UClass_UCFR_CheatManager_Statics; \
public: \
	DECLARE_CLASS(UCFR_CheatManager, UCheatManager, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_CheatManager)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_9_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCFR_CheatManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_CheatManager(UCFR_CheatManager&&); \
	UCFR_CheatManager(const UCFR_CheatManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_CheatManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_CheatManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_CheatManager) \
	NO_API virtual ~UCFR_CheatManager();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_6_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_9_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_9_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_9_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_CheatManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
