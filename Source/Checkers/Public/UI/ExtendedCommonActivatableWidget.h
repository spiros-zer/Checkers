// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "ExtendedCommonActivatableWidget.generated.h"

class UInputAction;
DECLARE_DYNAMIC_DELEGATE_OneParam(FInputActionExecutedDelegate, FName, ActionName);

USTRUCT(BlueprintType)
struct FInputActionBindingHandle
{
	GENERATED_BODY()
	
	FUIActionBindingHandle Handle;
};
/**
 * 
 */
UCLASS(meta = (DisableNativeTick))
class CHECKERS_API UExtendedCommonActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	
	virtual void NativeDestruct() override;

	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget, meta = (DeprecatedFunction))
	void RegisterBindingWithDataTable(FDataTableRowHandle InputAction, const FInputActionExecutedDelegate& Callback, FInputActionBindingHandle& BindingHandle);

	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget, meta = (DeprecatedFunction))
	void RegisterBindingWithAction(UInputAction* InputAction, const FInputActionExecutedDelegate& Callback, FInputActionBindingHandle& BindingHandle);

	void OnExecuteInputAction();
	
	/** Registers an Input Action to be displayed in the action bar of the widget if any is present. */
	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget)
	void RegisterBinding(UInputAction* InputAction, FInputActionBindingHandle& BindingHandle);
	
	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget)
	void UnregisterBinding(FInputActionBindingHandle BindingHandle);

	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget)
	void UnregisterAllBindings();

private:
	
	TArray<FUIActionBindingHandle> BindingHandles;
};
