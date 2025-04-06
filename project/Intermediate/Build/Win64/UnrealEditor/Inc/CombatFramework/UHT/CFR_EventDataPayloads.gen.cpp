// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/CFR_EventDataPayloads.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_EventDataPayloads() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AbilitySourceDataInterface_NoRegister();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_DamageEventDataAsset();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_DamageEventDataAsset_NoRegister();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_EventDataAsset();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_EventDataAsset_NoRegister();
COMBATFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FCFR_EffectContextContainer();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_UCurveTable_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffect_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_EventDataAsset
void UCFR_EventDataAsset::StaticRegisterNativesUCFR_EventDataAsset()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_EventDataAsset);
UClass* Z_Construct_UClass_UCFR_EventDataAsset_NoRegister()
{
	return UCFR_EventDataAsset::StaticClass();
}
struct Z_Construct_UClass_UCFR_EventDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AbilitySystem/CFR_EventDataPayloads.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_EventDataPayloads.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventTag_MetaData[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_EventDataPayloads.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_EventDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_EventDataAsset_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_EventDataAsset, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventTag_MetaData), NewProp_EventTag_MetaData) }; // 1298103297
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCFR_EventDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_EventDataAsset_Statics::NewProp_EventTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_EventDataAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCFR_EventDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_EventDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_EventDataAsset_Statics::ClassParams = {
	&UCFR_EventDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCFR_EventDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_EventDataAsset_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_EventDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_EventDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_EventDataAsset()
{
	if (!Z_Registration_Info_UClass_UCFR_EventDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_EventDataAsset.OuterSingleton, Z_Construct_UClass_UCFR_EventDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_EventDataAsset.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_EventDataAsset>()
{
	return UCFR_EventDataAsset::StaticClass();
}
UCFR_EventDataAsset::UCFR_EventDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_EventDataAsset);
UCFR_EventDataAsset::~UCFR_EventDataAsset() {}
// End Class UCFR_EventDataAsset

// Begin ScriptStruct FCFR_EffectContextContainer
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CFR_EffectContextContainer;
class UScriptStruct* FCFR_EffectContextContainer::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CFR_EffectContextContainer.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CFR_EffectContextContainer.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCFR_EffectContextContainer, (UObject*)Z_Construct_UPackage__Script_CombatFramework(), TEXT("CFR_EffectContextContainer"));
	}
	return Z_Registration_Info_UScriptStruct_CFR_EffectContextContainer.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UScriptStruct* StaticStruct<FCFR_EffectContextContainer>()
{
	return FCFR_EffectContextContainer::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_EventDataPayloads.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EffectToApply_MetaData[] = {
		{ "Category", "CFR_EffectContextContainer" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_EventDataPayloads.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Payload_MetaData[] = {
		{ "Category", "CFR_EffectContextContainer" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_EventDataPayloads.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_EffectToApply;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Payload;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCFR_EffectContextContainer>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::NewProp_EffectToApply = { "EffectToApply", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCFR_EffectContextContainer, EffectToApply), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayEffect_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EffectToApply_MetaData), NewProp_EffectToApply_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::NewProp_Payload = { "Payload", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCFR_EffectContextContainer, Payload), Z_Construct_UClass_UCFR_EventDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Payload_MetaData), NewProp_Payload_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::NewProp_EffectToApply,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::NewProp_Payload,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
	nullptr,
	&NewStructOps,
	"CFR_EffectContextContainer",
	Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::PropPointers),
	sizeof(FCFR_EffectContextContainer),
	alignof(FCFR_EffectContextContainer),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCFR_EffectContextContainer()
{
	if (!Z_Registration_Info_UScriptStruct_CFR_EffectContextContainer.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CFR_EffectContextContainer.InnerSingleton, Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CFR_EffectContextContainer.InnerSingleton;
}
// End ScriptStruct FCFR_EffectContextContainer

// Begin Class UCFR_DamageEventDataAsset
void UCFR_DamageEventDataAsset::StaticRegisterNativesUCFR_DamageEventDataAsset()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_DamageEventDataAsset);
UClass* Z_Construct_UClass_UCFR_DamageEventDataAsset_NoRegister()
{
	return UCFR_DamageEventDataAsset::StaticClass();
}
struct Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "AbilitySystem/CFR_EventDataPayloads.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_EventDataPayloads.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "CFR_DamageEventDataAsset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// TODO: Table information about the damage to apply.\n" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_EventDataPayloads.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "TODO: Table information about the damage to apply." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageCurveName_MetaData[] = {
		{ "Category", "CFR_DamageEventDataAsset" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_EventDataPayloads.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeScalingCurveName_MetaData[] = {
		{ "Category", "CFR_DamageEventDataAsset" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_EventDataPayloads.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageLevelCurve_MetaData[] = {
		{ "Category", "CFR_DamageEventDataAsset" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_EventDataPayloads.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DamageCurveName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_AttributeScalingCurveName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageLevelCurve;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_DamageEventDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_DamageEventDataAsset, Damage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::NewProp_DamageCurveName = { "DamageCurveName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_DamageEventDataAsset, DamageCurveName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageCurveName_MetaData), NewProp_DamageCurveName_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::NewProp_AttributeScalingCurveName = { "AttributeScalingCurveName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_DamageEventDataAsset, AttributeScalingCurveName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeScalingCurveName_MetaData), NewProp_AttributeScalingCurveName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::NewProp_DamageLevelCurve = { "DamageLevelCurve", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_DamageEventDataAsset, DamageLevelCurve), Z_Construct_UClass_UCurveTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageLevelCurve_MetaData), NewProp_DamageLevelCurve_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::NewProp_DamageCurveName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::NewProp_AttributeScalingCurveName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::NewProp_DamageLevelCurve,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCFR_EventDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UCFR_AbilitySourceDataInterface_NoRegister, (int32)VTABLE_OFFSET(UCFR_DamageEventDataAsset, ICFR_AbilitySourceDataInterface), false },  // 1143518693
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::ClassParams = {
	&UCFR_DamageEventDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_DamageEventDataAsset()
{
	if (!Z_Registration_Info_UClass_UCFR_DamageEventDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_DamageEventDataAsset.OuterSingleton, Z_Construct_UClass_UCFR_DamageEventDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_DamageEventDataAsset.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_DamageEventDataAsset>()
{
	return UCFR_DamageEventDataAsset::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_DamageEventDataAsset);
UCFR_DamageEventDataAsset::~UCFR_DamageEventDataAsset() {}
// End Class UCFR_DamageEventDataAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCFR_EffectContextContainer::StaticStruct, Z_Construct_UScriptStruct_FCFR_EffectContextContainer_Statics::NewStructOps, TEXT("CFR_EffectContextContainer"), &Z_Registration_Info_UScriptStruct_CFR_EffectContextContainer, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCFR_EffectContextContainer), 1774026666U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_EventDataAsset, UCFR_EventDataAsset::StaticClass, TEXT("UCFR_EventDataAsset"), &Z_Registration_Info_UClass_UCFR_EventDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_EventDataAsset), 1602594695U) },
		{ Z_Construct_UClass_UCFR_DamageEventDataAsset, UCFR_DamageEventDataAsset::StaticClass, TEXT("UCFR_DamageEventDataAsset"), &Z_Registration_Info_UClass_UCFR_DamageEventDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_DamageEventDataAsset), 2668603695U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_2471713596(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_EventDataPayloads_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
