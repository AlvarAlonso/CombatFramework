// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/Characters/CFR_PlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_PlayerController() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_PlayerController();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_PlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class ACFR_PlayerController
void ACFR_PlayerController::StaticRegisterNativesACFR_PlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACFR_PlayerController);
UClass* Z_Construct_UClass_ACFR_PlayerController_NoRegister()
{
	return ACFR_PlayerController::StaticClass();
}
struct Z_Construct_UClass_ACFR_PlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Characters/CFR_PlayerController.h" },
		{ "ModuleRelativePath", "Public/Characters/CFR_PlayerController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACFR_PlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACFR_PlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_PlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACFR_PlayerController_Statics::ClassParams = {
	&ACFR_PlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_PlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ACFR_PlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACFR_PlayerController()
{
	if (!Z_Registration_Info_UClass_ACFR_PlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACFR_PlayerController.OuterSingleton, Z_Construct_UClass_ACFR_PlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACFR_PlayerController.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<ACFR_PlayerController>()
{
	return ACFR_PlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACFR_PlayerController);
ACFR_PlayerController::~ACFR_PlayerController() {}
// End Class ACFR_PlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACFR_PlayerController, ACFR_PlayerController::StaticClass, TEXT("ACFR_PlayerController"), &Z_Registration_Info_UClass_ACFR_PlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACFR_PlayerController), 2148109928U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerController_h_3614714560(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_PlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
