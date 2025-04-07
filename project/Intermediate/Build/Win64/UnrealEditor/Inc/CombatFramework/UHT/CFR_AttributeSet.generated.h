// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/CFR_AttributeSet.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "Net/Core/PushModel/PushModelMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayAttributeData;
#ifdef COMBATFRAMEWORK_CFR_AttributeSet_generated_h
#error "CFR_AttributeSet.generated.h already included, missing '#pragma once' in CFR_AttributeSet.h"
#endif
#define COMBATFRAMEWORK_CFR_AttributeSet_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_Strength); \
	DECLARE_FUNCTION(execOnRep_MaxMana); \
	DECLARE_FUNCTION(execOnRep_CurrentMana); \
	DECLARE_FUNCTION(execOnRep_MaxHealth); \
	DECLARE_FUNCTION(execOnRep_CurrentHealth);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_AttributeSet(); \
	friend struct Z_Construct_UClass_UCFR_AttributeSet_Statics; \
public: \
	DECLARE_CLASS(UCFR_AttributeSet, UAttributeSet, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_AttributeSet) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CurrentHealth=NETFIELD_REP_START, \
		MaxHealth, \
		CurrentMana, \
		MaxMana, \
		Strength, \
		NETFIELD_REP_END=Strength	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override; \
private: \
	REPLICATED_BASE_CLASS(UCFR_AttributeSet) \
public:


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_AttributeSet(UCFR_AttributeSet&&); \
	UCFR_AttributeSet(const UCFR_AttributeSet&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_AttributeSet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_AttributeSet); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCFR_AttributeSet) \
	NO_API virtual ~UCFR_AttributeSet();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_16_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_19_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_AttributeSet>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
