// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CombatFramework : ModuleRules
{
    public CombatFramework(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "CommonUI",
            "Core",
            "CoreUObject",
            "Engine",
            "EnhancedInput",
            "GameplayAbilities",
            "HeadMountedDisplay",
            "InputCore",
            "NavigationSystem",
            "Niagara",
            "UMG"
             });
        PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks" });
    }
}
