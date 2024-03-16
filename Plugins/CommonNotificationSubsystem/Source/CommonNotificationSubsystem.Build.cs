// Copyright 2024 Spyridon Zervos

using UnrealBuildTool;

public class CommonNotificationSubsystem : ModuleRules
{
	public CommonNotificationSubsystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;				
		
		PublicDependencyModuleNames.AddRange(new string[]
		{
			// Core
			"Core",
			"CoreUObject",
			"InputCore",
			"Engine",
			// Slate
			"Slate",
			"SlateCore",
			// UMG
			"UMG",
			// Common
			"CommonInput",
			"CommonUI",
			// Gameplay tags
			"GameplayTags",
		});
		
		// PrivateDependencyModuleNames.AddRange(new string[] { });
		
		// DynamicallyLoadedModuleNames.AddRange(new string[] { });
	}
}
