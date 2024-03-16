// Copyright 2024 Spyridon Zervos

using UnrealBuildTool;

public class Checkers : ModuleRules
{
	public Checkers(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			// Core
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			// UMG
			"UMG", 
			// Common UI
			"CommonUI", 
			"CommonInput",
			"CommonNotificationSubsystem",
			// Gameplay Tags
			"GameplayTags",
		});
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			// Using Enhanced Input
			"EnhancedInput", 
			// Using Slate UI
			"Slate",
			"SlateCore"
		});
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
