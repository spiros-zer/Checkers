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

	EntryBox_Buttons->Reset<UCheckersButtonBase>([](UCheckersButtonBase& CheckersButton)
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
		case ENotificationAction::Negative:
			ActionRow = ICommonInputModule::GetSettings().GetDefaultBackAction();
			break;
		case ENotificationAction::Cancelled:
			ActionRow = CancelAction;
			break;
		default:
			ensure(false);
			continue;
		}

		UCheckersButtonBase* Button = EntryBox_Buttons->CreateEntry<UCheckersButtonBase>();
		Button->SetTriggeringInputAction(ActionRow);
		Button->OnClicked().AddUObject(this, &ThisClass::CloseConfirmationWindow, Action.Result);
		Button->SetButtonTextInternal(Action.ActionText);
	}

	OnResultCallback = ResultCallback;
}

void UCheckersNotification::CloseConfirmationWindow(ENotificationAction Action)
{
	DeactivateWidget();
	OnResultCallback.ExecuteIfBound(Action);
}
