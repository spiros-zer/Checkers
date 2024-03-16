﻿// Copyright 2024 Spyridon Zervos

#pragma once

#include "Subsystems/LocalPlayerSubsystem.h"

#include "NotificationSubsystem.generated.h"

class UNotificationType;

/** Context from button pressed */
UENUM(BlueprintType)
enum class ENotificationAction : uint8
{
	Affirmative,
	Negative,
	Cancelled,
	Killed,
	Unknown UMETA(Hidden)
};

DECLARE_DELEGATE_OneParam(FNotificationActionDelegate, ENotificationAction);

/**
 * Subsystem responsible for displaying notifications. You need to subclass from this and override the ShowNotification()
 * to work properly.
 */
UCLASS()
class COMMONNOTIFICATIONSUBSYSTEM_API UNotificationSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	virtual void Deinitialize() override;

	virtual void ShowNotification(UNotificationType* DialogDescriptor, FNotificationActionDelegate ResultCallback = FNotificationActionDelegate());
};

inline void UNotificationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

inline void UNotificationSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

inline void UNotificationSubsystem::ShowNotification(UNotificationType* DialogDescriptor,
	FNotificationActionDelegate ResultCallback)
{
}