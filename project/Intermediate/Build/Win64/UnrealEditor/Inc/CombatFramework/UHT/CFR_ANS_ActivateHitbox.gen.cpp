// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/Notifies/CFR_ANS_ActivateHitbox.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_ANS_ActivateHitbox() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_ANS_ActivateHitbox();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_ANS_ActivateHitbox_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimNotifyState();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_ANS_ActivateHitbox
void UCFR_ANS_ActivateHitbox::StaticRegisterNativesUCFR_ANS_ActivateHitbox()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_ANS_ActivateHitbox);
UClass* Z_Construct_UClass_UCFR_ANS_ActivateHitbox_NoRegister()
{
	return UCFR_ANS_ActivateHitbox::StaticClass();
}
struct Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "Notifies/CFR_ANS_ActivateHitbox.h" },
		{ "ModuleRelativePath", "Public/Notifies/CFR_ANS_ActivateHitbox.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitboxTag_MetaData[] = {
		{ "Category", "CFR_ANS_ActivateHitbox" },
		{ "ModuleRelativePath", "Public/Notifies/CFR_ANS_ActivateHitbox.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EffectTag_MetaData[] = {
		{ "Category", "CFR_ANS_ActivateHitbox" },
		{ "ModuleRelativePath", "Public/Notifies/CFR_ANS_ActivateHitbox.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitboxTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EffectTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_ANS_ActivateHitbox>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::NewProp_HitboxTag = { "HitboxTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_ANS_ActivateHitbox, HitboxTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitboxTag_MetaData), NewProp_HitboxTag_MetaData) }; // 1298103297
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::NewProp_EffectTag = { "EffectTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_ANS_ActivateHitbox, EffectTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EffectTag_MetaData), NewProp_EffectTag_MetaData) }; // 1298103297
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::NewProp_HitboxTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::NewProp_EffectTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimNotifyState,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::ClassParams = {
	&UCFR_ANS_ActivateHitbox::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::PropPointers),
	0,
	0x001130A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_ANS_ActivateHitbox()
{
	if (!Z_Registration_Info_UClass_UCFR_ANS_ActivateHitbox.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_ANS_ActivateHitbox.OuterSingleton, Z_Construct_UClass_UCFR_ANS_ActivateHitbox_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_ANS_ActivateHitbox.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_ANS_ActivateHitbox>()
{
	return UCFR_ANS_ActivateHitbox::StaticClass();
}
UCFR_ANS_ActivateHitbox::UCFR_ANS_ActivateHitbox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_ANS_ActivateHitbox);
UCFR_ANS_ActivateHitbox::~UCFR_ANS_ActivateHitbox() {}
// End Class UCFR_ANS_ActivateHitbox

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Notifies_CFR_ANS_ActivateHitbox_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_ANS_ActivateHitbox, UCFR_ANS_ActivateHitbox::StaticClass, TEXT("UCFR_ANS_ActivateHitbox"), &Z_Registration_Info_UClass_UCFR_ANS_ActivateHitbox, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_ANS_ActivateHitbox), 2877284605U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Notifies_CFR_ANS_ActivateHitbox_h_2545224624(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Notifies_CFR_ANS_ActivateHitbox_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Notifies_CFR_ANS_ActivateHitbox_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
