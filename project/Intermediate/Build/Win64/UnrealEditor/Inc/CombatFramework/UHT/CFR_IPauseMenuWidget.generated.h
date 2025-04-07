// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Widgets/CFR_IPauseMenuWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMBATFRAMEWORK_CFR_IPauseMenuWidget_generated_h
#error "CFR_IPauseMenuWidget.generated.h already included, missing '#pragma once' in CFR_IPauseMenuWidget.h"
#endif
#define COMBATFRAMEWORK_CFR_IPauseMenuWidget_generated_h

#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execResume);


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCFR_IPauseMenuWidget(); \
	friend struct Z_Construct_UClass_UCFR_IPauseMenuWidget_Statics; \
public: \
	DECLARE_CLASS(UCFR_IPauseMenuWidget, UCFR_IInGameMenuWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatFramework"), NO_API) \
	DECLARE_SERIALIZER(UCFR_IPauseMenuWidget)


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCFR_IPauseMenuWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCFR_IPauseMenuWidget(UCFR_IPauseMenuWidget&&); \
	UCFR_IPauseMenuWidget(const UCFR_IPauseMenuWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCFR_IPauseMenuWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCFR_IPauseMenuWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCFR_IPauseMenuWidget) \
	NO_API virtual ~UCFR_IPauseMenuWidget();


#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_7_PROLOG
#define FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_10_INCLASS_NO_PURE_DECLS \
	FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMBATFRAMEWORK_API UClass* StaticClass<class UCFR_IPauseMenuWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
