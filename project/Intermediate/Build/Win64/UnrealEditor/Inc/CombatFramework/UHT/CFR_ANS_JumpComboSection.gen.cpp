// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/Notifies/CFR_ANS_JumpComboSection.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_ANS_JumpComboSection() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_ANS_JumpComboSection();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_ANS_JumpComboSection_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimNotifyState();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_ANS_JumpComboSection
void UCFR_ANS_JumpComboSection::StaticRegisterNativesUCFR_ANS_JumpComboSection()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_ANS_JumpComboSection);
UClass* Z_Construct_UClass_UCFR_ANS_JumpComboSection_NoRegister()
{
	return UCFR_ANS_JumpComboSection::StaticClass();
}
struct Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "Notifies/CFR_ANS_JumpComboSection.h" },
		{ "ModuleRelativePath", "Public/Notifies/CFR_ANS_JumpComboSection.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SectionName_MetaData[] = {
		{ "Category", "CFR_ANS_JumpComboSection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Section name to jump when appropiate input is received. */" },
#endif
		{ "ModuleRelativePath", "Public/Notifies/CFR_ANS_JumpComboSection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Section name to jump when appropiate input is received." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputAction_MetaData[] = {
		{ "Category", "CFR_ANS_JumpComboSection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* InputAction to be started to continue the combo. */" },
#endif
		{ "ModuleRelativePath", "Public/Notifies/CFR_ANS_JumpComboSection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "InputAction to be started to continue the combo." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SectionName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputAction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_ANS_JumpComboSection>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::NewProp_SectionName = { "SectionName", nullptr, (EPropertyFlags)0x0010000000000011, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_ANS_JumpComboSection, SectionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SectionName_MetaData), NewProp_SectionName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::NewProp_InputAction = { "InputAction", nullptr, (EPropertyFlags)0x0010000000000011, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCFR_ANS_JumpComboSection, InputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputAction_MetaData), NewProp_InputAction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::NewProp_SectionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::NewProp_InputAction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimNotifyState,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::ClassParams = {
	&UCFR_ANS_JumpComboSection::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::PropPointers),
	0,
	0x001130A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_ANS_JumpComboSection()
{
	if (!Z_Registration_Info_UClass_UCFR_ANS_JumpComboSection.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_ANS_JumpComboSection.OuterSingleton, Z_Construct_UClass_UCFR_ANS_JumpComboSection_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_ANS_JumpComboSection.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_ANS_JumpComboSection>()
{
	return UCFR_ANS_JumpComboSection::StaticClass();
}
UCFR_ANS_JumpComboSection::UCFR_ANS_JumpComboSection(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_ANS_JumpComboSection);
UCFR_ANS_JumpComboSection::~UCFR_ANS_JumpComboSection() {}
// End Class UCFR_ANS_JumpComboSection

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Notifies_CFR_ANS_JumpComboSection_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_ANS_JumpComboSection, UCFR_ANS_JumpComboSection::StaticClass, TEXT("UCFR_ANS_JumpComboSection"), &Z_Registration_Info_UClass_UCFR_ANS_JumpComboSection, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_ANS_JumpComboSection), 3910293105U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Notifies_CFR_ANS_JumpComboSection_h_2509232961(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Notifies_CFR_ANS_JumpComboSection_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Notifies_CFR_ANS_JumpComboSection_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
