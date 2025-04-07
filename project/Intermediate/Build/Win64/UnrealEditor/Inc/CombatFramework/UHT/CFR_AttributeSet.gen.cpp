// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/CFR_AttributeSet.h"
#include "GameplayAbilities/Public/AttributeSet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_AttributeSet() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AttributeSet();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AttributeSet_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAttributeSet();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAttributeData();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_AttributeSet Function OnRep_CurrentHealth
struct Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics
{
	struct CFR_AttributeSet_eventOnRep_CurrentHealth_Parms
	{
		FGameplayAttributeData OldCurrentHealth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldCurrentHealth_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OldCurrentHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::NewProp_OldCurrentHealth = { "OldCurrentHealth", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AttributeSet_eventOnRep_CurrentHealth_Parms, OldCurrentHealth), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldCurrentHealth_MetaData), NewProp_OldCurrentHealth_MetaData) }; // 675369593
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::NewProp_OldCurrentHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AttributeSet, nullptr, "OnRep_CurrentHealth", nullptr, nullptr, Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::CFR_AttributeSet_eventOnRep_CurrentHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::CFR_AttributeSet_eventOnRep_CurrentHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AttributeSet::execOnRep_CurrentHealth)
{
	P_GET_STRUCT(FGameplayAttributeData,Z_Param_OldCurrentHealth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentHealth(Z_Param_OldCurrentHealth);
	P_NATIVE_END;
}
// End Class UCFR_AttributeSet Function OnRep_CurrentHealth

// Begin Class UCFR_AttributeSet Function OnRep_CurrentMana
struct Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics
{
	struct CFR_AttributeSet_eventOnRep_CurrentMana_Parms
	{
		FGameplayAttributeData OldCurrentMana;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldCurrentMana_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OldCurrentMana;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::NewProp_OldCurrentMana = { "OldCurrentMana", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AttributeSet_eventOnRep_CurrentMana_Parms, OldCurrentMana), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldCurrentMana_MetaData), NewProp_OldCurrentMana_MetaData) }; // 675369593
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::NewProp_OldCurrentMana,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AttributeSet, nullptr, "OnRep_CurrentMana", nullptr, nullptr, Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::CFR_AttributeSet_eventOnRep_CurrentMana_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::CFR_AttributeSet_eventOnRep_CurrentMana_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AttributeSet::execOnRep_CurrentMana)
{
	P_GET_STRUCT(FGameplayAttributeData,Z_Param_OldCurrentMana);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentMana(Z_Param_OldCurrentMana);
	P_NATIVE_END;
}
// End Class UCFR_AttributeSet Function OnRep_CurrentMana

// Begin Class UCFR_AttributeSet Function OnRep_MaxHealth
struct Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics
{
	struct CFR_AttributeSet_eventOnRep_MaxHealth_Parms
	{
		FGameplayAttributeData OldMaxHealth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldMaxHealth_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OldMaxHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::NewProp_OldMaxHealth = { "OldMaxHealth", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AttributeSet_eventOnRep_MaxHealth_Parms, OldMaxHealth), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldMaxHealth_MetaData), NewProp_OldMaxHealth_MetaData) }; // 675369593
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::NewProp_OldMaxHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AttributeSet, nullptr, "OnRep_MaxHealth", nullptr, nullptr, Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::CFR_AttributeSet_eventOnRep_MaxHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::CFR_AttributeSet_eventOnRep_MaxHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AttributeSet::execOnRep_MaxHealth)
{
	P_GET_STRUCT(FGameplayAttributeData,Z_Param_OldMaxHealth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_MaxHealth(Z_Param_OldMaxHealth);
	P_NATIVE_END;
}
// End Class UCFR_AttributeSet Function OnRep_MaxHealth

// Begin Class UCFR_AttributeSet Function OnRep_MaxMana
struct Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics
{
	struct CFR_AttributeSet_eventOnRep_MaxMana_Parms
	{
		FGameplayAttributeData OldMaxMana;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldMaxMana_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OldMaxMana;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::NewProp_OldMaxMana = { "OldMaxMana", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AttributeSet_eventOnRep_MaxMana_Parms, OldMaxMana), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldMaxMana_MetaData), NewProp_OldMaxMana_MetaData) }; // 675369593
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::NewProp_OldMaxMana,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AttributeSet, nullptr, "OnRep_MaxMana", nullptr, nullptr, Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::CFR_AttributeSet_eventOnRep_MaxMana_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::CFR_AttributeSet_eventOnRep_MaxMana_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AttributeSet::execOnRep_MaxMana)
{
	P_GET_STRUCT(FGameplayAttributeData,Z_Param_OldMaxMana);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_MaxMana(Z_Param_OldMaxMana);
	P_NATIVE_END;
}
// End Class UCFR_AttributeSet Function OnRep_MaxMana

// Begin Class UCFR_AttributeSet Function OnRep_Strength
struct Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics
{
	struct CFR_AttributeSet_eventOnRep_Strength_Parms
	{
		FGameplayAttributeData OldStrength;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldStrength_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OldStrength;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::NewProp_OldStrength = { "OldStrength", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AttributeSet_eventOnRep_Strength_Parms, OldStrength), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldStrength_MetaData), NewProp_OldStrength_MetaData) }; // 675369593
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::NewProp_OldStrength,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AttributeSet, nullptr, "OnRep_Strength", nullptr, nullptr, Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::CFR_AttributeSet_eventOnRep_Strength_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::CFR_AttributeSet_eventOnRep_Strength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AttributeSet::execOnRep_Strength)
{
	P_GET_STRUCT(FGameplayAttributeData,Z_Param_OldStrength);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_Strength(Z_Param_OldStrength);
	P_NATIVE_END;
}
// End Class UCFR_AttributeSet Function OnRep_Strength

// Begin Class UCFR_AttributeSet
void UCFR_AttributeSet::StaticRegisterNativesUCFR_AttributeSet()
{
	UClass* Class = UCFR_AttributeSet::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnRep_CurrentHealth", &UCFR_AttributeSet::execOnRep_CurrentHealth },
		{ "OnRep_CurrentMana", &UCFR_AttributeSet::execOnRep_CurrentMana },
		{ "OnRep_MaxHealth", &UCFR_AttributeSet::execOnRep_MaxHealth },
		{ "OnRep_MaxMana", &UCFR_AttributeSet::execOnRep_MaxMana },
		{ "OnRep_Strength", &UCFR_AttributeSet::execOnRep_Strength },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_AttributeSet);
UClass* Z_Construct_UClass_UCFR_AttributeSet_NoRegister()
{
	return UCFR_AttributeSet::StaticClass();
}
struct Z_Construct_UClass_UCFR_AttributeSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AbilitySystem/CFR_AttributeSet.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[] = {
		{ "Category", "Base Attributes" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Base Attributes" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMana_MetaData[] = {
		{ "Category", "Base Attributes" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxMana_MetaData[] = {
		{ "Category", "Base Attributes" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Strength_MetaData[] = {
		{ "Category", "Base Attributes" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "Damage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Damage is a 'temporary' attribute used by the DamageExecution to calculate final damage, which then turns into -Health */" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AttributeSet.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Damage is a 'temporary' attribute used by the DamageExecution to calculate final damage, which then turns into -Health" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentHealth;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentMana;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxMana;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Strength;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentHealth, "OnRep_CurrentHealth" }, // 361022380
		{ &Z_Construct_UFunction_UCFR_AttributeSet_OnRep_CurrentMana, "OnRep_CurrentMana" }, // 3069385462
		{ &Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxHealth, "OnRep_MaxHealth" }, // 2789797420
		{ &Z_Construct_UFunction_UCFR_AttributeSet_OnRep_MaxMana, "OnRep_MaxMana" }, // 1399985285
		{ &Z_Construct_UFunction_UCFR_AttributeSet_OnRep_Strength, "OnRep_Strength" }, // 504367498
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_AttributeSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_CurrentHealth = { "CurrentHealth", "OnRep_CurrentHealth", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_AttributeSet, CurrentHealth), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHealth_MetaData), NewProp_CurrentHealth_MetaData) }; // 675369593
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_MaxHealth = { "MaxHealth", "OnRep_MaxHealth", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_AttributeSet, MaxHealth), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) }; // 675369593
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_CurrentMana = { "CurrentMana", "OnRep_CurrentMana", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_AttributeSet, CurrentMana), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMana_MetaData), NewProp_CurrentMana_MetaData) }; // 675369593
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_MaxMana = { "MaxMana", "OnRep_MaxMana", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_AttributeSet, MaxMana), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxMana_MetaData), NewProp_MaxMana_MetaData) }; // 675369593
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_Strength = { "Strength", "OnRep_Strength", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_AttributeSet, Strength), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Strength_MetaData), NewProp_Strength_MetaData) }; // 675369593
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_AttributeSet, Damage), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) }; // 675369593
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCFR_AttributeSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_CurrentHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_MaxHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_CurrentMana,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_MaxMana,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_Strength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AttributeSet_Statics::NewProp_Damage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AttributeSet_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCFR_AttributeSet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAttributeSet,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AttributeSet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_AttributeSet_Statics::ClassParams = {
	&UCFR_AttributeSet::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCFR_AttributeSet_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AttributeSet_Statics::PropPointers),
	0,
	0x003000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AttributeSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_AttributeSet_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_AttributeSet()
{
	if (!Z_Registration_Info_UClass_UCFR_AttributeSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_AttributeSet.OuterSingleton, Z_Construct_UClass_UCFR_AttributeSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_AttributeSet.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_AttributeSet>()
{
	return UCFR_AttributeSet::StaticClass();
}
void UCFR_AttributeSet::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_CurrentHealth(TEXT("CurrentHealth"));
	static const FName Name_MaxHealth(TEXT("MaxHealth"));
	static const FName Name_CurrentMana(TEXT("CurrentMana"));
	static const FName Name_MaxMana(TEXT("MaxMana"));
	static const FName Name_Strength(TEXT("Strength"));
	const bool bIsValid = true
		&& Name_CurrentHealth == ClassReps[(int32)ENetFields_Private::CurrentHealth].Property->GetFName()
		&& Name_MaxHealth == ClassReps[(int32)ENetFields_Private::MaxHealth].Property->GetFName()
		&& Name_CurrentMana == ClassReps[(int32)ENetFields_Private::CurrentMana].Property->GetFName()
		&& Name_MaxMana == ClassReps[(int32)ENetFields_Private::MaxMana].Property->GetFName()
		&& Name_Strength == ClassReps[(int32)ENetFields_Private::Strength].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UCFR_AttributeSet"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_AttributeSet);
UCFR_AttributeSet::~UCFR_AttributeSet() {}
// End Class UCFR_AttributeSet

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_AttributeSet, UCFR_AttributeSet::StaticClass, TEXT("UCFR_AttributeSet"), &Z_Registration_Info_UClass_UCFR_AttributeSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_AttributeSet), 2436695681U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_3731494537(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AttributeSet_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
