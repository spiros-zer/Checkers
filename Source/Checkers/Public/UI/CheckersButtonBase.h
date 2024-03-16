// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"

#include "CheckersButtonBase.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class CHECKERS_API UCheckersButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable)
	void SetButtonTextInternal(const FText& InText);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateButtonText(const FText& InText);
};
