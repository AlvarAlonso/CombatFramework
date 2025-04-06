// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCombatFramework_init() {}
	COMBATFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature();
	COMBATFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_CombatFramework_CFR_PlayMontageAndWaitForEventDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_CombatFramework;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_CombatFramework()
	{
		if (!Z_Registration_Info_UPackage__Script_CombatFramework.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_CombatFramework_CFR_HitboxOverlapDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_CombatFramework_CFR_PlayMontageAndWaitForEventDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/CombatFramework",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xC6D75642,
				0xBEC917DC,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_CombatFramework.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_CombatFramework.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_CombatFramework(Z_Construct_UPackage__Script_CombatFramework, TEXT("/Script/CombatFramework"), Z_Registration_Info_UPackage__Script_CombatFramework, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xC6D75642, 0xBEC917DC));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
