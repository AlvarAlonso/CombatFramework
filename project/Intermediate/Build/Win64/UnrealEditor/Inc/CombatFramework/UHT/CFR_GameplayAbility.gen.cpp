// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/CFR_GameplayAbility.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_GameplayAbility() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_GameplayAbility();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_GameplayAbility_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_GameplayAbility
void UCFR_GameplayAbility::StaticRegisterNativesUCFR_GameplayAbility()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_GameplayAbility);
UClass* Z_Construct_UClass_UCFR_GameplayAbility_NoRegister()
{
	return UCFR_GameplayAbility::StaticClass();
}
struct Z_Construct_UClass_UCFR_GameplayAbility_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AbilitySystem/CFR_GameplayAbility.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_GameplayAbility.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_GameplayAbility>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCFR_GameplayAbility_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_GameplayAbility_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_GameplayAbility_Statics::ClassParams = {
	&UCFR_GameplayAbility::StaticClass,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_GameplayAbility_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_GameplayAbility_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_GameplayAbility()
{
	if (!Z_Registration_Info_UClass_UCFR_GameplayAbility.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_GameplayAbility.OuterSingleton, Z_Construct_UClass_UCFR_GameplayAbility_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_GameplayAbility.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_GameplayAbility>()
{
	return UCFR_GameplayAbility::StaticClass();
}
UCFR_GameplayAbility::UCFR_GameplayAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_GameplayAbility);
UCFR_GameplayAbility::~UCFR_GameplayAbility() {}
// End Class UCFR_GameplayAbility

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_GameplayAbility, UCFR_GameplayAbility::StaticClass, TEXT("UCFR_GameplayAbility"), &Z_Registration_Info_UClass_UCFR_GameplayAbility, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_GameplayAbility), 4125870077U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h_768939064(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_GameplayAbility_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
