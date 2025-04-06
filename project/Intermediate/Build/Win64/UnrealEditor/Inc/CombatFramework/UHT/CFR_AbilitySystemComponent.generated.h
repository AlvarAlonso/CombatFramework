// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/CFR_AbilitySystemComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UGameplayAbility;
class UInputAction;
struct FGameplayAbilitySpecHandle;
struct FGameplayTag;
struct FGameplayTagContainer;
#ifdef COMBATFRAMEWORK_CFR_AbilitySystemComponent_generated_h
#error "CFR_AbilitySystemComponent.generated.h already included, missing '#pragma once' in CFR_AbilitySystemComponent.h"
#endif
#define COMBATFRAMEWORK_CFR_AbilitySystemComponent_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics; \
	COMBATFRAMEWORK_API static class UScriptStruct* StaticStruct();


template<> COMBATFRAMEWORK_API UScriptStruct* StaticStruct<struct FCFR_AbilityInitData>();

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_29_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCFR_AbilityInputBinding_Statics; \
	COMBATFRAMEWORK_API static class UScriptStruct* StaticStruct();


template<> COMBATFRAMEWORK_API UScriptStruct* StaticStruct<struct FCFR_AbilityInputBinding>();

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetInputBinding); \
	DECLARE_FUNCTION(execK2_RemoveLooseGameplayTags); \
	DECLARE_FUNCTION(execK2_RemoveLooseGameplayTag); \
	DECLARE_FUNCTION(execK2_AddLooseGameplayTags); \
	DECLARE_FUNCTION(execK2_AddLooseGameplayTag); \
	DECLARE_FUNCTION(execAddUniqueLooseGameplayTag); \
	DECLARE_FUNCTION(execGrantAbilityOfType);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_46_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_AbilitySystemComponent(); \
	friend struct Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics; \
public: \
	DECLARE_CLASS(UCFR_AbilitySystemComponent, UAbilitySystemComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_AbilitySystemComponent)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_46_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCFR_AbilitySystemComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_AbilitySystemComponent(UCFR_AbilitySystemComponent&&); \
	UCFR_AbilitySystemComponent(const UCFR_AbilitySystemComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_AbilitySystemComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_AbilitySystemComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_AbilitySystemComponent) \
	NO_API virtual ~UCFR_AbilitySystemComponent();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_43_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_46_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_46_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_46_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_AbilitySystemComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
