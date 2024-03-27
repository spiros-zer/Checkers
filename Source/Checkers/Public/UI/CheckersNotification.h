// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "Notification.h"
#include "CheckersNotification.generated.h"

class UCommonButtonStyle;
class UDynamicEntryBox;
class UCommonRichTextBlock;
class UCommonTextBlock;

/**
 * The notification base class of checkers.
 */
UCLASS()
class CHECKERS_API UCheckersNotification : public UNotification
{
	GENERATED_BODY()

public:

	virtual void SetupNotification(UNotificationType* UNotificationType, FNotificationActionDelegate ResultCallback) override;
	
protected:

	/** Called when any of the entry box's buttons are clicked. */
	virtual void CloseConfirmationWindow(ENotificationAction Action);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> Title{};

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCommonRichTextBlock> Content{};

	/** Holds the notification's button(s). */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UDynamicEntryBox> EntryBox{};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "NotificationCosmetics|Buttons")
	TSubclassOf<UCommonButtonStyle> AffirmativeStyle{};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "NotificationCosmetics|Buttons")
	TSubclassOf<UCommonButtonStyle> NegativeStyle{};
	
	FNotificationActionDelegate OnResultCallback{};
};
