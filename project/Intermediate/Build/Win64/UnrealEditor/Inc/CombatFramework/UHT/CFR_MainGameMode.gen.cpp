// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/GameFramework/CFR_MainGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_MainGameMode() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_IGameMode();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_MainGameMode();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_MainGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class ACFR_MainGameMode
void ACFR_MainGameMode::StaticRegisterNativesACFR_MainGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACFR_MainGameMode);
UClass* Z_Construct_UClass_ACFR_MainGameMode_NoRegister()
{
	return ACFR_MainGameMode::StaticClass();
}
struct Z_Construct_UClass_ACFR_MainGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameFramework/CFR_MainGameMode.h" },
		{ "ModuleRelativePath", "Public/GameFramework/CFR_MainGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACFR_MainGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACFR_MainGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACFR_IGameMode,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_MainGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACFR_MainGameMode_Statics::ClassParams = {
	&ACFR_MainGameMode::StaticClass,
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
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_MainGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ACFR_MainGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACFR_MainGameMode()
{
	if (!Z_Registration_Info_UClass_ACFR_MainGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACFR_MainGameMode.OuterSingleton, Z_Construct_UClass_ACFR_MainGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACFR_MainGameMode.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<ACFR_MainGameMode>()
{
	return ACFR_MainGameMode::StaticClass();
}
ACFR_MainGameMode::ACFR_MainGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACFR_MainGameMode);
ACFR_MainGameMode::~ACFR_MainGameMode() {}
// End Class ACFR_MainGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACFR_MainGameMode, ACFR_MainGameMode::StaticClass, TEXT("ACFR_MainGameMode"), &Z_Registration_Info_UClass_ACFR_MainGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACFR_MainGameMode), 1693440141U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h_2647571235(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_MainGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
