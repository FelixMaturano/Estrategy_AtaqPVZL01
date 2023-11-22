// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Estrategy_AtaqPVZL01EditorTarget : TargetRules
{
	public Estrategy_AtaqPVZL01EditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Estrategy_AtaqPVZL01" } );
	}
}
