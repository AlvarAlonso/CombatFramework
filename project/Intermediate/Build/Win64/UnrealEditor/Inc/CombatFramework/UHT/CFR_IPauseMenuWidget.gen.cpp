// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/Widgets/CFR_IPauseMenuWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_IPauseMenuWidget() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_IInGameMenuWidget();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_IPauseMenuWidget();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_IPauseMenuWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_IPauseMenuWidget Function Resume
struct Z_Construct_UFunction_UCFR_IPauseMenuWidget_Resume_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widgets/CFR_IPauseMenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_IPauseMenuWidget_Resume_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_IPauseMenuWidget, nullptr, "Resume", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_IPauseMenuWidget_Resume_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_IPauseMenuWidget_Resume_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UCFR_IPauseMenuWidget_Resume()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_IPauseMenuWidget_Resume_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_IPauseMenuWidget::execResume)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Resume();
	P_NATIVE_END;
}
// End Class UCFR_IPauseMenuWidget Function Resume

// Begin Class UCFR_IPauseMenuWidget
void UCFR_IPauseMenuWidget::StaticRegisterNativesUCFR_IPauseMenuWidget()
{
	UClass* Class = UCFR_IPauseMenuWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Resume", &UCFR_IPauseMenuWidget::execResume },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_IPauseMenuWidget);
UClass* Z_Construct_UClass_UCFR_IPauseMenuWidget_NoRegister()
{
	return UCFR_IPauseMenuWidget::StaticClass();
}
struct Z_Construct_UClass_UCFR_IPauseMenuWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Widgets/CFR_IPauseMenuWidget.h" },
		{ "ModuleRelativePath", "Public/Widgets/CFR_IPauseMenuWidget.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCFR_IPauseMenuWidget_Resume, "Resume" }, // 4248310207
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_IPauseMenuWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCFR_IPauseMenuWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCFR_IInGameMenuWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_IPauseMenuWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_IPauseMenuWidget_Statics::ClassParams = {
	&UCFR_IPauseMenuWidget::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_IPauseMenuWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_IPauseMenuWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_IPauseMenuWidget()
{
	if (!Z_Registration_Info_UClass_UCFR_IPauseMenuWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_IPauseMenuWidget.OuterSingleton, Z_Construct_UClass_UCFR_IPauseMenuWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_IPauseMenuWidget.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_IPauseMenuWidget>()
{
	return UCFR_IPauseMenuWidget::StaticClass();
}
UCFR_IPauseMenuWidget::UCFR_IPauseMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_IPauseMenuWidget);
UCFR_IPauseMenuWidget::~UCFR_IPauseMenuWidget() {}
// End Class UCFR_IPauseMenuWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_IPauseMenuWidget, UCFR_IPauseMenuWidget::StaticClass, TEXT("UCFR_IPauseMenuWidget"), &Z_Registration_Info_UClass_UCFR_IPauseMenuWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_IPauseMenuWidget), 159423077U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_109080640(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Widgets_CFR_IPauseMenuWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
