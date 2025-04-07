// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/Components/CFR_HitboxComponent.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_HitboxComponent() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_HitboxComponent();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_HitboxComponent_NoRegister();
COMBATFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
ENGINE_API UClass* Z_Construct_UClass_UShapeComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Delegate FCFR_HitboxOverlapDelegate
struct Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics
{
	struct _Script_CombatFramework_eventCFR_HitboxOverlapDelegate_Parms
	{
		AActor* HitActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::NewProp_HitActor = { "HitActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CombatFramework_eventCFR_HitboxOverlapDelegate_Parms, HitActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::NewProp_HitActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_CombatFramework, nullptr, "CFR_HitboxOverlapDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::_Script_CombatFramework_eventCFR_HitboxOverlapDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::_Script_CombatFramework_eventCFR_HitboxOverlapDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCFR_HitboxOverlapDelegate_DelegateWrapper(const FMulticastScriptDelegate& CFR_HitboxOverlapDelegate, AActor* HitActor)
{
	struct _Script_CombatFramework_eventCFR_HitboxOverlapDelegate_Parms
	{
		AActor* HitActor;
	};
	_Script_CombatFramework_eventCFR_HitboxOverlapDelegate_Parms Parms;
	Parms.HitActor=HitActor;
	CFR_HitboxOverlapDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FCFR_HitboxOverlapDelegate

// Begin Class UCFR_HitboxComponent Function ActivateHitbox
struct Z_Construct_UFunction_UCFR_HitboxComponent_ActivateHitbox_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Activate hitbox for detecting overlaps and set collision preset to dodgeable. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Activate hitbox for detecting overlaps and set collision preset to dodgeable." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_HitboxComponent_ActivateHitbox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_HitboxComponent, nullptr, "ActivateHitbox", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_ActivateHitbox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_HitboxComponent_ActivateHitbox_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UCFR_HitboxComponent_ActivateHitbox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_HitboxComponent_ActivateHitbox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_HitboxComponent::execActivateHitbox)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ActivateHitbox();
	P_NATIVE_END;
}
// End Class UCFR_HitboxComponent Function ActivateHitbox

// Begin Class UCFR_HitboxComponent Function DeactivateHitbox
struct Z_Construct_UFunction_UCFR_HitboxComponent_DeactivateHitbox_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Deactivate hitbox. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deactivate hitbox." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_HitboxComponent_DeactivateHitbox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_HitboxComponent, nullptr, "DeactivateHitbox", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_DeactivateHitbox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_HitboxComponent_DeactivateHitbox_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UCFR_HitboxComponent_DeactivateHitbox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_HitboxComponent_DeactivateHitbox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_HitboxComponent::execDeactivateHitbox)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DeactivateHitbox();
	P_NATIVE_END;
}
// End Class UCFR_HitboxComponent Function DeactivateHitbox

// Begin Class UCFR_HitboxComponent Function GetEffectTag
struct Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics
{
	struct CFR_HitboxComponent_eventGetEffectTag_Parms
	{
		FGameplayTag ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get the event tag to be sent when the hitbox hits a target actor. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the event tag to be sent when the hitbox hits a target actor." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxComponent_eventGetEffectTag_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_HitboxComponent, nullptr, "GetEffectTag", nullptr, nullptr, Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::CFR_HitboxComponent_eventGetEffectTag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::CFR_HitboxComponent_eventGetEffectTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_HitboxComponent::execGetEffectTag)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTag*)Z_Param__Result=P_THIS->GetEffectTag();
	P_NATIVE_END;
}
// End Class UCFR_HitboxComponent Function GetEffectTag

// Begin Class UCFR_HitboxComponent Function OnComponentOverlap
struct Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics
{
	struct CFR_HitboxComponent_eventOnComponentOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxComponent_eventOnComponentOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxComponent_eventOnComponentOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxComponent_eventOnComponentOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxComponent_eventOnComponentOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((CFR_HitboxComponent_eventOnComponentOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CFR_HitboxComponent_eventOnComponentOverlap_Parms), &Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxComponent_eventOnComponentOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_HitboxComponent, nullptr, "OnComponentOverlap", nullptr, nullptr, Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::CFR_HitboxComponent_eventOnComponentOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::CFR_HitboxComponent_eventOnComponentOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_HitboxComponent::execOnComponentOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnComponentOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// End Class UCFR_HitboxComponent Function OnComponentOverlap

// Begin Class UCFR_HitboxComponent Function SetEffectTag
struct Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics
{
	struct CFR_HitboxComponent_eventSetEffectTag_Parms
	{
		FGameplayTag Tag;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Set the event tag to be sent when the hitbox hits a target actor. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the event tag to be sent when the hitbox hits a target actor." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CFR_HitboxComponent_eventSetEffectTag_Parms, Tag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::NewProp_Tag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_HitboxComponent, nullptr, "SetEffectTag", nullptr, nullptr, Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::CFR_HitboxComponent_eventSetEffectTag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::CFR_HitboxComponent_eventSetEffectTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_HitboxComponent::execSetEffectTag)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_Tag);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetEffectTag(Z_Param_Tag);
	P_NATIVE_END;
}
// End Class UCFR_HitboxComponent Function SetEffectTag

// Begin Class UCFR_HitboxComponent
void UCFR_HitboxComponent::StaticRegisterNativesUCFR_HitboxComponent()
{
	UClass* Class = UCFR_HitboxComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ActivateHitbox", &UCFR_HitboxComponent::execActivateHitbox },
		{ "DeactivateHitbox", &UCFR_HitboxComponent::execDeactivateHitbox },
		{ "GetEffectTag", &UCFR_HitboxComponent::execGetEffectTag },
		{ "OnComponentOverlap", &UCFR_HitboxComponent::execOnComponentOverlap },
		{ "SetEffectTag", &UCFR_HitboxComponent::execSetEffectTag },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_HitboxComponent);
UClass* Z_Construct_UClass_UCFR_HitboxComponent_NoRegister()
{
	return UCFR_HitboxComponent::StaticClass();
}
struct Z_Construct_UClass_UCFR_HitboxComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Components/CFR_HitboxComponent.h" },
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shapes_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** All shapes forming the hitbox component. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/CFR_HitboxComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All shapes forming the hitbox component." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Shapes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Shapes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCFR_HitboxComponent_ActivateHitbox, "ActivateHitbox" }, // 2024235618
		{ &Z_Construct_UFunction_UCFR_HitboxComponent_DeactivateHitbox, "DeactivateHitbox" }, // 505966333
		{ &Z_Construct_UFunction_UCFR_HitboxComponent_GetEffectTag, "GetEffectTag" }, // 581233797
		{ &Z_Construct_UFunction_UCFR_HitboxComponent_OnComponentOverlap, "OnComponentOverlap" }, // 1185786487
		{ &Z_Construct_UFunction_UCFR_HitboxComponent_SetEffectTag, "SetEffectTag" }, // 2684580109
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_HitboxComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCFR_HitboxComponent_Statics::NewProp_Shapes_Inner = { "Shapes", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UShapeComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCFR_HitboxComponent_Statics::NewProp_Shapes = { "Shapes", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_HitboxComponent, Shapes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shapes_MetaData), NewProp_Shapes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCFR_HitboxComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_HitboxComponent_Statics::NewProp_Shapes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_HitboxComponent_Statics::NewProp_Shapes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_HitboxComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCFR_HitboxComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USceneComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_HitboxComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_HitboxComponent_Statics::ClassParams = {
	&UCFR_HitboxComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCFR_HitboxComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_HitboxComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_HitboxComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_HitboxComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_HitboxComponent()
{
	if (!Z_Registration_Info_UClass_UCFR_HitboxComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_HitboxComponent.OuterSingleton, Z_Construct_UClass_UCFR_HitboxComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_HitboxComponent.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_HitboxComponent>()
{
	return UCFR_HitboxComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_HitboxComponent);
UCFR_HitboxComponent::~UCFR_HitboxComponent() {}
// End Class UCFR_HitboxComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_HitboxComponent, UCFR_HitboxComponent::StaticClass, TEXT("UCFR_HitboxComponent"), &Z_Registration_Info_UClass_UCFR_HitboxComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_HitboxComponent), 2254869644U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_700214485(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Components_CFR_HitboxComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
