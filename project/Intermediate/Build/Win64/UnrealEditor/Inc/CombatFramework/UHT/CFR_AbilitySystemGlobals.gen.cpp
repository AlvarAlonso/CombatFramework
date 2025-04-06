// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/CFR_AbilitySystemGlobals.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_AbilitySystemGlobals() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AbilitySystemGlobals();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AbilitySystemGlobals_NoRegister();
COMBATFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FCFR_GameplayEffectContext();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemGlobals();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayEffectContext();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_AbilitySystemGlobals
void UCFR_AbilitySystemGlobals::StaticRegisterNativesUCFR_AbilitySystemGlobals()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_AbilitySystemGlobals);
UClass* Z_Construct_UClass_UCFR_AbilitySystemGlobals_NoRegister()
{
	return UCFR_AbilitySystemGlobals::StaticClass();
}
struct Z_Construct_UClass_UCFR_AbilitySystemGlobals_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AbilitySystem/CFR_AbilitySystemGlobals.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemGlobals.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_AbilitySystemGlobals>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCFR_AbilitySystemGlobals_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilitySystemGlobals,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AbilitySystemGlobals_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_AbilitySystemGlobals_Statics::ClassParams = {
	&UCFR_AbilitySystemGlobals::StaticClass,
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
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AbilitySystemGlobals_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_AbilitySystemGlobals_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_AbilitySystemGlobals()
{
	if (!Z_Registration_Info_UClass_UCFR_AbilitySystemGlobals.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_AbilitySystemGlobals.OuterSingleton, Z_Construct_UClass_UCFR_AbilitySystemGlobals_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_AbilitySystemGlobals.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_AbilitySystemGlobals>()
{
	return UCFR_AbilitySystemGlobals::StaticClass();
}
UCFR_AbilitySystemGlobals::UCFR_AbilitySystemGlobals(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_AbilitySystemGlobals);
UCFR_AbilitySystemGlobals::~UCFR_AbilitySystemGlobals() {}
// End Class UCFR_AbilitySystemGlobals

// Begin ScriptStruct FCFR_GameplayEffectContext
static_assert(std::is_polymorphic<FCFR_GameplayEffectContext>() == std::is_polymorphic<FGameplayEffectContext>(), "USTRUCT FCFR_GameplayEffectContext cannot be polymorphic unless super FGameplayEffectContext is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CFR_GameplayEffectContext;
class UScriptStruct* FCFR_GameplayEffectContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CFR_GameplayEffectContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CFR_GameplayEffectContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCFR_GameplayEffectContext, (UObject*)Z_Construct_UPackage__Script_CombatFramework(), TEXT("CFR_GameplayEffectContext"));
	}
	return Z_Registration_Info_UScriptStruct_CFR_GameplayEffectContext.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UScriptStruct* StaticStruct<FCFR_GameplayEffectContext>()
{
	return FCFR_GameplayEffectContext::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemGlobals.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySourceData_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Payload. Object with the EventDataAsset.\n" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemGlobals.h" },
		{ "NativeConstTemplateArg", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Payload. Object with the EventDataAsset." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_AbilitySourceData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCFR_GameplayEffectContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::NewProp_AbilitySourceData = { "AbilitySourceData", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCFR_GameplayEffectContext, AbilitySourceData), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySourceData_MetaData), NewProp_AbilitySourceData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::NewProp_AbilitySourceData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
	Z_Construct_UScriptStruct_FGameplayEffectContext,
	&NewStructOps,
	"CFR_GameplayEffectContext",
	Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::PropPointers),
	sizeof(FCFR_GameplayEffectContext),
	alignof(FCFR_GameplayEffectContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCFR_GameplayEffectContext()
{
	if (!Z_Registration_Info_UScriptStruct_CFR_GameplayEffectContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CFR_GameplayEffectContext.InnerSingleton, Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CFR_GameplayEffectContext.InnerSingleton;
}
// End ScriptStruct FCFR_GameplayEffectContext

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCFR_GameplayEffectContext::StaticStruct, Z_Construct_UScriptStruct_FCFR_GameplayEffectContext_Statics::NewStructOps, TEXT("CFR_GameplayEffectContext"), &Z_Registration_Info_UScriptStruct_CFR_GameplayEffectContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCFR_GameplayEffectContext), 1016822883U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_AbilitySystemGlobals, UCFR_AbilitySystemGlobals::StaticClass, TEXT("UCFR_AbilitySystemGlobals"), &Z_Registration_Info_UClass_UCFR_AbilitySystemGlobals, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_AbilitySystemGlobals), 2288939613U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_1954211591(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemGlobals_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
