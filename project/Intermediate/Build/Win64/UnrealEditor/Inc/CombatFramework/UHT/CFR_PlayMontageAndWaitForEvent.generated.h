// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/AbilityTasks/CFR_PlayMontageAndWaitForEvent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
class UCFR_PlayMontageAndWaitForEvent;
class UGameplayAbility;
struct FGameplayEventData;
struct FGameplayTag;
struct FGameplayTagContainer;
#ifdef COMBATFRAMEWORK_CFR_PlayMontageAndWaitForEvent_generated_h
#error "CFR_PlayMontageAndWaitForEvent.generated.h already included, missing '#pragma once' in CFR_PlayMontageAndWaitForEvent.h"
#endif
#define COMBATFRAMEWORK_CFR_PlayMontageAndWaitForEvent_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_AbilityTasks_CFR_PlayMontageAndWaitForEvent_h_12_DELEGATE \
COMBATFRAMEWORK_API void FCFR_PlayMontageAndWaitForEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& CFR_PlayMontageAndWaitForEventDelegate, FGameplayTag EventTag, FGameplayEventData EventData);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_AbilityTasks_CFR_PlayMontageAndWaitForEvent_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execPlayMontageAndWaitForEvent);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_AbilityTasks_CFR_PlayMontageAndWaitForEvent_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_PlayMontageAndWaitForEvent(); \
	friend struct Z_Construct_UClass_UCFR_PlayMontageAndWaitForEvent_Statics; \
public: \
	DECLARE_CLASS(UCFR_PlayMontageAndWaitForEvent, UAbilityTask, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_PlayMontageAndWaitForEvent)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_AbilityTasks_CFR_PlayMontageAndWaitForEvent_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_PlayMontageAndWaitForEvent(UCFR_PlayMontageAndWaitForEvent&&); \
	UCFR_PlayMontageAndWaitForEvent(const UCFR_PlayMontageAndWaitForEvent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_PlayMontageAndWaitForEvent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_PlayMontageAndWaitForEvent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_PlayMontageAndWaitForEvent) \
	NO_API virtual ~UCFR_PlayMontageAndWaitForEvent();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_AbilityTasks_CFR_PlayMontageAndWaitForEvent_h_18_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_AbilityTasks_CFR_PlayMontageAndWaitForEvent_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_AbilityTasks_CFR_PlayMontageAndWaitForEvent_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_AbilityTasks_CFR_PlayMontageAndWaitForEvent_h_21_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_AbilityTasks_CFR_PlayMontageAndWaitForEvent_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_PlayMontageAndWaitForEvent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_AbilityTasks_CFR_PlayMontageAndWaitForEvent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
