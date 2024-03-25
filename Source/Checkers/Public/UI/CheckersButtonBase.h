// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"

#include "CheckersButtonBase.generated.h"

/**
 * The base button of the project.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class CHECKERS_API UCheckersButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:

	/** Used in order to change the button's text from C++ side. It should only be used from C++ and not blueprints. */
	UFUNCTION(BlueprintCallable)
	void SetButtonTextInternal(const FText& InText);

	/** Diode to update the button's text when it has been changed from C++ side - eg. notification creation. All
	 * implemented interfaces that change the button's text have to do it through this function for DRY. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateButtonText(const FText& InText);
};
