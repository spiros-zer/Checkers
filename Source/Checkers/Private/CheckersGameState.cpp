// Copyright 2024 Spyridon Zervos


#include "CheckersGameState.h"

#include "CheckersGameInstance.h"

void ACheckersGameState::HandleLeavingMap()
{
	Super::HandleLeavingMap();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("%s fired."), *FString(__FUNCTION__)));
	
	/*
	if (GetNetMode() == NM_Client || GetNetMode() == NM_Standalone)
	{
		if (const UCheckersGameInstance* CheckersGameInstance = GetGameInstance<UCheckersGameInstance>())
		{
			CheckersGameInstance->BeginShowingLoadingScreen();
		}
	}*/
}
