// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CheckersPlayerController.generated.h"

class UMainMenu;

/**
 * 
 */
UCLASS()
class CHECKERS_API ACheckersPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	void ShowLoadingScreen();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class UUserWidget> LoadingScreenClass;
};
