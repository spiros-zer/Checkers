// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "CommonActionWidget.h"
#include "CheckersActionWidget.generated.h"

class UEnhancedInputLocalPlayerSubsystem;

/**
 * 
 */
UCLASS()
class CHECKERS_API UCheckersActionWidget : public UCommonActionWidget
{
	GENERATED_BODY()

public:
	
	//~ Begin UCommonActionWidget interface
	virtual FSlateBrush GetIcon() const override;
	//~ End of UCommonActionWidget interface

	/** The Enhanced Input Action that is associated with this Common Input action. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	const TObjectPtr<UInputAction> AssociatedInputAction;

private:

	UEnhancedInputLocalPlayerSubsystem* GetEnhancedInputSubsystem() const;
};
