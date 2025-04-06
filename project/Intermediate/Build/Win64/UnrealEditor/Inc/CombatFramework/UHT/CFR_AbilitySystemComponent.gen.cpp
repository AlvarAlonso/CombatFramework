// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/CFR_AbilitySystemComponent.h"
#include "GameplayAbilities/Public/GameplayAbilitySpecHandle.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_AbilitySystemComponent() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AbilitySystemComponent();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_AbilitySystemComponent_NoRegister();
COMBATFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FCFR_AbilityInitData();
COMBATFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FCFR_AbilityInputBinding();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UEnhancedInputComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffect_NoRegister();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAbilitySpecHandle();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin ScriptStruct FCFR_AbilityInitData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CFR_AbilityInitData;
class UScriptStruct* FCFR_AbilityInitData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CFR_AbilityInitData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CFR_AbilityInitData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCFR_AbilityInitData, (UObject*)Z_Construct_UPackage__Script_CombatFramework(), TEXT("CFR_AbilityInitData"));
	}
	return Z_Registration_Info_UScriptStruct_CFR_AbilityInitData.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UScriptStruct* StaticStruct<FCFR_AbilityInitData>()
{
	return FCFR_AbilityInitData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputAction_MetaData[] = {
		{ "Category", "CFR_AbilityInitData" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ability_MetaData[] = {
		{ "Category", "CFR_AbilityInitData" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputAction;
	static const UECodeGen_Private::FClassPropertyParams NewProp_Ability;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCFR_AbilityInitData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::NewProp_InputAction = { "InputAction", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCFR_AbilityInitData, InputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputAction_MetaData), NewProp_InputAction_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::NewProp_Ability = { "Ability", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCFR_AbilityInitData, Ability), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ability_MetaData), NewProp_Ability_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::NewProp_InputAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::NewProp_Ability,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
	nullptr,
	&NewStructOps,
	"CFR_AbilityInitData",
	Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::PropPointers),
	sizeof(FCFR_AbilityInitData),
	alignof(FCFR_AbilityInitData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCFR_AbilityInitData()
{
	if (!Z_Registration_Info_UScriptStruct_CFR_AbilityInitData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CFR_AbilityInitData.InnerSingleton, Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CFR_AbilityInitData.InnerSingleton;
}
// End ScriptStruct FCFR_AbilityInitData

// Begin ScriptStruct FCFR_AbilityInputBinding
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CFR_AbilityInputBinding;
class UScriptStruct* FCFR_AbilityInputBinding::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CFR_AbilityInputBinding.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CFR_AbilityInputBinding.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCFR_AbilityInputBinding, (UObject*)Z_Construct_UPackage__Script_CombatFramework(), TEXT("CFR_AbilityInputBinding"));
	}
	return Z_Registration_Info_UScriptStruct_CFR_AbilityInputBinding.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UScriptStruct* StaticStruct<FCFR_AbilityInputBinding>()
{
	return FCFR_AbilityInputBinding::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCFR_AbilityInputBinding_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCFR_AbilityInputBinding>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCFR_AbilityInputBinding_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
	nullptr,
	&NewStructOps,
	"CFR_AbilityInputBinding",
	nullptr,
	0,
	sizeof(FCFR_AbilityInputBinding),
	alignof(FCFR_AbilityInputBinding),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCFR_AbilityInputBinding_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCFR_AbilityInputBinding_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCFR_AbilityInputBinding()
{
	if (!Z_Registration_Info_UScriptStruct_CFR_AbilityInputBinding.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CFR_AbilityInputBinding.InnerSingleton, Z_Construct_UScriptStruct_FCFR_AbilityInputBinding_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CFR_AbilityInputBinding.InnerSingleton;
}
// End ScriptStruct FCFR_AbilityInputBinding

// Begin Class UCFR_AbilitySystemComponent Function AddUniqueLooseGameplayTag
struct Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics
{
	struct CFR_AbilitySystemComponent_eventAddUniqueLooseGameplayTag_Parms
	{
		FGameplayTag GameplayTag;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Gameplay Tags*/// Add a stack of the tag only if it is not already added.\n" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gameplay Tags// Add a stack of the tag only if it is not already added." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameplayTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GameplayTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::NewProp_GameplayTag = { "GameplayTag", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventAddUniqueLooseGameplayTag_Parms, GameplayTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameplayTag_MetaData), NewProp_GameplayTag_MetaData) }; // 1298103297
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::NewProp_GameplayTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AbilitySystemComponent, nullptr, "AddUniqueLooseGameplayTag", nullptr, nullptr, Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::CFR_AbilitySystemComponent_eventAddUniqueLooseGameplayTag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::CFR_AbilitySystemComponent_eventAddUniqueLooseGameplayTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AbilitySystemComponent::execAddUniqueLooseGameplayTag)
{
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_GameplayTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddUniqueLooseGameplayTag(Z_Param_Out_GameplayTag);
	P_NATIVE_END;
}
// End Class UCFR_AbilitySystemComponent Function AddUniqueLooseGameplayTag

// Begin Class UCFR_AbilitySystemComponent Function GrantAbilityOfType
struct Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics
{
	struct CFR_AbilitySystemComponent_eventGrantAbilityOfType_Parms
	{
		TSubclassOf<UGameplayAbility> AbilityType;
		bool bRemoveAfterActivation;
		FGameplayAbilitySpecHandle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Can add abilities in game. */" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Can add abilities in game." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_AbilityType;
	static void NewProp_bRemoveAfterActivation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRemoveAfterActivation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::NewProp_AbilityType = { "AbilityType", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventGrantAbilityOfType_Parms, AbilityType), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::NewProp_bRemoveAfterActivation_SetBit(void* Obj)
{
	((CFR_AbilitySystemComponent_eventGrantAbilityOfType_Parms*)Obj)->bRemoveAfterActivation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::NewProp_bRemoveAfterActivation = { "bRemoveAfterActivation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CFR_AbilitySystemComponent_eventGrantAbilityOfType_Parms), &Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::NewProp_bRemoveAfterActivation_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventGrantAbilityOfType_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayAbilitySpecHandle, METADATA_PARAMS(0, nullptr) }; // 3490030742
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::NewProp_AbilityType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::NewProp_bRemoveAfterActivation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AbilitySystemComponent, nullptr, "GrantAbilityOfType", nullptr, nullptr, Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::CFR_AbilitySystemComponent_eventGrantAbilityOfType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::CFR_AbilitySystemComponent_eventGrantAbilityOfType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AbilitySystemComponent::execGrantAbilityOfType)
{
	P_GET_OBJECT(UClass,Z_Param_AbilityType);
	P_GET_UBOOL(Z_Param_bRemoveAfterActivation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayAbilitySpecHandle*)Z_Param__Result=P_THIS->GrantAbilityOfType(Z_Param_AbilityType,Z_Param_bRemoveAfterActivation);
	P_NATIVE_END;
}
// End Class UCFR_AbilitySystemComponent Function GrantAbilityOfType

// Begin Class UCFR_AbilitySystemComponent Function K2_AddLooseGameplayTag
struct Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics
{
	struct CFR_AbilitySystemComponent_eventK2_AddLooseGameplayTag_Parms
	{
		FGameplayTag GameplayTag;
		int32 Count;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Exposes AddLooseGameplayTag to Blueprint. This tag is *not* replicated.\n" },
#endif
		{ "CPP_Default_Count", "1" },
		{ "DisplayName", "AddLooseGameplayTag" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exposes AddLooseGameplayTag to Blueprint. This tag is *not* replicated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameplayTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GameplayTag;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::NewProp_GameplayTag = { "GameplayTag", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventK2_AddLooseGameplayTag_Parms, GameplayTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameplayTag_MetaData), NewProp_GameplayTag_MetaData) }; // 1298103297
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventK2_AddLooseGameplayTag_Parms, Count), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::NewProp_GameplayTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::NewProp_Count,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AbilitySystemComponent, nullptr, "K2_AddLooseGameplayTag", nullptr, nullptr, Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::CFR_AbilitySystemComponent_eventK2_AddLooseGameplayTag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::CFR_AbilitySystemComponent_eventK2_AddLooseGameplayTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AbilitySystemComponent::execK2_AddLooseGameplayTag)
{
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_GameplayTag);
	P_GET_PROPERTY(FIntProperty,Z_Param_Count);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->K2_AddLooseGameplayTag(Z_Param_Out_GameplayTag,Z_Param_Count);
	P_NATIVE_END;
}
// End Class UCFR_AbilitySystemComponent Function K2_AddLooseGameplayTag

// Begin Class UCFR_AbilitySystemComponent Function K2_AddLooseGameplayTags
struct Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics
{
	struct CFR_AbilitySystemComponent_eventK2_AddLooseGameplayTags_Parms
	{
		FGameplayTagContainer GameplayTags;
		int32 Count;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Exposes AddLooseGameplayTags to Blueprint. These tags are *not* replicated.\n" },
#endif
		{ "CPP_Default_Count", "1" },
		{ "DisplayName", "AddLooseGameplayTags" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exposes AddLooseGameplayTags to Blueprint. These tags are *not* replicated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameplayTags_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GameplayTags;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::NewProp_GameplayTags = { "GameplayTags", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventK2_AddLooseGameplayTags_Parms, GameplayTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameplayTags_MetaData), NewProp_GameplayTags_MetaData) }; // 3352185621
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventK2_AddLooseGameplayTags_Parms, Count), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::NewProp_GameplayTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::NewProp_Count,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AbilitySystemComponent, nullptr, "K2_AddLooseGameplayTags", nullptr, nullptr, Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::CFR_AbilitySystemComponent_eventK2_AddLooseGameplayTags_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::CFR_AbilitySystemComponent_eventK2_AddLooseGameplayTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AbilitySystemComponent::execK2_AddLooseGameplayTags)
{
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_GameplayTags);
	P_GET_PROPERTY(FIntProperty,Z_Param_Count);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->K2_AddLooseGameplayTags(Z_Param_Out_GameplayTags,Z_Param_Count);
	P_NATIVE_END;
}
// End Class UCFR_AbilitySystemComponent Function K2_AddLooseGameplayTags

// Begin Class UCFR_AbilitySystemComponent Function K2_RemoveLooseGameplayTag
struct Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics
{
	struct CFR_AbilitySystemComponent_eventK2_RemoveLooseGameplayTag_Parms
	{
		FGameplayTag GameplayTag;
		int32 Count;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Exposes RemoveLooseGameplayTag to Blueprint. This tag is *not* replicated.\n" },
#endif
		{ "CPP_Default_Count", "1" },
		{ "DisplayName", "RemoveLooseGameplayTag" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exposes RemoveLooseGameplayTag to Blueprint. This tag is *not* replicated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameplayTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GameplayTag;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::NewProp_GameplayTag = { "GameplayTag", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventK2_RemoveLooseGameplayTag_Parms, GameplayTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameplayTag_MetaData), NewProp_GameplayTag_MetaData) }; // 1298103297
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventK2_RemoveLooseGameplayTag_Parms, Count), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::NewProp_GameplayTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::NewProp_Count,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AbilitySystemComponent, nullptr, "K2_RemoveLooseGameplayTag", nullptr, nullptr, Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::CFR_AbilitySystemComponent_eventK2_RemoveLooseGameplayTag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::CFR_AbilitySystemComponent_eventK2_RemoveLooseGameplayTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AbilitySystemComponent::execK2_RemoveLooseGameplayTag)
{
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_GameplayTag);
	P_GET_PROPERTY(FIntProperty,Z_Param_Count);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->K2_RemoveLooseGameplayTag(Z_Param_Out_GameplayTag,Z_Param_Count);
	P_NATIVE_END;
}
// End Class UCFR_AbilitySystemComponent Function K2_RemoveLooseGameplayTag

// Begin Class UCFR_AbilitySystemComponent Function K2_RemoveLooseGameplayTags
struct Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics
{
	struct CFR_AbilitySystemComponent_eventK2_RemoveLooseGameplayTags_Parms
	{
		FGameplayTagContainer GameplayTags;
		int32 Count;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Exposes RemoveLooseGameplayTags to Blueprint. These tags are *not* replicated.\n" },
#endif
		{ "CPP_Default_Count", "1" },
		{ "DisplayName", "RemoveLooseGameplayTags" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exposes RemoveLooseGameplayTags to Blueprint. These tags are *not* replicated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameplayTags_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GameplayTags;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::NewProp_GameplayTags = { "GameplayTags", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventK2_RemoveLooseGameplayTags_Parms, GameplayTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameplayTags_MetaData), NewProp_GameplayTags_MetaData) }; // 3352185621
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventK2_RemoveLooseGameplayTags_Parms, Count), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::NewProp_GameplayTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::NewProp_Count,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AbilitySystemComponent, nullptr, "K2_RemoveLooseGameplayTags", nullptr, nullptr, Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::CFR_AbilitySystemComponent_eventK2_RemoveLooseGameplayTags_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::CFR_AbilitySystemComponent_eventK2_RemoveLooseGameplayTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AbilitySystemComponent::execK2_RemoveLooseGameplayTags)
{
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_GameplayTags);
	P_GET_PROPERTY(FIntProperty,Z_Param_Count);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->K2_RemoveLooseGameplayTags(Z_Param_Out_GameplayTags,Z_Param_Count);
	P_NATIVE_END;
}
// End Class UCFR_AbilitySystemComponent Function K2_RemoveLooseGameplayTags

// Begin Class UCFR_AbilitySystemComponent Function SetInputBinding
struct Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics
{
	struct CFR_AbilitySystemComponent_eventSetInputBinding_Parms
	{
		UInputAction* InputAction;
		FGameplayAbilitySpecHandle AbilitySpecHandle;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Input */" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputAction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AbilitySpecHandle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::NewProp_InputAction = { "InputAction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventSetInputBinding_Parms, InputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::NewProp_AbilitySpecHandle = { "AbilitySpecHandle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_AbilitySystemComponent_eventSetInputBinding_Parms, AbilitySpecHandle), Z_Construct_UScriptStruct_FGameplayAbilitySpecHandle, METADATA_PARAMS(0, nullptr) }; // 3490030742
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::NewProp_InputAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::NewProp_AbilitySpecHandle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_AbilitySystemComponent, nullptr, "SetInputBinding", nullptr, nullptr, Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::CFR_AbilitySystemComponent_eventSetInputBinding_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::CFR_AbilitySystemComponent_eventSetInputBinding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_AbilitySystemComponent::execSetInputBinding)
{
	P_GET_OBJECT(UInputAction,Z_Param_InputAction);
	P_GET_STRUCT(FGameplayAbilitySpecHandle,Z_Param_AbilitySpecHandle);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetInputBinding(Z_Param_InputAction,Z_Param_AbilitySpecHandle);
	P_NATIVE_END;
}
// End Class UCFR_AbilitySystemComponent Function SetInputBinding

// Begin Class UCFR_AbilitySystemComponent
void UCFR_AbilitySystemComponent::StaticRegisterNativesUCFR_AbilitySystemComponent()
{
	UClass* Class = UCFR_AbilitySystemComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddUniqueLooseGameplayTag", &UCFR_AbilitySystemComponent::execAddUniqueLooseGameplayTag },
		{ "GrantAbilityOfType", &UCFR_AbilitySystemComponent::execGrantAbilityOfType },
		{ "K2_AddLooseGameplayTag", &UCFR_AbilitySystemComponent::execK2_AddLooseGameplayTag },
		{ "K2_AddLooseGameplayTags", &UCFR_AbilitySystemComponent::execK2_AddLooseGameplayTags },
		{ "K2_RemoveLooseGameplayTag", &UCFR_AbilitySystemComponent::execK2_RemoveLooseGameplayTag },
		{ "K2_RemoveLooseGameplayTags", &UCFR_AbilitySystemComponent::execK2_RemoveLooseGameplayTags },
		{ "SetInputBinding", &UCFR_AbilitySystemComponent::execSetInputBinding },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_AbilitySystemComponent);
UClass* Z_Construct_UClass_UCFR_AbilitySystemComponent_NoRegister()
{
	return UCFR_AbilitySystemComponent::StaticClass();
}
struct Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object LOD Lighting Transform Sockets TextureStreaming Object LOD Lighting Transform Sockets TextureStreaming" },
		{ "IncludePath", "AbilitySystem/CFR_AbilitySystemComponent.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultAbilitiesInitData_MetaData[] = {
		{ "Category", "Abilities" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartupGameplayEffects_MetaData[] = {
		{ "Category", "Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Initializer gameplay effects. */" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initializer gameplay effects." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AbilitySystem/CFR_AbilitySystemComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultAbilitiesInitData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DefaultAbilitiesInitData;
	static const UECodeGen_Private::FClassPropertyParams NewProp_StartupGameplayEffects_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StartupGameplayEffects;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCFR_AbilitySystemComponent_AddUniqueLooseGameplayTag, "AddUniqueLooseGameplayTag" }, // 3191809964
		{ &Z_Construct_UFunction_UCFR_AbilitySystemComponent_GrantAbilityOfType, "GrantAbilityOfType" }, // 797792150
		{ &Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTag, "K2_AddLooseGameplayTag" }, // 2643609188
		{ &Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_AddLooseGameplayTags, "K2_AddLooseGameplayTags" }, // 615298351
		{ &Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTag, "K2_RemoveLooseGameplayTag" }, // 1855353181
		{ &Z_Construct_UFunction_UCFR_AbilitySystemComponent_K2_RemoveLooseGameplayTags, "K2_RemoveLooseGameplayTags" }, // 175219867
		{ &Z_Construct_UFunction_UCFR_AbilitySystemComponent_SetInputBinding, "SetInputBinding" }, // 3571736310
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_AbilitySystemComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::NewProp_DefaultAbilitiesInitData_Inner = { "DefaultAbilitiesInitData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCFR_AbilityInitData, METADATA_PARAMS(0, nullptr) }; // 3687838712
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::NewProp_DefaultAbilitiesInitData = { "DefaultAbilitiesInitData", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_AbilitySystemComponent, DefaultAbilitiesInitData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultAbilitiesInitData_MetaData), NewProp_DefaultAbilitiesInitData_MetaData) }; // 3687838712
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::NewProp_StartupGameplayEffects_Inner = { "StartupGameplayEffects", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayEffect_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::NewProp_StartupGameplayEffects = { "StartupGameplayEffects", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_AbilitySystemComponent, StartupGameplayEffects), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartupGameplayEffects_MetaData), NewProp_StartupGameplayEffects_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::NewProp_InputComponent = { "InputComponent", nullptr, (EPropertyFlags)0x0020080000082008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_AbilitySystemComponent, InputComponent), Z_Construct_UClass_UEnhancedInputComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputComponent_MetaData), NewProp_InputComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::NewProp_DefaultAbilitiesInitData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::NewProp_DefaultAbilitiesInitData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::NewProp_StartupGameplayEffects_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::NewProp_StartupGameplayEffects,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::NewProp_InputComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilitySystemComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::ClassParams = {
	&UCFR_AbilitySystemComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_AbilitySystemComponent()
{
	if (!Z_Registration_Info_UClass_UCFR_AbilitySystemComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_AbilitySystemComponent.OuterSingleton, Z_Construct_UClass_UCFR_AbilitySystemComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_AbilitySystemComponent.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_AbilitySystemComponent>()
{
	return UCFR_AbilitySystemComponent::StaticClass();
}
UCFR_AbilitySystemComponent::UCFR_AbilitySystemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_AbilitySystemComponent);
UCFR_AbilitySystemComponent::~UCFR_AbilitySystemComponent() {}
// End Class UCFR_AbilitySystemComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCFR_AbilityInitData::StaticStruct, Z_Construct_UScriptStruct_FCFR_AbilityInitData_Statics::NewStructOps, TEXT("CFR_AbilityInitData"), &Z_Registration_Info_UScriptStruct_CFR_AbilityInitData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCFR_AbilityInitData), 3687838712U) },
		{ FCFR_AbilityInputBinding::StaticStruct, Z_Construct_UScriptStruct_FCFR_AbilityInputBinding_Statics::NewStructOps, TEXT("CFR_AbilityInputBinding"), &Z_Registration_Info_UScriptStruct_CFR_AbilityInputBinding, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCFR_AbilityInputBinding), 3907237576U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_AbilitySystemComponent, UCFR_AbilitySystemComponent::StaticClass, TEXT("UCFR_AbilitySystemComponent"), &Z_Registration_Info_UClass_UCFR_AbilitySystemComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_AbilitySystemComponent), 2566137528U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_3191983248(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_CFR_AbilitySystemComponent_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
