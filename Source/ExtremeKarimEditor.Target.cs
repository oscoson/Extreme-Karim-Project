// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ExtremeKarimEditorTarget : TargetRules
{
	public ExtremeKarimEditorTarget(TargetInfo Target) : base(Target)
	{
		bOverrideBuildEnvironment = true;
		//AdditionalCompilerArguments = "-Wno-unused-but-set-variable";
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("ExtremeKarim");
	}
}
