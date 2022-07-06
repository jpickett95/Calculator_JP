#pragma once

#include "wx/wx.h"

class CalculatorFrame : public wxFrame // inherits from wxFrame
{
private:
	// Buttons
	wxButton* numButton_0;
	wxButton* numButton_1;
	wxButton* numButton_2;
	wxButton* numButton_3;
	wxButton* numButton_4;
	wxButton* numButton_5;
	wxButton* numButton_6;
	wxButton* numButton_7;
	wxButton* numButton_8;
	wxButton* numButton_9;
	wxButton* addButton;
	wxButton* subtractButton;
	wxButton* multiplyButton;
	wxButton* divideButton;
	wxButton* equalsButton;
	wxButton* clearButton;
	wxButton* modButton; // modulus
	wxButton* decimalPointButton; // "."
	wxButton* posNegButton; // +/-
	wxButton* binButton; // Binary 
	wxButton* hexButton; // Hexdecimal
	wxButton* decButton; // Decimal
public:
	CalculatorFrame(); // Constructor
};

