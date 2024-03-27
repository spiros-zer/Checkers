// Copyright 2024 Spyridon Zervos


#include "UI/CheckersNotification.h"

#include "CommonRichTextBlock.h"
#include "CommonTextBlock.h"
#include "ICommonInputModule.h"
#include "NotificationType.h"
#include "Components/DynamicEntryBox.h"
#include "UI/CheckersButtonBase.h"

void UCheckersNotification::SetupNotification(UNotificationType* UNotificationType, FNotificationActionDelegate ResultCallback)
{
	Super::SetupNotification(UNotificationType, ResultCallback);

	Title->SetText(UNotificationType->Title);
	Content->SetText(UNotificationType->Body);

	EntryBox->Reset<UCheckersButtonBase>([](UCheckersButtonBase& CheckersButton)
	{
		CheckersButton.OnClicked().Clear();
	});

	for (const FNotificationContext& Action : UNotificationType->ButtonsContext)
	{
		FDataTableRowHandle ActionRow;

		switch(Action.Result)
		{
		case ENotificationAction::Affirmative:
			ActionRow = ICommonInputModule::GetSettings().GetDefaultClickAction();
			break;
		case ENotificationAction::Cancelled:
		case ENotificationAction::Negative:
			ActionRow = ICommonInputModule::GetSettings().GetDefaultBackAction();
			break;
		default:
			ensure(false);
			continue;
		}

		UCheckersButtonBase* Button = EntryBox->CreateEntry<UCheckersButtonBase>();
		Button->SetTriggeringInputAction(ActionRow);
		Button->OnClicked().AddUObject(this, &ThisClass::CloseConfirmationWindow, Action.Result);
		Button->SetButtonTextInternal(Action.ActionText);

		if (AffirmativeStyle)
		{
			Button->SetStyle(AffirmativeStyle);
		}

		if (Action.Result == ENotificationAction::Negative && NegativeStyle)
		{
			Button->SetStyle(NegativeStyle);
		}
	}

	OnResultCallback = ResultCallback;
}

void UCheckersNotification::CloseConfirmationWindow(ENotificationAction Action)
{
	DeactivateWidget();
	OnResultCallback.ExecuteIfBound(Action);
}
