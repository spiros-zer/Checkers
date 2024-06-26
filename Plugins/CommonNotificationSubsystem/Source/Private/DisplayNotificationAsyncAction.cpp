﻿// Copyright 2024 Spyridon Zervos


#include "DisplayNotificationAsyncAction.h"

#include "NotificationType.h"
#include "Blueprint/UserWidget.h"

UDisplayNotificationAsyncAction* UDisplayNotificationAsyncAction::ShowNotification(UObject* InWorldContextObject,
	const FText InTitle, const FText InBody)
{
	UDisplayNotificationAsyncAction* Action = NewObject<UDisplayNotificationAsyncAction>();
	Action->WorldContextObject = InWorldContextObject;
	Action->Descriptor = UNotificationType::CreateNotificationSingle(InTitle, InBody, FText::FromString("Ok"));
	Action->RegisterWithGameInstance(InWorldContextObject);

	return Action;
}

UDisplayNotificationAsyncAction* UDisplayNotificationAsyncAction::ShowNotificationAcknowledgement(
	UObject* InWorldContextObject, const FText InTitle, const FText InBody)
{
	UDisplayNotificationAsyncAction* Action = NewObject<UDisplayNotificationAsyncAction>();
	Action->WorldContextObject = InWorldContextObject;
	Action->Descriptor = UNotificationType::CreateNotificationSingle(InTitle, InBody, FText::FromString("Ok"));
	Action->RegisterWithGameInstance(InWorldContextObject);

	return Action;
}

UDisplayNotificationAsyncAction* UDisplayNotificationAsyncAction::ShowNotificationSingle(UObject* InWorldContextObject,
	FText InTitle, FText InBody, FText InActionText)
{
	UDisplayNotificationAsyncAction* Action = NewObject<UDisplayNotificationAsyncAction>();
	Action->WorldContextObject = InWorldContextObject;
	Action->Descriptor = UNotificationType::CreateNotificationSingle(InTitle, InBody, InActionText);
	Action->RegisterWithGameInstance(InWorldContextObject);

	return Action;
}

UDisplayNotificationAsyncAction* UDisplayNotificationAsyncAction::ShowNotificationDual(UObject* InWorldContextObject,
	FText InTitle, FText InBody, FText InActionLeftText, FText InActionRightText)
{
	UDisplayNotificationAsyncAction* Action = NewObject<UDisplayNotificationAsyncAction>();
	Action->WorldContextObject = InWorldContextObject;
	Action->Descriptor = UNotificationType::CreateNotificationDouble(InTitle, InBody, InActionLeftText, InActionRightText);
	Action->RegisterWithGameInstance(InWorldContextObject);

	return Action;
}

void UDisplayNotificationAsyncAction::Activate()
{
	Super::Activate();

	if (WorldContextObject && !TargetLocalPlayer)
	{
		if (UUserWidget* UserWidget = Cast<UUserWidget>(WorldContextObject))
		{
			TargetLocalPlayer = UserWidget->GetOwningLocalPlayer<ULocalPlayer>();
		}
		else if (APlayerController* PC = Cast<APlayerController>(WorldContextObject))
		{
			TargetLocalPlayer = PC->GetLocalPlayer();
		}
		else if (UWorld* World = WorldContextObject->GetWorld())
		{
			if (UGameInstance* GameInstance = World->GetGameInstance<UGameInstance>())
			{
				TargetLocalPlayer = GameInstance->GetPrimaryPlayerController(false)->GetLocalPlayer();
			}
		}
	}

	if (TargetLocalPlayer)
	{
		if (UNotificationSubsystem* Messaging = TargetLocalPlayer->GetSubsystem<UNotificationSubsystem>())
		{
			FNotificationActionDelegate ResultCallback = FNotificationActionDelegate::CreateUObject(this, &ThisClass::HandleConfirmationResult);
			Messaging->ShowNotification(Descriptor, ResultCallback);
			return;
		}
	}
	
	// If we couldn't make the confirmation, just handle an unknown result and broadcast nothing
	HandleConfirmationResult(ENotificationAction::Unknown);
}

void UDisplayNotificationAsyncAction::HandleConfirmationResult(ENotificationAction NotificationResult)
{
	OnResult.Broadcast(NotificationResult);

	SetReadyToDestroy();
}
