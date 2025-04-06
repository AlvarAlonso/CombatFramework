// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Characters/CFR_CharacterBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_CharacterBase_generated_h
#error "CFR_CharacterBase.generated.h already included, missing '#pragma once' in CFR_CharacterBase.h"
#endif
#define COMBATFRAMEWORK_CFR_CharacterBase_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetMaxHealth); \
	DECLARE_FUNCTION(execGetHealth);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACFR_CharacterBase(); \
	friend struct Z_Construct_UClass_ACFR_CharacterBase_Statics; \
public: \
	DECLARE_CLASS(ACFR_CharacterBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(ACFR_CharacterBase) \
	virtual UObject* _getUObject() const override { return const_cast<ACFR_CharacterBase*>(this); }


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACFR_CharacterBase(ACFR_CharacterBase&&); \
	ACFR_CharacterBase(const ACFR_CharacterBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACFR_CharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACFR_CharacterBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACFR_CharacterBase) \
	NO_API virtual ~ACFR_CharacterBase();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_15_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_18_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class ACFR_CharacterBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
