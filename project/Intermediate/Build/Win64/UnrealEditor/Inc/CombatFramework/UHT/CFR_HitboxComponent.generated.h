// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/CFR_HitboxComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FGameplayTag;
struct FHitResult;
#ifdef COMBATFRAMEWORK_CFR_HitboxComponent_generated_h
#error "CFR_HitboxComponent.generated.h already included, missing '#pragma once' in CFR_HitboxComponent.h"
#endif
#define COMBATFRAMEWORK_CFR_HitboxComponent_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_10_DELEGATE \
COMBATFRAMEWORK_API void FCFR_HitboxOverlapDelegate_DelegateWrapper(const FMulticastScriptDelegate& CFR_HitboxOverlapDelegate, AActor* HitActor);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetEffectTag); \
	DECLARE_FUNCTION(execSetEffectTag); \
	DECLARE_FUNCTION(execDeactivateHitbox); \
	DECLARE_FUNCTION(execActivateHitbox); \
	DECLARE_FUNCTION(execOnComponentOverlap);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_HitboxComponent(); \
	friend struct Z_Construct_UClass_UCFR_HitboxComponent_Statics; \
public: \
	DECLARE_CLASS(UCFR_HitboxComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_HitboxComponent)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_HitboxComponent(UCFR_HitboxComponent&&); \
	UCFR_HitboxComponent(const UCFR_HitboxComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_HitboxComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_HitboxComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCFR_HitboxComponent) \
	NO_API virtual ~UCFR_HitboxComponent();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_12_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_15_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_HitboxComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
