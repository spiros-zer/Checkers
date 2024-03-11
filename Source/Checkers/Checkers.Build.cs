// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Checkers : ModuleRules
{
	public Checkers(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "CommonUI", "CommonInput"});

		// Using UMG
		PublicDependencyModuleNames.AddRange(new string[] { "UMG", "CommonUI", "CommonInput"});

		// Using Common UI
		PublicDependencyModuleNames.AddRange(new string[] { "CommonUI", "CommonInput"});
		
		// Using Gameplay Tags
		PublicDependencyModuleNames.AddRange(new string[] { "GameplayTags"});

		// Using Enhanced Input
		PrivateDependencyModuleNames.AddRange(new string[] { "EnhancedInput" });
		
		// Using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
