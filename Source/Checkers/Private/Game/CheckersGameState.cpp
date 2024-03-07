// Copyright 2024 Spyridon Zervos


#include "Game/CheckersGameState.h"

void ACheckersGameState::HandleLeavingMap()
{
	Super::HandleLeavingMap();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("%s fired."), *FString(__FUNCTION__)));
}
