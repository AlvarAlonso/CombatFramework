// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameFramework/CFR_PlayerState.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_PlayerState_generated_h
#error "CFR_PlayerState.generated.h already included, missing '#pragma once' in CFR_PlayerState.h"
#endif
#define COMBATFRAMEWORK_CFR_PlayerState_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_PlayerState_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACFR_PlayerState(); \
	friend struct Z_Construct_UClass_ACFR_PlayerState_Statics; \
public: \
	DECLARE_CLASS(ACFR_PlayerState, APlayerState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(ACFR_PlayerState) \
	virtual UObject* _getUObject() const override { return const_cast<ACFR_PlayerState*>(this); }


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_PlayerState_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACFR_PlayerState(ACFR_PlayerState&&); \
	ACFR_PlayerState(const ACFR_PlayerState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACFR_PlayerState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACFR_PlayerState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACFR_PlayerState) \
	NO_API virtual ~ACFR_PlayerState();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_PlayerState_h_13_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_PlayerState_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_PlayerState_h_16_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_PlayerState_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class ACFR_PlayerState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_PlayerState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
