// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CheckersGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CHECKERS_API UCheckersGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	virtual void Init() override;

	UFUNCTION(BlueprintNativeEvent)
	void BeginShowingLoadingScreen(const FString& MapName);
};
