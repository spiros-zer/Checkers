// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "DisplayNotificationAsyncAction.generated.h"

class UNotificationType;
enum class ENotificationAction : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotificationActionDelegateMC, ENotificationAction, Action);

/**
 * 
 */
UCLASS()
class COMMONNOTIFICATIONSUBSYSTEM_API UDisplayNotificationAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncAction* ShowNotification(UObject* InWorldContextObject, const FText InTitle, const FText InBody);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncAction* ShowNotificationAcknowledgement(UObject* InWorldContextObject, FText InTitle, FText InBody);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncAction* ShowNotificationSingle(UObject* InWorldContextObject, FText InTitle, FText InBody, FText InActionText);
	
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncAction* ShowNotificationDual(UObject* InWorldContextObject, FText InTitle, FText InBody, FText InActionLeftText, FText InActionRightText);
	
	virtual void Activate() override;
	
	UPROPERTY(BlueprintAssignable)
	FNotificationActionDelegateMC OnResult;

private:
	
	void HandleConfirmationResult(ENotificationAction NotificationResult);

	UPROPERTY(Transient)
	TObjectPtr<UObject> WorldContextObject;

	UPROPERTY(Transient)
	TObjectPtr<ULocalPlayer> TargetLocalPlayer;

	UPROPERTY(Transient)
	TObjectPtr<UNotificationType> Descriptor;
};
