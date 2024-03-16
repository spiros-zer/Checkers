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
	
	virtual void SetupDialog(UNotificationType* UNotificationType, FNotificationActionDelegate ResultCallback);

	virtual void KillDialog();
};

inline void UNotification::SetupDialog(UNotificationType* UNotificationType, FNotificationActionDelegate ResultCallback)
{
}

inline void UNotification::KillDialog()
{
}
