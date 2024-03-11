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
UCLASS()
class CHECKERS_API UCheckersUIManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintGetter)
	UCheckersScreenLayoutBase* GetScreenLayout() const {return ScreenLayout;}

	UFUNCTION(BlueprintCallable, BlueprintSetter)
	void SetScreenLayout(UCheckersScreenLayoutBase* InScreenLayout) {ScreenLayout = InScreenLayout;}

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintGetter = "GetScreenLayout", BlueprintSetter = "SetScreenLayout")
	TObjectPtr<UCheckersScreenLayoutBase> ScreenLayout {};
};
