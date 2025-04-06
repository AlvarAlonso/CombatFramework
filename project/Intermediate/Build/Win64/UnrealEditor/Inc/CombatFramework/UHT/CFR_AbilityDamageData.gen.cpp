// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/CFR_AbilityDamageData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_AbilityDamageData() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AbilityDamageData();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AbilityDamageData_NoRegister();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AbilitySourceDataInterface_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_AbilityDamageData
void UCFR_AbilityDamageData::StaticRegisterNativesUCFR_AbilityDamageData()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_AbilityDamageData);
UClass* Z_Construct_UClass_UCFR_AbilityDamageData_NoRegister()
{
	return UCFR_AbilityDamageData::StaticClass();
}
struct Z_Construct_UClass_UCFR_AbilityDamageData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AbilitySystem/CFR_AbilityDamageData.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilityDamageData.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_AbilityDamageData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCFR_AbilityDamageData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AbilityDamageData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UCFR_AbilityDamageData_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UCFR_AbilitySourceDataInterface_NoRegister, (int32)VTABLE_OFFSET(UCFR_AbilityDamageData, ICFR_AbilitySourceDataInterface), false },  // 1143518693
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_AbilityDamageData_Statics::ClassParams = {
	&UCFR_AbilityDamageData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	UE_ARRAY_COUNT(InterfaceParams),
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AbilityDamageData_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_AbilityDamageData_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_AbilityDamageData()
{
	if (!Z_Registration_Info_UClass_UCFR_AbilityDamageData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_AbilityDamageData.OuterSingleton, Z_Construct_UClass_UCFR_AbilityDamageData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_AbilityDamageData.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_AbilityDamageData>()
{
	return UCFR_AbilityDamageData::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_AbilityDamageData);
UCFR_AbilityDamageData::~UCFR_AbilityDamageData() {}
// End Class UCFR_AbilityDamageData

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilityDamageData_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_AbilityDamageData, UCFR_AbilityDamageData::StaticClass, TEXT("UCFR_AbilityDamageData"), &Z_Registration_Info_UClass_UCFR_AbilityDamageData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_AbilityDamageData), 497318384U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilityDamageData_h_2875379155(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilityDamageData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilityDamageData_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
