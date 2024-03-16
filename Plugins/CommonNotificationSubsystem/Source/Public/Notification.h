// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "NotificationSubsystem.h"
#include "Notification.generated.h"

class UNotificationType;
/**
 * 
 */
UCLASS()
class COMMONNOTIFICATIONSUBSYSTEM_API UNotification : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	
	virtual void SetupNotification(UNotificationType* UNotificationType, FNotificationActionDelegate ResultCallback);

	virtual void KillNotification();
};

inline void UNotification::SetupNotification(UNotificationType* UNotificationType, FNotificationActionDelegate ResultCallback)
{
}

inline void UNotification::KillNotification()
{
}
