// Copyright 2024 Spyridon Zervos


#include "UI/VirtualKeyboard/VirtualKeyboardTypes.h"

bool FKeyInfo::operator==(const FKeyInfo& Other) const
{
	return Key == Other.Key
	&& KeyMain.EqualTo(Other.KeyMain)
	&& KeySecondary.EqualTo(Other.KeySecondary)
	&& bIsPathSafe == Other.bIsPathSafe;
}

bool FKeyInfo::operator!=(const FKeyInfo& Other) const
{
	return !(*this == Other);
}

bool FVirtualKeyboardKeyDataBase::operator==(const FVirtualKeyboardKeyDataBase& Other) const
{
	return KeyName.EqualTo(Other.KeyName)
		&& KeyInfo == Other.KeyInfo;
}

bool FVirtualKeyboardKeyDataBase::operator!=(const FVirtualKeyboardKeyDataBase& Other) const
{
	return !(*this == Other);
}
