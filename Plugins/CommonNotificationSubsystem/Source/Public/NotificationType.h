// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "NotificationSubsystem.h"
#include "UObject/Object.h"
#include "NotificationType.generated.h"

USTRUCT(BlueprintType)
struct FNotificationContext
{
	GENERATED_BODY()
	
	/** The dialog option to provide. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ENotificationAction Result = ENotificationAction::Unknown;

	/** Text that will be displayed in the button related to this action. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ActionText;

	bool operator==(const FNotificationContext& Other) const
	{
		return Result == Other.Result && ActionText.EqualTo(Other.ActionText);
	}
};

/**
 * Describes the type of the notification. Currently supporting notification with one and two buttons - single and
 * double. 
 */
UCLASS()
class COMMONNOTIFICATIONSUBSYSTEM_API UNotificationType : public UObject
{
	GENERATED_BODY()

public:
	
	static UNotificationType* CreateNotificationSingle(const FText& InTitle, const FText& InContent, const FText& InActionText);
	
	static UNotificationType* CreateNotificationDouble(const FText& InTitle, const FText& InContent, TArray<FText> InActionTexts);

	/** The header of the message to display */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;
	
	/** The body of the message to display */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Body;

	/** The confirm button's input action to use. */
	UPROPERTY(BlueprintReadWrite)
	TArray<FNotificationContext> ButtonsContext;
};
