// Copyright 2024 Spyridon Zervos


#include "UI/CheckersScreenLayoutBase.h"

#include "GameplayTagContainer.h"

void UCheckersScreenLayoutBase::RegisterLayer(FGameplayTag LayerTag, UCommonActivatableWidgetContainerBase* LayerWidget)
{
	Layers.Add(LayerTag, LayerWidget);
}
