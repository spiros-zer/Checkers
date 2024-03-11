// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "CheckersScreenLayoutBase.generated.h"

class UCommonActivatableWidget;
class UCommonActivatableWidgetContainerBase;

/**
 * The base layout of the player screen. 
 */
UCLASS()
class CHECKERS_API UCheckersScreenLayoutBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:

	UCommonActivatableWidget* PushWidgetToLayer(UPARAM(meta = (Categories = "UI.Layer")) FGameplayTag LayerTag, TSubclassOf<UCommonActivatableWidget> ActivatableWidgetClass);

protected:

	/** Registers a widget to the layer denote by the gameplay tag. */
	UFUNCTION(BlueprintCallable, Category="Layer")
	void RegisterLayer(UPARAM(meta = (Categories = "UI.Layer")) FGameplayTag LayerTag, UCommonActivatableWidgetContainerBase* LayerWidget);
	
private:

	/** Maps the gameplay tags with the layers they represent. */
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UCommonActivatableWidgetContainerBase>> Layers;
};
