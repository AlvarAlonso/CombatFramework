// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/Characters/CFR_AICharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_AICharacter() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_AICharacter();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_AICharacter_NoRegister();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_CharacterBase();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class ACFR_AICharacter
void ACFR_AICharacter::StaticRegisterNativesACFR_AICharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACFR_AICharacter);
UClass* Z_Construct_UClass_ACFR_AICharacter_NoRegister()
{
	return ACFR_AICharacter::StaticClass();
}
struct Z_Construct_UClass_ACFR_AICharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/CFR_AICharacter.h" },
		{ "ModuleRelativePath", "Public/Characters/CFR_AICharacter.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACFR_AICharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACFR_AICharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACFR_CharacterBase,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_AICharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACFR_AICharacter_Statics::ClassParams = {
	&ACFR_AICharacter::StaticClass,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_AICharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ACFR_AICharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACFR_AICharacter()
{
	if (!Z_Registration_Info_UClass_ACFR_AICharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACFR_AICharacter.OuterSingleton, Z_Construct_UClass_ACFR_AICharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACFR_AICharacter.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<ACFR_AICharacter>()
{
	return ACFR_AICharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACFR_AICharacter);
ACFR_AICharacter::~ACFR_AICharacter() {}
// End Class ACFR_AICharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_AICharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACFR_AICharacter, ACFR_AICharacter::StaticClass, TEXT("ACFR_AICharacter"), &Z_Registration_Info_UClass_ACFR_AICharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACFR_AICharacter), 3722678551U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_AICharacter_h_2400775429(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_AICharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Characters_CFR_AICharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
