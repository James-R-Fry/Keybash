// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleProto_1GameMode.h"
#include "BattleProto_1Character.h"
#include "UObject/ConstructorHelpers.h"

AKeybashGameMode::AKeybashGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
    /**[0] = word , [1] cost, [2] power, [3] type
    SingleWord.Add(TEXT("stupid"));
    SingleWord.Add(TEXT("2"));
    SingleWord.Add(TEXT("500"));
    SingleWord.Add(TEXT("INT"));

    **/

    FString file = FPaths::ConvertRelativePathToFull(FPaths::GameSourceDir()) + TEXT("/WordsList.txt");

    IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

    FString FileContent;

    if (FileManager.FileExists(*file))
    {
        if (FFileHelper::LoadFileToString(FileContent, *file, FFileHelper::EHashOptions::None))
        {
            UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Text From File: %s"), *FileContent);

            WordsString = FileContent;
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
        UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"), *file);
    }
}


void AKeybashGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(StartingWidgetClass);
}

void AKeybashGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}