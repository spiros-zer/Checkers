// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VirtualKeyboardTypes.generated.h"

USTRUCT(BlueprintType)
struct FKeyInfo
{
	GENERATED_BODY()

	FKeyInfo() {}
	
	FKey GetKey() const {return Key;}
	
	void SetKey(const FKey& InKey) {Key = InKey;}

	bool operator==(const FKeyInfo& Other) const;

	bool operator!=(const FKeyInfo& Other) const;
	
	/** The Upper / not-shift-pressed value this key outputs when pressed. */
	UPROPERTY(EditAnywhere, Category = "VirtualKeyboard")
	FText KeyMain{};

	/** The Lower / shift-pressed value this key outputs when pressed. */
	UPROPERTY(EditAnywhere, Category = "VirtualKeyboard")
	FText KeySecondary{};

	/** Safe to use as a windows file */
	UPROPERTY(EditAnywhere, Category = "VirtualKeyboard")
	bool bIsPathSafe{true};

private:
	
	/** Key this action is bound to	*/
	UPROPERTY(EditAnywhere, Category = "CommonInput")
	FKey Key{};
};

USTRUCT(BlueprintType)
struct FVirtualKeyboardKeyDataBase : public FTableRowBase
{
	GENERATED_BODY()

	FVirtualKeyboardKeyDataBase() {}

	/** The key this row is about */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VirtualKeyboard")
	FText KeyName{};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VirtualKeyboard")
	FKeyInfo KeyInfo{};

	bool operator==(const FVirtualKeyboardKeyDataBase&) const;

	bool operator!=(const FVirtualKeyboardKeyDataBase&) const;
};

/**
 * 
 */
UCLASS()
class CHECKERS_API UVirtualKeyboardTypes : public UObject
{
	GENERATED_BODY()
};
