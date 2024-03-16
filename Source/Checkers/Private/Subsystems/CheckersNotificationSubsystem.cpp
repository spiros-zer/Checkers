// Copyright 2024 Spyridon Zervos


#include "Subsystems/CheckersNotificationSubsystem.h"

#include "Notification.h"
#include "Player/CheckersPlayerController.h"
#include "UI/CheckersScreenLayoutBase.h"
#include "NativeGameplayTags.h"

UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_UI_LAYER_SYSTEM, "UI.Layer.System");

void UCheckersNotificationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (NotificationClass)
	{
		NotificationClassPtr = NotificationClass.LoadSynchronous();
	}
}

void UCheckersNotificationSubsystem::ShowNotification(UNotificationType* NotificationType,
	FNotificationActionDelegate ResultCallback)
{
	Super::ShowNotification(NotificationType, ResultCallback);

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (AController* PlayerController = LocalPlayer->GetPlayerController(GetWorld()))
		{
			if (ACheckersPlayerController* CheckersPlayerController = Cast<ACheckersPlayerController>(PlayerController))
			{
				CheckersPlayerController->ScreenLayout->PushWidgetToLayer<UNotification>(TAG_UI_LAYER_SYSTEM, NotificationClassPtr, [NotificationType, ResultCallback](UNotification& Notification)
				{
					Notification.SetupNotification(NotificationType, ResultCallback);
				});
			}
		}
	}
}
