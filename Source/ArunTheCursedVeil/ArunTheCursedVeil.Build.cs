// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ArunTheCursedVeil : ModuleRules
{
	public ArunTheCursedVeil(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"EnhancedInput",
			"Niagara",
			"AIModule",
			"NavigationSystem",
			"GameplayTasks",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ArunTheCursedVeil",
			"ArunTheCursedVeil/Variant_Platforming",
			"ArunTheCursedVeil/Variant_Platforming/Animation",
			"ArunTheCursedVeil/Variant_Combat",
			"ArunTheCursedVeil/Variant_Combat/AI",
			"ArunTheCursedVeil/Variant_Combat/Animation",
			"ArunTheCursedVeil/Variant_Combat/Gameplay",
			"ArunTheCursedVeil/Variant_Combat/Interfaces",
			"ArunTheCursedVeil/Variant_Combat/UI",
			"ArunTheCursedVeil/Variant_SideScrolling",
			"ArunTheCursedVeil/Variant_SideScrolling/AI",
			"ArunTheCursedVeil/Variant_SideScrolling/Gameplay",
			"ArunTheCursedVeil/Variant_SideScrolling/Interfaces",
			"ArunTheCursedVeil/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
