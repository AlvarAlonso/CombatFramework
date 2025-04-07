// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/CFR_HitboxesManagerComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCFR_HitboxComponent;
struct FGameplayTag;
#ifdef COMBATFRAMEWORK_CFR_HitboxesManagerComponent_generated_h
#error "CFR_HitboxesManagerComponent.generated.h already included, missing '#pragma once' in CFR_HitboxesManagerComponent.h"
#endif
#define COMBATFRAMEWORK_CFR_HitboxesManagerComponent_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetHitboxByTag); \
	DECLARE_FUNCTION(execAddHitboxToMap);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_HitboxesManagerComponent(); \
	friend struct Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics; \
public: \
	DECLARE_CLASS(UCFR_HitboxesManagerComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_HitboxesManagerComponent)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_HitboxesManagerComponent(UCFR_HitboxesManagerComponent&&); \
	UCFR_HitboxesManagerComponent(const UCFR_HitboxesManagerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_HitboxesManagerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_HitboxesManagerComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCFR_HitboxesManagerComponent) \
	NO_API virtual ~UCFR_HitboxesManagerComponent();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_12_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_15_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_HitboxesManagerComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
