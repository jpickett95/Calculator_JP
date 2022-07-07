#include "CalculatorFrame.h"
#include <wx/gbsizer.h> // used for wxGridBagSizer
#include "ButtonFactory.h"

// Event Table
//wxBEGIN_EVENT_TABLE(CalculatorFrame, wxFrame) // Begin
// Button Events
//EVT_BUTTON(100, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(101, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(102, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(103, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(104, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(105, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(106, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(107, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(108, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(109, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(1001, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(1002, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(1003, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(1004, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(1005, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(1006, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(1007, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(1008, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(1009, CalculatorFrame::OnButtonClick)
//EVT_BUTTON(1010, CalculatorFrame::OnButtonClick)
//wxEND_EVENT_TABLE() // End


CalculatorFrame::CalculatorFrame() : wxFrame(nullptr, wxID_ANY, "Basic Calculator - Jonah Pickett", wxPoint(300,200), wxSize(400, 500))
{
	wxBoxSizer* windowGrid = new wxBoxSizer(wxVERTICAL);

	// Add TextBox display to windowGrid
	windowGrid->Add(currentTextBox = new wxTextCtrl(this, 200, "", wxPoint(-1, -1), wxSize(-1, 75), wxTE_RIGHT), 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
	
	//Buttons
	ButtonFactory buttonFactory; // create a button factory
	wxGridSizer* buttonsGrid = new wxGridSizer(5,4,3,3); // Grid to hold buttons
	buttonsGrid->Add(clearButton = buttonFactory.CreateClearButton(this), 0, wxEXPAND);
	buttonsGrid->Add(posNegButton = buttonFactory.CreatePosNegButton(this), 0, wxEXPAND);
	buttonsGrid->Add(modButton = buttonFactory.CreateModButton(this), 0, wxEXPAND);
	buttonsGrid->Add(divideButton = buttonFactory.CreateDivideButton(this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_7 = buttonFactory.CreateNumButton(7, this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_8 = buttonFactory.CreateNumButton(8, this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_9 = buttonFactory.CreateNumButton(9, this), 0, wxEXPAND);
	buttonsGrid->Add(multiplyButton = buttonFactory.CreateMultiplyButton(this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_4 = buttonFactory.CreateNumButton(4, this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_5 = buttonFactory.CreateNumButton(5, this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_6 = buttonFactory.CreateNumButton(6, this), 0, wxEXPAND);
	buttonsGrid->Add(subtractButton = buttonFactory.CreateSubtractButton(this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_1 = buttonFactory.CreateNumButton(1, this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_2 = buttonFactory.CreateNumButton(2, this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_3 = buttonFactory.CreateNumButton(3, this), 0, wxEXPAND);
	buttonsGrid->Add(addButton = buttonFactory.CreateAddButton(this), 0, wxEXPAND);
	buttonsGrid->Add(binHexDecButton = buttonFactory.CreateBinHexDecButton(this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_0 = buttonFactory.CreateNumButton(0,this), 0, wxEXPAND);	
	buttonsGrid->Add(decimalPointButton = buttonFactory.CreateDecimalPointButton(this), 0, wxEXPAND);
	buttonsGrid->Add(equalsButton = buttonFactory.CreateEqualsButton(this), 0, wxEXPAND);
	buttonsGrid->Layout();
	windowGrid->Add(buttonsGrid, 1, wxEXPAND); // Add buttons to windowGrid

	this->SetSizer(windowGrid); // set window to try to resize according to windowGrid proportions

	// Event Bindings
	numButton_0->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	numButton_1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	numButton_2->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	numButton_3->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	numButton_4->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	numButton_5->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	numButton_6->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	numButton_7->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	numButton_8->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	numButton_9->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	clearButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	posNegButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	modButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	divideButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	multiplyButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	subtractButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	addButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	binHexDecButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	decimalPointButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	equalsButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);

}

void CalculatorFrame::OnButtonClick(wxCommandEvent& evt)
{
	wxObject* object = evt.GetEventObject();
	currentTextBox->AppendText(((wxButton*)object)->GetLabel());
}
