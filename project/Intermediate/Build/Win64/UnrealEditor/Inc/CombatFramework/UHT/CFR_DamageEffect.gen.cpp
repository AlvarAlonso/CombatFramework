// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/GameplayEffects/CFR_DamageEffect.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_DamageEffect() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_DamageEffect();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_DamageEffect_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffect();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_DamageEffect
void UCFR_DamageEffect::StaticRegisterNativesUCFR_DamageEffect()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_DamageEffect);
UClass* Z_Construct_UClass_UCFR_DamageEffect_NoRegister()
{
	return UCFR_DamageEffect::StaticClass();
}
struct Z_Construct_UClass_UCFR_DamageEffect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AbilitySystem/GameplayEffects/CFR_DamageEffect.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayEffects/CFR_DamageEffect.h" },
		{ "PrioritizeCategories", "Status Duration GameplayEffect GameplayCues Stacking" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "CFR_DamageEffect" },
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayEffects/CFR_DamageEffect.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_DamageEffect>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCFR_DamageEffect_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_DamageEffect, Damage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCFR_DamageEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_DamageEffect_Statics::NewProp_Damage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_DamageEffect_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCFR_DamageEffect_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayEffect,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_DamageEffect_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_DamageEffect_Statics::ClassParams = {
	&UCFR_DamageEffect::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCFR_DamageEffect_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_DamageEffect_Statics::PropPointers),
	0,
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_DamageEffect_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_DamageEffect_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_DamageEffect()
{
	if (!Z_Registration_Info_UClass_UCFR_DamageEffect.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_DamageEffect.OuterSingleton, Z_Construct_UClass_UCFR_DamageEffect_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_DamageEffect.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_DamageEffect>()
{
	return UCFR_DamageEffect::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_DamageEffect);
UCFR_DamageEffect::~UCFR_DamageEffect() {}
// End Class UCFR_DamageEffect

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_DamageEffect_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_DamageEffect, UCFR_DamageEffect::StaticClass, TEXT("UCFR_DamageEffect"), &Z_Registration_Info_UClass_UCFR_DamageEffect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_DamageEffect), 116704910U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_DamageEffect_h_4060061028(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_DamageEffect_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayEffects_CFR_DamageEffect_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
