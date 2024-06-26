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
UCLASS(Abstract)
class COMMONNOTIFICATIONSUBSYSTEM_API UNotificationSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
public:

	UNotificationSubsystem() {}

	/** Allows this subsystem to be created or not depending if there are derived classes or not. Can be used instead
	 * of UCLASS(Abstract). In this scenario I will be using Abstract so consider this obsolete and to be removed */
	//virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	virtual void Deinitialize() override;

	virtual void ShowNotification(UNotificationType* NotificationType, FNotificationActionDelegate ResultCallback = FNotificationActionDelegate());
};
