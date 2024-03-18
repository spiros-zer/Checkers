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
class CHECKERS_API UDisplayNotificationAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncAction* ShowNotification(UObject* InWorldContextObject, FText InTitle, FText InBody, FText InActionText);
	
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
