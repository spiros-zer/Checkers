// Copyright 2024 Spyridon Zervos


#include "Player/CheckersPlayerController.h"

#include "Blueprint/UserWidget.h"

void ACheckersPlayerController::ShowLoadingScreen()
{
	if (LoadingScreenClass)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("%s fired!"), *FString(__FUNCTION__)));
		if (UUserWidget* LoadingScreenWidget = CreateWidget<UUserWidget>(this, LoadingScreenClass, FName(TEXT("Loading Screen"))))
		{
			LoadingScreenWidget->AddToViewport(9999);
		}
	}
}

UCheckersScreenLayoutBase* ACheckersPlayerController::CreateAndShowScreenLayout_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("CheckersPlayerController | %s: Should override this."), *FString(__FUNCTION__)));
	return nullptr;
}
