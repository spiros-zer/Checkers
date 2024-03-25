// Copyright 2024 Spyridon Zervos


#include "UI/CheckersButtonBase.h"

void UCheckersButtonBase::SetButtonTextInternal(const FText& InText)
{
	/** Since no text related widget is defined and binded in C++. This is an issue because when text is updated from
	 * C++ there is no way to update it in the button. Also, not every button needs text. That's why I need another way
	 * for when this is necessary. That's were UpdateButtonText(...) comes to play as it acts as a Diode to update the
	 * button's text when it has been changed from C++ side - eg. notification creation.*/
	UpdateButtonText(InText);
}
