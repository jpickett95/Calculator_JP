#include "CalculatorFrame.h"
#include <wx/gbsizer.h> // used for wxGridBagSizer
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"

CalculatorFrame::CalculatorFrame() : wxFrame(nullptr, wxID_ANY, "Basic Calculator - Jonah Pickett", wxPoint(300,200), wxSize(400, 500))
{
	wxBoxSizer* windowGrid = new wxBoxSizer(wxVERTICAL);

	// Add TextBox display to windowGrid
	windowGrid->Add(currentTextBox = new wxTextCtrl(this, 200, "", wxPoint(-1, -1), wxSize(-1, 75), wxTE_RIGHT | wxTE_READONLY | wxTE_NO_VSCROLL), 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
	wxFont textBoxFont = wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	currentTextBox->SetFont(textBoxFont);
	currentTextBox->SetMaxLength(18);


	//Buttons
	ButtonFactory buttonFactory; // create a button factory
	wxGridSizer* buttonsGrid = new wxGridSizer(6,4,3,3); // Grid to hold buttons
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
	buttonsGrid->Add(decimalButton = buttonFactory.CreateDecimalButton(this), 0, wxEXPAND);
	buttonsGrid->Add(numButton_0 = buttonFactory.CreateNumButton(0,this), 0, wxEXPAND);	
	buttonsGrid->Add(binaryButton = buttonFactory.CreateBinaryButton(this), 0, wxEXPAND);
	buttonsGrid->Add(equalsButton = buttonFactory.CreateEqualsButton(this), 0, wxEXPAND);
	buttonsGrid->Add(hexadecimalButton = buttonFactory.CreateHexadecimalButton(this), 0, wxEXPAND);
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
	decimalButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	binaryButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	hexadecimalButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);
	equalsButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalculatorFrame::OnButtonClick, this);

}

void CalculatorFrame::OnButtonClick(wxCommandEvent& evt)
{
	wxObject* object = evt.GetEventObject();
	std::string label = (std::string)((wxButton*)object)->GetLabelText();
	transform(label.begin(), label.end(), label.begin(), std::toupper);
	CalculatorProcessor* processor = CalculatorProcessor::GetInstance();

	bool isEmpty = currentTextBox->IsEmpty();

	if (label == "C"){
		processor->ClearCommands();
		currentTextBox->SetValue("");
		hitEquals = false;
	}
	else if (label == "=" && hitEquals == false && hitOperand == true && isEmpty == false) {
		hitOperand = false;
		processor->Equals(this);
		currentTextBox->SetValue(std::to_string(processor->GetTotal()));
		hitEquals = true;
	}
	else if (label == "+" && hitOperand == false && isEmpty == false) {
		hitOperand = true;
		processor->Add(this);
		currentTextBox->SetValue("");
	}
	else if (label == "-" && hitOperand == false && isEmpty == false) {
		hitOperand = true;
		processor->Subtract(this);
		currentTextBox->SetValue("");
	}
	else if (label == "*" && hitOperand == false && isEmpty == false) {
		hitOperand = true;
		processor->Multiply(this);
		currentTextBox->SetValue("");
	}
	else if (label == "/" && hitOperand == false && isEmpty == false) {
		hitOperand = true;
		processor->Divide(this);
		currentTextBox->SetValue("");
	}
	else if (label == "%" && hitOperand == false && isEmpty == false) {
		hitOperand = true;
		processor->Mod(this);
		currentTextBox->SetValue("");
	}
	else if (label == "BIN" && hitBinary == false && isEmpty == false) {
		processor->GetBinary(this);
		hitBinary = true;
	}
	else if (label == "HEX" && hitHexadecimal == false && isEmpty == false) {
		processor->GetHexadecimal(this);
		hitHexadecimal = true;
	}
	else if (label == "DEC" && hitDecimal == false && isEmpty == false) {
		processor->GetDecimal(this);
		hitDecimal = true;
	}
	else if (label == "+/-" && isEmpty == false) {
		processor->SwitchPosNeg(this);
	}
	else {
		if (hitEquals == true || hitBinary == true || hitHexadecimal == true || hitDecimal == true) {
			currentTextBox->SetValue("");
			hitEquals = false;
			hitBinary = false;
			hitHexadecimal = false;
			hitDecimal = false;
		}
		if (((hitOperand == true && label == "+" || label == "-" || label == "*" || label == "/" || label == "%") || (hitEquals == true && label == "=") || (hitOperand == false && hitEquals == false && label == "=") || (label == "BIN") || (label == "DEC") || (label == "HEX")) && isEmpty == true) {
			
		}
		else {
			currentTextBox->AppendText(label);
		}
	}
}

wxTextCtrl* CalculatorFrame::GetTextBox()
{
	return currentTextBox;
}

