// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/GameFramework/CFR_IGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_IGameMode() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_IGameMode();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACFR_IGameMode_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AGameMode();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class ACFR_IGameMode
void ACFR_IGameMode::StaticRegisterNativesACFR_IGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACFR_IGameMode);
UClass* Z_Construct_UClass_ACFR_IGameMode_NoRegister()
{
	return ACFR_IGameMode::StaticClass();
}
struct Z_Construct_UClass_ACFR_IGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameFramework/CFR_IGameMode.h" },
		{ "ModuleRelativePath", "Public/GameFramework/CFR_IGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGamePauseMenuWidget_MetaData[] = {
		{ "Category", "WidgetMenus" },
		{ "ModuleRelativePath", "Public/GameFramework/CFR_IGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerWinsWidget_MetaData[] = {
		{ "Category", "WidgetMenus" },
		{ "ModuleRelativePath", "Public/GameFramework/CFR_IGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerLosesWidget_MetaData[] = {
		{ "Category", "WidgetMenus" },
		{ "ModuleRelativePath", "Public/GameFramework/CFR_IGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_InGamePauseMenuWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerWinsWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerLosesWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACFR_IGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACFR_IGameMode_Statics::NewProp_InGamePauseMenuWidget = { "InGamePauseMenuWidget", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACFR_IGameMode, InGamePauseMenuWidget), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGamePauseMenuWidget_MetaData), NewProp_InGamePauseMenuWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACFR_IGameMode_Statics::NewProp_PlayerWinsWidget = { "PlayerWinsWidget", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACFR_IGameMode, PlayerWinsWidget), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerWinsWidget_MetaData), NewProp_PlayerWinsWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACFR_IGameMode_Statics::NewProp_PlayerLosesWidget = { "PlayerLosesWidget", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACFR_IGameMode, PlayerLosesWidget), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerLosesWidget_MetaData), NewProp_PlayerLosesWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACFR_IGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACFR_IGameMode_Statics::NewProp_InGamePauseMenuWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACFR_IGameMode_Statics::NewProp_PlayerWinsWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACFR_IGameMode_Statics::NewProp_PlayerLosesWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_IGameMode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACFR_IGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameMode,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_IGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACFR_IGameMode_Statics::ClassParams = {
	&ACFR_IGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACFR_IGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_IGameMode_Statics::PropPointers),
	0,
	0x009002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACFR_IGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ACFR_IGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACFR_IGameMode()
{
	if (!Z_Registration_Info_UClass_ACFR_IGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACFR_IGameMode.OuterSingleton, Z_Construct_UClass_ACFR_IGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACFR_IGameMode.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<ACFR_IGameMode>()
{
	return ACFR_IGameMode::StaticClass();
}
ACFR_IGameMode::ACFR_IGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACFR_IGameMode);
ACFR_IGameMode::~ACFR_IGameMode() {}
// End Class ACFR_IGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACFR_IGameMode, ACFR_IGameMode::StaticClass, TEXT("ACFR_IGameMode"), &Z_Registration_Info_UClass_ACFR_IGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACFR_IGameMode), 1153148437U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h_960363793(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_GameFramework_CFR_IGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
