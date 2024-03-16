// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "CheckersNotificationSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CHECKERS_API UCheckersNotificationSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	
};
