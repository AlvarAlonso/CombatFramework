// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/GameplayEffects/CFR_InstantDeathEffect.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_InstantDeathEffect() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_InstantDeathEffect();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_InstantDeathEffect_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffect();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_InstantDeathEffect
void UCFR_InstantDeathEffect::StaticRegisterNativesUCFR_InstantDeathEffect()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_InstantDeathEffect);
UClass* Z_Construct_UClass_UCFR_InstantDeathEffect_NoRegister()
{
	return UCFR_InstantDeathEffect::StaticClass();
}
struct Z_Construct_UClass_UCFR_InstantDeathEffect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AbilitySystem/GameplayEffects/CFR_InstantDeathEffect.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayEffects/CFR_InstantDeathEffect.h" },
		{ "PrioritizeCategories", "Status Duration GameplayEffect GameplayCues Stacking" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_InstantDeathEffect>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCFR_InstantDeathEffect_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayEffect,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_InstantDeathEffect_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_InstantDeathEffect_Statics::ClassParams = {
	&UCFR_InstantDeathEffect::StaticClass,
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
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_InstantDeathEffect_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_InstantDeathEffect_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_InstantDeathEffect()
{
	if (!Z_Registration_Info_UClass_UCFR_InstantDeathEffect.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_InstantDeathEffect.OuterSingleton, Z_Construct_UClass_UCFR_InstantDeathEffect_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_InstantDeathEffect.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_InstantDeathEffect>()
{
	return UCFR_InstantDeathEffect::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_InstantDeathEffect);
UCFR_InstantDeathEffect::~UCFR_InstantDeathEffect() {}
// End Class UCFR_InstantDeathEffect

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_InstantDeathEffect_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_InstantDeathEffect, UCFR_InstantDeathEffect::StaticClass, TEXT("UCFR_InstantDeathEffect"), &Z_Registration_Info_UClass_UCFR_InstantDeathEffect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_InstantDeathEffect), 3299243040U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_InstantDeathEffect_h_2704148668(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_InstantDeathEffect_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_InstantDeathEffect_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
