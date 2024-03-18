// Copyright 2024 Spyridon Zervos


#include "NotificationSubsystem.h"

void UNotificationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UNotificationSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UNotificationSubsystem::ShowNotification(UNotificationType* NotificationType,
	FNotificationActionDelegate ResultCallback)
{
}
