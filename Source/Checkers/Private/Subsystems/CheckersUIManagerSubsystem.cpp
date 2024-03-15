// Copyright 2024 Spyridon Zervos


#include "Subsystems/CheckersUIManagerSubsystem.h"

#include "UI/CheckersScreenLayoutBase.h"

void UCheckersUIManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (ScreenLayoutBaseClass.IsValid())
	{
		ScreenLayoutBase = NewObject<UCheckersScreenLayoutBase>(this, ScreenLayoutBaseClass.LoadSynchronous());
	}
}

void UCheckersUIManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();

	ScreenLayoutBase = nullptr;
}
