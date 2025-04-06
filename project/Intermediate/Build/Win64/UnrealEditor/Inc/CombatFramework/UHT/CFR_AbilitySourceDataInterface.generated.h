// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/CFR_AbilitySourceDataInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_AbilitySourceDataInterface_generated_h
#error "CFR_AbilitySourceDataInterface.generated.h already included, missing '#pragma once' in CFR_AbilitySourceDataInterface.h"
#endif
#define COMBATFRAMEWORK_CFR_AbilitySourceDataInterface_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCFR_AbilitySourceDataInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_AbilitySourceDataInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_AbilitySourceDataInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_AbilitySourceDataInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_AbilitySourceDataInterface(UCFR_AbilitySourceDataInterface&&); \
	UCFR_AbilitySourceDataInterface(const UCFR_AbilitySourceDataInterface&); \
public: \
	NO_API virtual ~UCFR_AbilitySourceDataInterface();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_11_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUCFR_AbilitySourceDataInterface(); \
	friend struct Z_Construct_UClass_UCFR_AbilitySourceDataInterface_Statics; \
public: \
	DECLARE_CLASS(UCFR_AbilitySourceDataInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_AbilitySourceDataInterface)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_11_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_11_GENERATED_UINTERFACE_BODY() \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_11_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_11_INCLASS_IINTERFACE \
protected: \
	virtual ~ICFR_AbilitySourceDataInterface() {} \
public: \
	typedef UCFR_AbilitySourceDataInterface UClassType; \
	typedef ICFR_AbilitySourceDataInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_8_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_11_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_AbilitySourceDataInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
