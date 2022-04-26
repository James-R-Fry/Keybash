// Copyright Epic Games, Inc. All Rights Reserved.

#include "KeybashGameMode.h"
#include "KeybashCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKeybashGameMode::AKeybashGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
