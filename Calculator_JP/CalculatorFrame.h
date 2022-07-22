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
	wxButton* binaryButton; // Bin
	wxButton* posNegButton; // +/-
	wxButton* decimalButton; // Decimal
	wxButton* hexadecimalButton; // Hex
	// Text Box
	wxTextCtrl* currentTextBox; // Display current number

	// Bools
	bool hitEquals = false;
	bool hitDecimal = false;
	bool hitHexadecimal = false;
	bool hitBinary = false;
public:
	CalculatorFrame(); // Constructor
	void OnButtonClick(wxCommandEvent& evt); // button click event
	wxTextCtrl* GetTextBox();
};

