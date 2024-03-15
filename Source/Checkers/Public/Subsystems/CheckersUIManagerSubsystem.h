// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CheckersUIManagerSubsystem.generated.h"

class UCommonActivatableWidget;
class UCheckersScreenLayoutBase;

/**
 * 
 */
UCLASS(Config = Game)
class CHECKERS_API UCheckersUIManagerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION(BlueprintGetter)
	UCheckersScreenLayoutBase* GetScreenLayout() const {return ScreenLayoutBase;}
	
private:

	UPROPERTY(BlueprintGetter = "GetScreenLayout")
	TObjectPtr<UCheckersScreenLayoutBase> ScreenLayoutBase{};

	UPROPERTY(Config)
	TSoftClassPtr<UCheckersScreenLayoutBase> ScreenLayoutBaseClass{};
};
