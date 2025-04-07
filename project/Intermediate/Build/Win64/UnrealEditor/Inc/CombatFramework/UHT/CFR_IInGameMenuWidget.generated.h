// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Widgets/CFR_IInGameMenuWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_IInGameMenuWidget_generated_h
#error "CFR_IInGameMenuWidget.generated.h already included, missing '#pragma once' in CFR_IInGameMenuWidget.h"
#endif
#define COMBATFRAMEWORK_CFR_IInGameMenuWidget_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExitGame); \
	DECLARE_FUNCTION(execReturnToMainMenu);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_IInGameMenuWidget(); \
	friend struct Z_Construct_UClass_UCFR_IInGameMenuWidget_Statics; \
public: \
	DECLARE_CLASS(UCFR_IInGameMenuWidget, UCommonActivatableWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_IInGameMenuWidget)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCFR_IInGameMenuWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_IInGameMenuWidget(UCFR_IInGameMenuWidget&&); \
	UCFR_IInGameMenuWidget(const UCFR_IInGameMenuWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_IInGameMenuWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_IInGameMenuWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_IInGameMenuWidget) \
	NO_API virtual ~UCFR_IInGameMenuWidget();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_8_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_11_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_IInGameMenuWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
