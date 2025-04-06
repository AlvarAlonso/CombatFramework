// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h"
#include "CombatFramework/Public/AbilitySystem/CFR_EventDataPayloads.h"
#include "GameplayAbilities/Public/Abilities/GameplayAbilityTypes.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_GA_PlayMontage() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_GA_PlayMontage();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_GA_PlayMontage_NoRegister();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_GameplayAbility();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_PlayMontageAndWaitForEvent_NoRegister();
COMBATFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FCFR_EffectContextContainer();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayEventData();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_GA_PlayMontage Function BP_OnReceivedEvent
struct CFR_GA_PlayMontage_eventBP_OnReceivedEvent_Parms
{
	FGameplayTag EventTag;
	FGameplayEventData EventData;
};
static const FName NAME_UCFR_GA_PlayMontage_BP_OnReceivedEvent = FName(TEXT("BP_OnReceivedEvent"));
void UCFR_GA_PlayMontage::BP_OnReceivedEvent(FGameplayTag EventTag, FGameplayEventData EventData)
{
	CFR_GA_PlayMontage_eventBP_OnReceivedEvent_Parms Parms;
	Parms.EventTag=EventTag;
	Parms.EventData=EventData;
	UFunction* Func = FindFunctionChecked(NAME_UCFR_GA_PlayMontage_BP_OnReceivedEvent);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_GA_PlayMontage_eventBP_OnReceivedEvent_Parms, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::NewProp_EventData = { "EventData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_GA_PlayMontage_eventBP_OnReceivedEvent_Parms, EventData), Z_Construct_UScriptStruct_FGameplayEventData, METADATA_PARAMS(0, nullptr) }; // 1231635826
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::NewProp_EventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::NewProp_EventData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_GA_PlayMontage, nullptr, "BP_OnReceivedEvent", nullptr, nullptr, Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::PropPointers), sizeof(CFR_GA_PlayMontage_eventBP_OnReceivedEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::Function_MetaDataParams) };
static_assert(sizeof(CFR_GA_PlayMontage_eventBP_OnReceivedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class UCFR_GA_PlayMontage Function BP_OnReceivedEvent

// Begin Class UCFR_GA_PlayMontage Function OnMontageFinished
struct Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics
{
	struct CFR_GA_PlayMontage_eventOnMontageFinished_Parms
	{
		FGameplayTag EventTag;
		FGameplayEventData EventData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_GA_PlayMontage_eventOnMontageFinished_Parms, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::NewProp_EventData = { "EventData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_GA_PlayMontage_eventOnMontageFinished_Parms, EventData), Z_Construct_UScriptStruct_FGameplayEventData, METADATA_PARAMS(0, nullptr) }; // 1231635826
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::NewProp_EventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::NewProp_EventData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_GA_PlayMontage, nullptr, "OnMontageFinished", nullptr, nullptr, Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::CFR_GA_PlayMontage_eventOnMontageFinished_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::CFR_GA_PlayMontage_eventOnMontageFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_GA_PlayMontage::execOnMontageFinished)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_EventTag);
	P_GET_STRUCT(FGameplayEventData,Z_Param_EventData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMontageFinished(Z_Param_EventTag,Z_Param_EventData);
	P_NATIVE_END;
}
// End Class UCFR_GA_PlayMontage Function OnMontageFinished

// Begin Class UCFR_GA_PlayMontage Function OnReceivedEvent
struct Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics
{
	struct CFR_GA_PlayMontage_eventOnReceivedEvent_Parms
	{
		FGameplayTag EventTag;
		FGameplayEventData EventData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_GA_PlayMontage_eventOnReceivedEvent_Parms, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::NewProp_EventData = { "EventData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_GA_PlayMontage_eventOnReceivedEvent_Parms, EventData), Z_Construct_UScriptStruct_FGameplayEventData, METADATA_PARAMS(0, nullptr) }; // 1231635826
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::NewProp_EventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::NewProp_EventData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_GA_PlayMontage, nullptr, "OnReceivedEvent", nullptr, nullptr, Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::CFR_GA_PlayMontage_eventOnReceivedEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::CFR_GA_PlayMontage_eventOnReceivedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_GA_PlayMontage::execOnReceivedEvent)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_EventTag);
	P_GET_STRUCT(FGameplayEventData,Z_Param_EventData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnReceivedEvent(Z_Param_EventTag,Z_Param_EventData);
	P_NATIVE_END;
}
// End Class UCFR_GA_PlayMontage Function OnReceivedEvent

// Begin Class UCFR_GA_PlayMontage
void UCFR_GA_PlayMontage::StaticRegisterNativesUCFR_GA_PlayMontage()
{
	UClass* Class = UCFR_GA_PlayMontage::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnMontageFinished", &UCFR_GA_PlayMontage::execOnMontageFinished },
		{ "OnReceivedEvent", &UCFR_GA_PlayMontage::execOnReceivedEvent },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_GA_PlayMontage);
UClass* Z_Construct_UClass_UCFR_GA_PlayMontage_NoRegister()
{
	return UCFR_GA_PlayMontage::StaticClass();
}
struct Z_Construct_UClass_UCFR_GA_PlayMontage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayMontageAndWaitForEventTask_MetaData[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MontageToPlay_MetaData[] = {
		{ "Category", "CFR_GA_PlayMontage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Montage ability will play.\n" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Montage ability will play." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartSectionName_MetaData[] = {
		{ "Category", "CFR_GA_PlayMontage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Section of the montage in case we do not want to play from the beginning.\n" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Section of the montage in case we do not want to play from the beginning." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[] = {
		{ "Category", "CFR_GA_PlayMontage" },
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventTagContainer_MetaData[] = {
		{ "Category", "CFR_GA_PlayMontage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The Tag for the montage to wait for.\n" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Tag for the montage to wait for." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EffectsToApply_MetaData[] = {
		{ "Category", "CFR_GA_PlayMontage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Effects to apply to target actor when the events are received.\n" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/GameplayAbilities/CFR_GA_PlayMontage.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Effects to apply to target actor when the events are received." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayMontageAndWaitForEventTask;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MontageToPlay;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StartSectionName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTagContainer;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EffectsToApply_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EffectsToApply_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_EffectsToApply;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCFR_GA_PlayMontage_BP_OnReceivedEvent, "BP_OnReceivedEvent" }, // 2756621740
		{ &Z_Construct_UFunction_UCFR_GA_PlayMontage_OnMontageFinished, "OnMontageFinished" }, // 3183242512
		{ &Z_Construct_UFunction_UCFR_GA_PlayMontage_OnReceivedEvent, "OnReceivedEvent" }, // 1206481808
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_GA_PlayMontage>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_PlayMontageAndWaitForEventTask = { "PlayMontageAndWaitForEventTask", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_GA_PlayMontage, PlayMontageAndWaitForEventTask), Z_Construct_UClass_UCFR_PlayMontageAndWaitForEvent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayMontageAndWaitForEventTask_MetaData), NewProp_PlayMontageAndWaitForEventTask_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_MontageToPlay = { "MontageToPlay", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_GA_PlayMontage, MontageToPlay), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MontageToPlay_MetaData), NewProp_MontageToPlay_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_StartSectionName = { "StartSectionName", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_GA_PlayMontage, StartSectionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartSectionName_MetaData), NewProp_StartSectionName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_GA_PlayMontage, PlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_MetaData), NewProp_PlayRate_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_EventTagContainer = { "EventTagContainer", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_GA_PlayMontage, EventTagContainer), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventTagContainer_MetaData), NewProp_EventTagContainer_MetaData) }; // 3352185621
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_EffectsToApply_ValueProp = { "EffectsToApply", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FCFR_EffectContextContainer, METADATA_PARAMS(0, nullptr) }; // 1774026666
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_EffectsToApply_Key_KeyProp = { "EffectsToApply_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_EffectsToApply = { "EffectsToApply", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_GA_PlayMontage, EffectsToApply), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EffectsToApply_MetaData), NewProp_EffectsToApply_MetaData) }; // 1298103297 1774026666
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_PlayMontageAndWaitForEventTask,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_MontageToPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_StartSectionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_EventTagContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_EffectsToApply_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_EffectsToApply_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::NewProp_EffectsToApply,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCFR_GameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::ClassParams = {
	&UCFR_GA_PlayMontage::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_GA_PlayMontage()
{
	if (!Z_Registration_Info_UClass_UCFR_GA_PlayMontage.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_GA_PlayMontage.OuterSingleton, Z_Construct_UClass_UCFR_GA_PlayMontage_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_GA_PlayMontage.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_GA_PlayMontage>()
{
	return UCFR_GA_PlayMontage::StaticClass();
}
UCFR_GA_PlayMontage::UCFR_GA_PlayMontage(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_GA_PlayMontage);
UCFR_GA_PlayMontage::~UCFR_GA_PlayMontage() {}
// End Class UCFR_GA_PlayMontage

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_GA_PlayMontage, UCFR_GA_PlayMontage::StaticClass, TEXT("UCFR_GA_PlayMontage"), &Z_Registration_Info_UClass_UCFR_GA_PlayMontage, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_GA_PlayMontage), 4013285192U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_397572574(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_AbilitySystem_GameplayAbilities_CFR_GA_PlayMontage_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
