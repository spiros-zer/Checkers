// Copyright 2024 Spyridon Zervos


#include "UI/CheckersScreenLayoutBase.h"

#include "Widgets/CommonActivatableWidgetContainer.h"
#include "CommonActivatableWidget.h"

UCommonActivatableWidget* UCheckersScreenLayoutBase::PushWidgetToLayer(FGameplayTag LayerTag, TSubclassOf<UCommonActivatableWidget> ActivatableWidgetClass)
{
	if (UCommonActivatableWidgetContainerBase* Layer = Layers.FindRef(LayerTag))
	{
		return Layer->AddWidget<UCommonActivatableWidget>(ActivatableWidgetClass, [](UCommonActivatableWidget&) {});
	}

	return nullptr;
}

void UCheckersScreenLayoutBase::RegisterLayer(FGameplayTag LayerTag, UCommonActivatableWidgetContainerBase* LayerWidget)
{
	Layers.Add(LayerTag, LayerWidget);
}
