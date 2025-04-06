// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/Widgets/CFR_IInGameMenuWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_IInGameMenuWidget() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_IInGameMenuWidget();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_IInGameMenuWidget_NoRegister();
COMMONUI_API UClass* Z_Construct_UClass_UCommonActivatableWidget();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_IInGameMenuWidget Function ExitGame
struct Z_Construct_UFunction_UCFR_IInGameMenuWidget_ExitGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widgets/CFR_IInGameMenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_IInGameMenuWidget_ExitGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_IInGameMenuWidget, nullptr, "ExitGame", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_IInGameMenuWidget_ExitGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_IInGameMenuWidget_ExitGame_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UCFR_IInGameMenuWidget_ExitGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_IInGameMenuWidget_ExitGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_IInGameMenuWidget::execExitGame)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExitGame();
	P_NATIVE_END;
}
// End Class UCFR_IInGameMenuWidget Function ExitGame

// Begin Class UCFR_IInGameMenuWidget Function ReturnToMainMenu
struct Z_Construct_UFunction_UCFR_IInGameMenuWidget_ReturnToMainMenu_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widgets/CFR_IInGameMenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_IInGameMenuWidget_ReturnToMainMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_IInGameMenuWidget, nullptr, "ReturnToMainMenu", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_IInGameMenuWidget_ReturnToMainMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_IInGameMenuWidget_ReturnToMainMenu_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UCFR_IInGameMenuWidget_ReturnToMainMenu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_IInGameMenuWidget_ReturnToMainMenu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_IInGameMenuWidget::execReturnToMainMenu)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ReturnToMainMenu();
	P_NATIVE_END;
}
// End Class UCFR_IInGameMenuWidget Function ReturnToMainMenu

// Begin Class UCFR_IInGameMenuWidget
void UCFR_IInGameMenuWidget::StaticRegisterNativesUCFR_IInGameMenuWidget()
{
	UClass* Class = UCFR_IInGameMenuWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ExitGame", &UCFR_IInGameMenuWidget::execExitGame },
		{ "ReturnToMainMenu", &UCFR_IInGameMenuWidget::execReturnToMainMenu },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_IInGameMenuWidget);
UClass* Z_Construct_UClass_UCFR_IInGameMenuWidget_NoRegister()
{
	return UCFR_IInGameMenuWidget::StaticClass();
}
struct Z_Construct_UClass_UCFR_IInGameMenuWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Widgets/CFR_IInGameMenuWidget.h" },
		{ "ModuleRelativePath", "Public/Widgets/CFR_IInGameMenuWidget.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCFR_IInGameMenuWidget_ExitGame, "ExitGame" }, // 1049049005
		{ &Z_Construct_UFunction_UCFR_IInGameMenuWidget_ReturnToMainMenu, "ReturnToMainMenu" }, // 2532098967
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_IInGameMenuWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCFR_IInGameMenuWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCommonActivatableWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_IInGameMenuWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_IInGameMenuWidget_Statics::ClassParams = {
	&UCFR_IInGameMenuWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_IInGameMenuWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_IInGameMenuWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_IInGameMenuWidget()
{
	if (!Z_Registration_Info_UClass_UCFR_IInGameMenuWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_IInGameMenuWidget.OuterSingleton, Z_Construct_UClass_UCFR_IInGameMenuWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_IInGameMenuWidget.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_IInGameMenuWidget>()
{
	return UCFR_IInGameMenuWidget::StaticClass();
}
UCFR_IInGameMenuWidget::UCFR_IInGameMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_IInGameMenuWidget);
UCFR_IInGameMenuWidget::~UCFR_IInGameMenuWidget() {}
// End Class UCFR_IInGameMenuWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_IInGameMenuWidget, UCFR_IInGameMenuWidget::StaticClass, TEXT("UCFR_IInGameMenuWidget"), &Z_Registration_Info_UClass_UCFR_IInGameMenuWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_IInGameMenuWidget), 1163720860U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_647039558(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IInGameMenuWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
