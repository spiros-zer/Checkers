// Copyright 2024 Spyridon Zervos


#include "NotificationType.h"

UNotificationType* UNotificationType::CreateNotificationSingle(const FText& InTitle, const FText& InContent, const FText& InActionText)
{
	UNotificationType* NotificationType = NewObject<UNotificationType>();
	NotificationType->Title = InTitle;
	NotificationType->Body = InContent;

	FNotificationContext NotificationContext;
	NotificationContext.Result = ENotificationAction::Affirmative;
	NotificationContext.ActionText = InActionText;

	NotificationType->ButtonsContext.Add(NotificationContext);

	return NotificationType;
}

UNotificationType* UNotificationType::CreateNotificationDouble(const FText& InTitle, const FText& InContent,
	const FText& InActionLeftText, const FText& InActionRightText)
{
	UNotificationType* NotificationType = NewObject<UNotificationType>();
	NotificationType->Title = InTitle;
	NotificationType->Body = InContent;

	FNotificationContext NotificationContextAffirmative;
	NotificationContextAffirmative.Result = ENotificationAction::Affirmative;
	NotificationContextAffirmative.ActionText = InActionLeftText;

	FNotificationContext NotificationContextNegative;
	NotificationContextNegative.Result = ENotificationAction::Cancelled;
	NotificationContextNegative.ActionText = InActionRightText;

	NotificationType->ButtonsContext.Add(NotificationContextAffirmative);
	NotificationType->ButtonsContext.Add(NotificationContextNegative);

	return NotificationType;
}
