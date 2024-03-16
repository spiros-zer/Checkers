// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CheckersPlayerController.generated.h"

class UCheckersScreenLayoutBase;
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ScreenLayout")
	TObjectPtr<UCheckersScreenLayoutBase> ScreenLayout{};
	
protected:

	UFUNCTION(BlueprintNativeEvent)
	UCheckersScreenLayoutBase* CreateAndShowScreenLayout();	
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ScreenLayout")
	TSubclassOf<UCheckersScreenLayoutBase> ScreenLayoutClass{};
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UUserWidget> LoadingScreenClass{};
};
