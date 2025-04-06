// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/Components/CFR_HitboxesManagerComponent.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_HitboxesManagerComponent() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_HitboxComponent_NoRegister();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_HitboxesManagerComponent();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_HitboxesManagerComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_HitboxesManagerComponent Function AddHitboxToMap
struct Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics
{
	struct CFR_HitboxesManagerComponent_eventAddHitboxToMap_Parms
	{
		FGameplayTag IdentifierTag;
		UCFR_HitboxComponent* HitboxComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxesManagerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitboxComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_IdentifierTag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitboxComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::NewProp_IdentifierTag = { "IdentifierTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxesManagerComponent_eventAddHitboxToMap_Parms, IdentifierTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::NewProp_HitboxComponent = { "HitboxComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxesManagerComponent_eventAddHitboxToMap_Parms, HitboxComponent), Z_Construct_UClass_UCFR_HitboxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitboxComponent_MetaData), NewProp_HitboxComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::NewProp_IdentifierTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::NewProp_HitboxComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_HitboxesManagerComponent, nullptr, "AddHitboxToMap", nullptr, nullptr, Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::CFR_HitboxesManagerComponent_eventAddHitboxToMap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::CFR_HitboxesManagerComponent_eventAddHitboxToMap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_HitboxesManagerComponent::execAddHitboxToMap)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_IdentifierTag);
	P_GET_OBJECT(UCFR_HitboxComponent,Z_Param_HitboxComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddHitboxToMap(Z_Param_IdentifierTag,Z_Param_HitboxComponent);
	P_NATIVE_END;
}
// End Class UCFR_HitboxesManagerComponent Function AddHitboxToMap

// Begin Class UCFR_HitboxesManagerComponent Function GetHitboxByTag
struct Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics
{
	struct CFR_HitboxesManagerComponent_eventGetHitboxByTag_Parms
	{
		FGameplayTag IdentifierTag;
		UCFR_HitboxComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxesManagerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_IdentifierTag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::NewProp_IdentifierTag = { "IdentifierTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxesManagerComponent_eventGetHitboxByTag_Parms, IdentifierTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxesManagerComponent_eventGetHitboxByTag_Parms, ReturnValue), Z_Construct_UClass_UCFR_HitboxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::NewProp_IdentifierTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_HitboxesManagerComponent, nullptr, "GetHitboxByTag", nullptr, nullptr, Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::CFR_HitboxesManagerComponent_eventGetHitboxByTag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::CFR_HitboxesManagerComponent_eventGetHitboxByTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_HitboxesManagerComponent::execGetHitboxByTag)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_IdentifierTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCFR_HitboxComponent**)Z_Param__Result=P_THIS->GetHitboxByTag(Z_Param_IdentifierTag);
	P_NATIVE_END;
}
// End Class UCFR_HitboxesManagerComponent Function GetHitboxByTag

// Begin Class UCFR_HitboxesManagerComponent
void UCFR_HitboxesManagerComponent::StaticRegisterNativesUCFR_HitboxesManagerComponent()
{
	UClass* Class = UCFR_HitboxesManagerComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddHitboxToMap", &UCFR_HitboxesManagerComponent::execAddHitboxToMap },
		{ "GetHitboxByTag", &UCFR_HitboxesManagerComponent::execGetHitboxByTag },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_HitboxesManagerComponent);
UClass* Z_Construct_UClass_UCFR_HitboxesManagerComponent_NoRegister()
{
	return UCFR_HitboxesManagerComponent::StaticClass();
}
struct Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Components/CFR_HitboxesManagerComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxesManagerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitboxesMap_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxesManagerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitboxesMap_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitboxesMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_HitboxesMap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCFR_HitboxesManagerComponent_AddHitboxToMap, "AddHitboxToMap" }, // 2020297267
		{ &Z_Construct_UFunction_UCFR_HitboxesManagerComponent_GetHitboxByTag, "GetHitboxByTag" }, // 726672267
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_HitboxesManagerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::NewProp_HitboxesMap_ValueProp = { "HitboxesMap", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UCFR_HitboxComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::NewProp_HitboxesMap_Key_KeyProp = { "HitboxesMap_Key", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::NewProp_HitboxesMap = { "HitboxesMap", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_HitboxesManagerComponent, HitboxesMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitboxesMap_MetaData), NewProp_HitboxesMap_MetaData) }; // 1298103297
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::NewProp_HitboxesMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::NewProp_HitboxesMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::NewProp_HitboxesMap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::ClassParams = {
	&UCFR_HitboxesManagerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_HitboxesManagerComponent()
{
	if (!Z_Registration_Info_UClass_UCFR_HitboxesManagerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_HitboxesManagerComponent.OuterSingleton, Z_Construct_UClass_UCFR_HitboxesManagerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_HitboxesManagerComponent.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_HitboxesManagerComponent>()
{
	return UCFR_HitboxesManagerComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_HitboxesManagerComponent);
UCFR_HitboxesManagerComponent::~UCFR_HitboxesManagerComponent() {}
// End Class UCFR_HitboxesManagerComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_HitboxesManagerComponent, UCFR_HitboxesManagerComponent::StaticClass, TEXT("UCFR_HitboxesManagerComponent"), &Z_Registration_Info_UClass_UCFR_HitboxesManagerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_HitboxesManagerComponent), 3426373124U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_3451709013(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxesManagerComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
