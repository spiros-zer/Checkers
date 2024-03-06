// Copyright 2024 Spyridon Zervos


#include "CheckersGameInstance.h"

#include "Player/CheckersPlayerController.h"

void UCheckersGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UCheckersGameInstance::BeginShowingLoadingScreen);
}

void UCheckersGameInstance::BeginShowingLoadingScreen_Implementation(const FString& MapName)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s fired!"), *FString(__FUNCTION__)));

	if (GetFirstLocalPlayerController())
	{
		if (ACheckersPlayerController* CheckersPlayerController = Cast<ACheckersPlayerController>(GetFirstLocalPlayerController()))
		{
			CheckersPlayerController->ShowLoadingScreen();
		}
	}
	
}
