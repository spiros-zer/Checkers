// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "NotificationSubsystem.h"
#include "CheckersNotificationSubsystem.generated.h"

class UNotification;

/**
 * 
 */
UCLASS(Config = Game)
class CHECKERS_API UCheckersNotificationSubsystem : public UNotificationSubsystem
{
	GENERATED_BODY()

public:

	UCheckersNotificationSubsystem() {}

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void ShowNotification(UNotificationType* NotificationType, FNotificationActionDelegate ResultCallback = FNotificationActionDelegate()) override;
	
private:
	
	UPROPERTY()
	TSubclassOf<UNotification> NotificationClassPtr;

	UPROPERTY(config)
	TSoftClassPtr<UNotification> NotificationClass;
};
