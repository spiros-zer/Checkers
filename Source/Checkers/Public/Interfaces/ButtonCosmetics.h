// Copyright 2024 Spyridon Zervos

#pragma once

#include "ButtonCosmetics.generated.h"

class UCommonTextStyle;

/**
 * Interface responsible for cosmetic events regarding the buttons.
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

	/** Sets the button's text style. this is implemented due to the fact that if a text style is defined in the button
	 * style it will still not be applied on its own. */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Text")
	void SetBtnTxtStyle(TSubclassOf<UCommonTextStyle> InTxtStyle);

	/** Sets the button text to the input value */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Text", meta = (AutoCreateRefTerm="FText"))
	void SetBtnTxt(const FText& InText);
};
