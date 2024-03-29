// Copyright 2024 Spyridon Zervos

#pragma once

#include "ButtonCosmetics.generated.h"

class UCommonTextStyle;

/**
 * 
 */
UINTERFACE(MinimalAPI, meta = (Blueprintable))
class UButtonCosmetics : public UInterface
{
	GENERATED_BODY()
};

class IButtonCosmetics
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Text")
	void SetBtnTxtStyle(TSubclassOf<UCommonTextStyle> InTxtStyle);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Text")
	void SetBtnTxt(const FText& InText);
};
