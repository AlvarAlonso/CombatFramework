// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/Characters/CFR_CharacterBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_CharacterBase() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UGenericTeamAgentInterface_NoRegister();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_CharacterBase();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_CharacterBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAttributeSet_NoRegister();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class ACFR_CharacterBase Function GetHealth
struct Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics
{
	struct CFR_CharacterBase_eventGetHealth_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/CFR_CharacterBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_CharacterBase_eventGetHealth_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACFR_CharacterBase, nullptr, "GetHealth", nullptr, nullptr, Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::CFR_CharacterBase_eventGetHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::CFR_CharacterBase_eventGetHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACFR_CharacterBase_GetHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACFR_CharacterBase_GetHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACFR_CharacterBase::execGetHealth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetHealth();
	P_NATIVE_END;
}
// End Class ACFR_CharacterBase Function GetHealth

// Begin Class ACFR_CharacterBase Function GetMaxHealth
struct Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics
{
	struct CFR_CharacterBase_eventGetMaxHealth_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/CFR_CharacterBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_CharacterBase_eventGetMaxHealth_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACFR_CharacterBase, nullptr, "GetMaxHealth", nullptr, nullptr, Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::CFR_CharacterBase_eventGetMaxHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::CFR_CharacterBase_eventGetMaxHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACFR_CharacterBase::execGetMaxHealth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetMaxHealth();
	P_NATIVE_END;
}
// End Class ACFR_CharacterBase Function GetMaxHealth

// Begin Class ACFR_CharacterBase
void ACFR_CharacterBase::StaticRegisterNativesACFR_CharacterBase()
{
	UClass* Class = ACFR_CharacterBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetHealth", &ACFR_CharacterBase::execGetHealth },
		{ "GetMaxHealth", &ACFR_CharacterBase::execGetMaxHealth },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACFR_CharacterBase);
UClass* Z_Construct_UClass_ACFR_CharacterBase_NoRegister()
{
	return ACFR_CharacterBase::StaticClass();
}
struct Z_Construct_UClass_ACFR_CharacterBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/CFR_CharacterBase.h" },
		{ "ModuleRelativePath", "Public/Characters/CFR_CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/CFR_CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeSet_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/CFR_CharacterBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeSet;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACFR_CharacterBase_GetHealth, "GetHealth" }, // 1441656194
		{ &Z_Construct_UFunction_ACFR_CharacterBase_GetMaxHealth, "GetMaxHealth" }, // 2552692454
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACFR_CharacterBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACFR_CharacterBase_Statics::NewProp_AbilitySystemComponent = { "AbilitySystemComponent", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACFR_CharacterBase, AbilitySystemComponent), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystemComponent_MetaData), NewProp_AbilitySystemComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACFR_CharacterBase_Statics::NewProp_AttributeSet = { "AttributeSet", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACFR_CharacterBase, AttributeSet), Z_Construct_UClass_UAttributeSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeSet_MetaData), NewProp_AttributeSet_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACFR_CharacterBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACFR_CharacterBase_Statics::NewProp_AbilitySystemComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACFR_CharacterBase_Statics::NewProp_AttributeSet,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_CharacterBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACFR_CharacterBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_CharacterBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ACFR_CharacterBase_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(ACFR_CharacterBase, IAbilitySystemInterface), false },  // 2272790346
	{ Z_Construct_UClass_UGenericTeamAgentInterface_NoRegister, (int32)VTABLE_OFFSET(ACFR_CharacterBase, IGenericTeamAgentInterface), false },  // 1380835789
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACFR_CharacterBase_Statics::ClassParams = {
	&ACFR_CharacterBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACFR_CharacterBase_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_CharacterBase_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_CharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ACFR_CharacterBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACFR_CharacterBase()
{
	if (!Z_Registration_Info_UClass_ACFR_CharacterBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACFR_CharacterBase.OuterSingleton, Z_Construct_UClass_ACFR_CharacterBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACFR_CharacterBase.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<ACFR_CharacterBase>()
{
	return ACFR_CharacterBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACFR_CharacterBase);
ACFR_CharacterBase::~ACFR_CharacterBase() {}
// End Class ACFR_CharacterBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACFR_CharacterBase, ACFR_CharacterBase::StaticClass, TEXT("ACFR_CharacterBase"), &Z_Registration_Info_UClass_ACFR_CharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACFR_CharacterBase), 364647011U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_590889650(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_CharacterBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
