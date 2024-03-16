// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "Notification.h"
#include "CheckersNotification.generated.h"

class UDynamicEntryBox;
class UCommonRichTextBlock;
class UCommonTextBlock;
/**
 * 
 */
UCLASS()
class CHECKERS_API UCheckersNotification : public UNotification
{
	GENERATED_BODY()

public:

	virtual void SetupNotification(UNotificationType* UNotificationType, FNotificationActionDelegate ResultCallback) override;
	
protected:

	virtual void CloseConfirmationWindow(ENotificationAction Action);

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> Title;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UCommonRichTextBlock> Content;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UDynamicEntryBox> EntryBox_Buttons;

	UPROPERTY(EditDefaultsOnly, meta = (RowType = "/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle CancelAction;
	
	FNotificationActionDelegate OnResultCallback;
};
