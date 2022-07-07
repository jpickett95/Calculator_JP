#include "CalculatorFrame.h"
#include <wx/gbsizer.h> // used for wxGridBagSizer

// Event Table
wxBEGIN_EVENT_TABLE(CalculatorFrame, wxFrame) // Begin
// Button Events
EVT_BUTTON(100, CalculatorFrame::OnButtonClick)
EVT_BUTTON(101, CalculatorFrame::OnButtonClick)
EVT_BUTTON(102, CalculatorFrame::OnButtonClick)
EVT_BUTTON(103, CalculatorFrame::OnButtonClick)
EVT_BUTTON(104, CalculatorFrame::OnButtonClick)
EVT_BUTTON(105, CalculatorFrame::OnButtonClick)
EVT_BUTTON(106, CalculatorFrame::OnButtonClick)
EVT_BUTTON(107, CalculatorFrame::OnButtonClick)
EVT_BUTTON(108, CalculatorFrame::OnButtonClick)
EVT_BUTTON(109, CalculatorFrame::OnButtonClick)
EVT_BUTTON(1001, CalculatorFrame::OnButtonClick)
EVT_BUTTON(1002, CalculatorFrame::OnButtonClick)
EVT_BUTTON(1003, CalculatorFrame::OnButtonClick)
EVT_BUTTON(1004, CalculatorFrame::OnButtonClick)
EVT_BUTTON(1005, CalculatorFrame::OnButtonClick)
EVT_BUTTON(1006, CalculatorFrame::OnButtonClick)
EVT_BUTTON(1007, CalculatorFrame::OnButtonClick)
EVT_BUTTON(1008, CalculatorFrame::OnButtonClick)
EVT_BUTTON(1009, CalculatorFrame::OnButtonClick)
EVT_BUTTON(1010, CalculatorFrame::OnButtonClick)
wxEND_EVENT_TABLE() // End


CalculatorFrame::CalculatorFrame() : wxFrame(nullptr, wxID_ANY, "Basic Calculator - Jonah Pickett", wxPoint(300,200), wxSize(400, 500))
{
	wxBoxSizer* windowGrid = new wxBoxSizer(wxVERTICAL);

	// Add TextBox display to windowGrid
	windowGrid->Add(currentTextBox = new wxTextCtrl(this, 200, "", wxPoint(-1, -1), wxSize(-1, 75), wxTE_RIGHT), 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
	
	//Buttons
	wxGridSizer* buttonsGrid = new wxGridSizer(5,4,3,3); // Grid to hold buttons
	buttonsGrid->Add(clearButton = new wxButton(this, 1001, "Clr"), 0, wxEXPAND);
	buttonsGrid->Add(posNegButton = new wxButton(this, 1002, "+/-"), 0, wxEXPAND);
	buttonsGrid->Add(modButton = new wxButton(this, 1003, "%"), 0, wxEXPAND);
	buttonsGrid->Add(divideButton = new wxButton(this, 1004, "/"), 0, wxEXPAND);
	buttonsGrid->Add(numButton_7 = new wxButton(this, 107, "7"), 0, wxEXPAND);
	buttonsGrid->Add(numButton_8 = new wxButton(this, 108, "8"), 0, wxEXPAND);
	buttonsGrid->Add(numButton_9 = new wxButton(this, 109, "9"), 0, wxEXPAND);
	buttonsGrid->Add(multiplyButton = new wxButton(this, 1005, "*"), 0, wxEXPAND);
	buttonsGrid->Add(numButton_4 = new wxButton(this, 104, "4"), 0, wxEXPAND);
	buttonsGrid->Add(numButton_5 = new wxButton(this, 105, "5"), 0, wxEXPAND);
	buttonsGrid->Add(numButton_6 = new wxButton(this, 106, "6"), 0, wxEXPAND);
	buttonsGrid->Add(subtractButton = new wxButton(this, 1006, "-"), 0, wxEXPAND);
	buttonsGrid->Add(numButton_1 = new wxButton(this, 101, "1"), 0, wxEXPAND);
	buttonsGrid->Add(numButton_2 = new wxButton(this, 102, "2"), 0, wxEXPAND);
	buttonsGrid->Add(numButton_3 = new wxButton(this, 103, "3"), 0, wxEXPAND);
	buttonsGrid->Add(addButton = new wxButton(this, 1007, "+"), 0, wxEXPAND);
	buttonsGrid->Add(binHexDecButton = new wxButton(this, 1008, "BIN\nHEX\nDEC"), 0, wxEXPAND);
	buttonsGrid->Add(numButton_0 = new wxButton(this, 100, "0"), 0, wxEXPAND);
	buttonsGrid->Add(decimalPointButton = new wxButton(this, 1009, "."), 0, wxEXPAND);
	buttonsGrid->Add(equalsButton = new wxButton(this, 1010, "="), 0, wxEXPAND);
	buttonsGrid->Layout();
	windowGrid->Add(buttonsGrid, 1, wxEXPAND); // Add buttons to windowGrid

	this->SetSizer(windowGrid); // set window to try to resize according to windowGrid proportions
}

void CalculatorFrame::OnButtonClick(wxCommandEvent& evt)
{
	wxObject* object = evt.GetEventObject();
	currentTextBox->AppendText(((wxButton*)object)->GetLabel());
}
