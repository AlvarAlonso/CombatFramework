// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Characters/CFR_PlayerCharacterAnimInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_PlayerCharacterAnimInstance_generated_h
#error "CFR_PlayerCharacterAnimInstance.generated.h already included, missing '#pragma once' in CFR_PlayerCharacterAnimInstance.h"
#endif
#define COMBATFRAMEWORK_CFR_PlayerCharacterAnimInstance_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacterAnimInstance_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_PlayerCharacterAnimInstance(); \
	friend struct Z_Construct_UClass_UCFR_PlayerCharacterAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UCFR_PlayerCharacterAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_PlayerCharacterAnimInstance)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacterAnimInstance_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCFR_PlayerCharacterAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_PlayerCharacterAnimInstance(UCFR_PlayerCharacterAnimInstance&&); \
	UCFR_PlayerCharacterAnimInstance(const UCFR_PlayerCharacterAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_PlayerCharacterAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_PlayerCharacterAnimInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_PlayerCharacterAnimInstance) \
	NO_API virtual ~UCFR_PlayerCharacterAnimInstance();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacterAnimInstance_h_7_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacterAnimInstance_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacterAnimInstance_h_10_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacterAnimInstance_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_PlayerCharacterAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerCharacterAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
