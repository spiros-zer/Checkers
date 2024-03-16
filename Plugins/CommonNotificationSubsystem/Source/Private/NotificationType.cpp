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

UNotificationType* UNotificationType::CreateNotificationDouble(const FText& InTitle, const FText& InContent, TArray<FText> InActionTexts)
{
	UNotificationType* NotificationType = NewObject<UNotificationType>();
	NotificationType->Title = InTitle;
	NotificationType->Body = InContent;

	FNotificationContext NotificationContextAffirmative;
	NotificationContextAffirmative.Result = ENotificationAction::Affirmative;
	NotificationContextAffirmative.ActionText = InActionTexts[0];

	FNotificationContext NotificationContextNegative;
	NotificationContextNegative.Result = ENotificationAction::Cancelled;
	NotificationContextNegative.ActionText = InActionTexts[1];

	NotificationType->ButtonsContext.Add(NotificationContextAffirmative);
	NotificationType->ButtonsContext.Add(NotificationContextNegative);

	return NotificationType;
}
