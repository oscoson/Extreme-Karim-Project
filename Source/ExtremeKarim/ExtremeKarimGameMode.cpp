// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtremeKarimGameMode.h"
#include "ExtremeKarimCharacter.h"

AExtremeKarimGameMode::AExtremeKarimGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AExtremeKarimCharacter::StaticClass();	
}
