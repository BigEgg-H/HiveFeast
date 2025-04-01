// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HiveFeast : ModuleRules
{
	public HiveFeast(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ChaosFlesh" , "ChaosFleshEngine"  });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

	}
}
