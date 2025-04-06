// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/Public/Utils/CFR_CheatManager.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCFR_CheatManager() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_CheatManager();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_UCFR_CheatManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCheatManager();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class UCFR_CheatManager Function KillPlayer
struct Z_Construct_UFunction_UCFR_CheatManager_KillPlayer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Utils/CFR_CheatManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCFR_CheatManager_KillPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCFR_CheatManager, nullptr, "KillPlayer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020601, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCFR_CheatManager_KillPlayer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCFR_CheatManager_KillPlayer_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UCFR_CheatManager_KillPlayer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCFR_CheatManager_KillPlayer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCFR_CheatManager::execKillPlayer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->KillPlayer();
	P_NATIVE_END;
}
// End Class UCFR_CheatManager Function KillPlayer

// Begin Class UCFR_CheatManager
void UCFR_CheatManager::StaticRegisterNativesUCFR_CheatManager()
{
	UClass* Class = UCFR_CheatManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "KillPlayer", &UCFR_CheatManager::execKillPlayer },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCFR_CheatManager);
UClass* Z_Construct_UClass_UCFR_CheatManager_NoRegister()
{
	return UCFR_CheatManager::StaticClass();
}
struct Z_Construct_UClass_UCFR_CheatManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Utils/CFR_CheatManager.h" },
		{ "ModuleRelativePath", "Public/Utils/CFR_CheatManager.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCFR_CheatManager_KillPlayer, "KillPlayer" }, // 1491797372
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCFR_CheatManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCFR_CheatManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCheatManager,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_CheatManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCFR_CheatManager_Statics::ClassParams = {
	&UCFR_CheatManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCFR_CheatManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UCFR_CheatManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCFR_CheatManager()
{
	if (!Z_Registration_Info_UClass_UCFR_CheatManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCFR_CheatManager.OuterSingleton, Z_Construct_UClass_UCFR_CheatManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCFR_CheatManager.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<UCFR_CheatManager>()
{
	return UCFR_CheatManager::StaticClass();
}
UCFR_CheatManager::UCFR_CheatManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCFR_CheatManager);
UCFR_CheatManager::~UCFR_CheatManager() {}
// End Class UCFR_CheatManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCFR_CheatManager, UCFR_CheatManager::StaticClass, TEXT("UCFR_CheatManager"), &Z_Registration_Info_UClass_UCFR_CheatManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCFR_CheatManager), 1307203931U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_3493584462(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_CombatFramework_project_Source_CombatFramework_Public_Utils_CFR_CheatManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
