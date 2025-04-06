// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/GameplayEffects/CFR_Execution_Damage.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_Execution_Damage() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_Execution_Damage();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_Execution_Damage_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffectExecutionCalculation();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_Execution_Damage
void UCFR_Execution_Damage::StaticRegisterNativesUCFR_Execution_Damage()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_Execution_Damage);
UClass* Z_Construct_UClass_UCFR_Execution_Damage_NoRegister()
{
	return UCFR_Execution_Damage::StaticClass();
}
struct Z_Construct_UClass_UCFR_Execution_Damage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AbilitySystem/GameplayEffects/CFR_Execution_Damage.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayEffects/CFR_Execution_Damage.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_Execution_Damage>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCFR_Execution_Damage_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayEffectExecutionCalculation,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_Execution_Damage_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_Execution_Damage_Statics::ClassParams = {
	&UCFR_Execution_Damage::StaticClass,
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
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_Execution_Damage_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_Execution_Damage_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_Execution_Damage()
{
	if (!Z_Registration_Info_UClass_UCFR_Execution_Damage.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_Execution_Damage.OuterSingleton, Z_Construct_UClass_UCFR_Execution_Damage_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_Execution_Damage.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_Execution_Damage>()
{
	return UCFR_Execution_Damage::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_Execution_Damage);
UCFR_Execution_Damage::~UCFR_Execution_Damage() {}
// End Class UCFR_Execution_Damage

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_Execution_Damage_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_Execution_Damage, UCFR_Execution_Damage::StaticClass, TEXT("UCFR_Execution_Damage"), &Z_Registration_Info_UClass_UCFR_Execution_Damage, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_Execution_Damage), 1304856320U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_Execution_Damage_h_3623556690(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_Execution_Damage_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_Execution_Damage_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
