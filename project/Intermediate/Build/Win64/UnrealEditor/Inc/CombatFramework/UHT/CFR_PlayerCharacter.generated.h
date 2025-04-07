// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Characters/CFR_PlayerCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_PlayerCharacter_generated_h
#error "CFR_PlayerCharacter.generated.h already included, missing '#pragma once' in CFR_PlayerCharacter.h"
#endif
#define COMBATFRAMEWORK_CFR_PlayerCharacter_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacter_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACFR_PlayerCharacter(); \
	friend struct Z_Construct_UClass_ACFR_PlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(ACFR_PlayerCharacter, ACFR_CharacterBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(ACFR_PlayerCharacter)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacter_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACFR_PlayerCharacter(ACFR_PlayerCharacter&&); \
	ACFR_PlayerCharacter(const ACFR_PlayerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACFR_PlayerCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACFR_PlayerCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACFR_PlayerCharacter) \
	NO_API virtual ~ACFR_PlayerCharacter();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacter_h_15_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacter_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacter_h_18_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacter_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class ACFR_PlayerCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
