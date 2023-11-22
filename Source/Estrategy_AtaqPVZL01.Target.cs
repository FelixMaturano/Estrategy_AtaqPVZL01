// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Estrategy_AtaqPVZL01Target : TargetRules
{
	public Estrategy_AtaqPVZL01Target( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Estrategy_AtaqPVZL01" } );
	}
}
