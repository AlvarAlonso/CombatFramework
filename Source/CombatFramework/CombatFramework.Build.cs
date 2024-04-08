// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CombatFramework : ModuleRules
{
	public CombatFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "GameplayAbilities", "UMG" });
		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks" });
	}
}
