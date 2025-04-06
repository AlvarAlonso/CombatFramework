// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/CFR_AbilitySourceDataInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_AbilitySourceDataInterface() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AbilitySourceDataInterface();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AbilitySourceDataInterface_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Interface UCFR_AbilitySourceDataInterface
void UCFR_AbilitySourceDataInterface::StaticRegisterNativesUCFR_AbilitySourceDataInterface()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_AbilitySourceDataInterface);
UClass* Z_Construct_UClass_UCFR_AbilitySourceDataInterface_NoRegister()
{
	return UCFR_AbilitySourceDataInterface::StaticClass();
}
struct Z_Construct_UClass_UCFR_AbilitySourceDataInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySourceDataInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ICFR_AbilitySourceDataInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCFR_AbilitySourceDataInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AbilitySourceDataInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_AbilitySourceDataInterface_Statics::ClassParams = {
	&UCFR_AbilitySourceDataInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000040A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AbilitySourceDataInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_AbilitySourceDataInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_AbilitySourceDataInterface()
{
	if (!Z_Registration_Info_UClass_UCFR_AbilitySourceDataInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_AbilitySourceDataInterface.OuterSingleton, Z_Construct_UClass_UCFR_AbilitySourceDataInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_AbilitySourceDataInterface.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_AbilitySourceDataInterface>()
{
	return UCFR_AbilitySourceDataInterface::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_AbilitySourceDataInterface);
UCFR_AbilitySourceDataInterface::~UCFR_AbilitySourceDataInterface() {}
// End Interface UCFR_AbilitySourceDataInterface

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_AbilitySourceDataInterface, UCFR_AbilitySourceDataInterface::StaticClass, TEXT("UCFR_AbilitySourceDataInterface"), &Z_Registration_Info_UClass_UCFR_AbilitySourceDataInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_AbilitySourceDataInterface), 1143518693U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_1798286906(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySourceDataInterface_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
