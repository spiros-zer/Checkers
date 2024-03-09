// Copyright 2024 Spyridon Zervos


#include "UI/CheckersActionWidget.h"

#include "CommonInputBaseTypes.h"
#include "CommonInputSubsystem.h"
#include "EnhancedInputSubsystems.h"

FSlateBrush UCheckersActionWidget::GetIcon() const
{
	// If there is an Enhanced Input action associated with this widget, then search for any
	// keys bound to that action and display those instead of the default data table settings.
	// This covers the case of when a player has rebound a key to something else
	if (AssociatedInputAction)
	{
		const UCommonInputSubsystem* CommonInputSubsystem = GetInputSubsystem();
		const UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = GetEnhancedInputSubsystem();
		TArray<FKey> BoundKeys = EnhancedInputSubsystem->QueryKeysMappedToAction(AssociatedInputAction);

		if (FSlateBrush SlateBrush; !BoundKeys.IsEmpty() && UCommonInputPlatformSettings::Get()->TryGetInputBrush(SlateBrush, BoundKeys[0], CommonInputSubsystem->GetCurrentInputType(), CommonInputSubsystem->GetCurrentGamepadName()))
		{
			return SlateBrush;
		}
	}
	
	return Super::GetIcon();
}

UEnhancedInputLocalPlayerSubsystem* UCheckersActionWidget::GetEnhancedInputSubsystem() const
{
	const UWidget* BoundWidget = DisplayedBindingHandle.GetBoundWidget();
	const ULocalPlayer* BindingOwner = BoundWidget ? BoundWidget->GetOwningLocalPlayer() : GetOwningLocalPlayer();
	
	return BindingOwner->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
}