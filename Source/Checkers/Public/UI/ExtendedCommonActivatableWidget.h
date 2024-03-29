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
 * An extended activatable widget offers the ability to add more actions displayed in the back handler action bar. This
 * is done by using one of the register binding functions to register an input action.
 */
UCLASS(meta = (DisableNativeTick))
class CHECKERS_API UExtendedCommonActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	
	virtual void NativeDestruct() override;

	/** Deprecated since in its current state it produces error invalid input action row provided. Don't have plans to
	 * fix it currently. */
	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget, meta = (DeprecatedFunction))
	void RegisterBindingWithDataTable(FDataTableRowHandle InputAction, const FInputActionExecutedDelegate& Callback, FInputActionBindingHandle& BindingHandle);

	/** Registers an Input Action to be displayed in the action bar of the widget if any is present. If the the action is
	 * pressed then the callback set in the blueprint event of this will be executed. */
	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget)
	void RegisterBindingWithAction(UInputAction* InputAction, const FInputActionExecutedDelegate& Callback, FInputActionBindingHandle& BindingHandle);

	void OnExecuteInputAction();
	
	/** Registers an Input Action to be displayed in the action bar of the widget if any is present. If the the action is
	 * pressed then the OnExecuteInputAction() will fire. */
	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget)
	void RegisterBinding(UInputAction* InputAction, FInputActionBindingHandle& BindingHandle);
	
	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget)
	void UnregisterBinding(FInputActionBindingHandle BindingHandle);

	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget)
	void UnregisterAllBindings();

private:
	
	TArray<FUIActionBindingHandle> BindingHandles;
};
