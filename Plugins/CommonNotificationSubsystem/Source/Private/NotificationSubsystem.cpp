// Copyright 2024 Spyridon Zervos


#include "NotificationSubsystem.h"

bool UNotificationSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	if (!CastChecked<ULocalPlayer>(Outer)->GetGameInstance()->IsDedicatedServerInstance())
	{
		TArray<UClass*> ChildClasses;
		GetDerivedClasses(GetClass(), ChildClasses, false);

		// Only create an instance if there is no override implementation defined elsewhere
		return ChildClasses.Num() == 0;
	}
	return false;
}

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
