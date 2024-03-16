// Copyright 2024 Spyridon Zervos


#include "NotificationType.h"

UNotificationType* UNotificationType::CreateNotificationSingle(const FText& InTitle, const FText& InContent)
{
	UNotificationType* NotificationType = NewObject<UNotificationType>();
	NotificationType->Title = InTitle;
	NotificationType->Body = InContent;

	FNotificationContext ConfirmAction;
	ConfirmAction.Result = ENotificationAction::Affirmative;

	NotificationType->ButtonsContext.Add(ConfirmAction);

	return NotificationType;
}

UNotificationType* UNotificationType::CreateNotificationDouble(const FText& InTitle, const FText& InContent)
{
	UNotificationType* NotificationType = NewObject<UNotificationType>();
	NotificationType->Title = InTitle;
	NotificationType->Body = InContent;

	FNotificationContext ConfirmAction;
	ConfirmAction.Result = ENotificationAction::Affirmative;

	FNotificationContext CancelAction;
	CancelAction.Result = ENotificationAction::Cancelled;

	NotificationType->ButtonsContext.Add(ConfirmAction);
	NotificationType->ButtonsContext.Add(CancelAction);

	return NotificationType;
}
