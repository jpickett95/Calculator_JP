#define _CRT_SECURE_NO_WARNINGS

#include "CalculatorProcessor.h"

CalculatorProcessor* CalculatorProcessor::processor = nullptr;

CalculatorProcessor::~CalculatorProcessor()
{
	for (int i = 0; i < commands.size(); ++i) {
		delete commands[i];
	}
}

CalculatorProcessor* CalculatorProcessor::GetInstance() {
	if (processor == nullptr)
		processor = new CalculatorProcessor();
	return processor;
}

void CalculatorProcessor::Add(CalculatorFrame* _frame) {
	std::string text = _frame->GetTextBox()->GetValue().ToStdString();
	baseNumber = std::stoi(text);
	AddCommand* addCommand = new AddCommand();
	commands.push_back(addCommand);
}

void CalculatorProcessor::Subtract(CalculatorFrame* _frame) {
	std::string text = _frame->GetTextBox()->GetValue().ToStdString();
	baseNumber = std::stoi(text);
	SubtractCommand* subtractCommand = new SubtractCommand();
	commands.push_back(subtractCommand);
}

void CalculatorProcessor::Multiply(CalculatorFrame* _frame) {
	std::string text = _frame->GetTextBox()->GetValue().ToStdString();
	baseNumber = std::stoi(text);
	MultiplyCommand* multiplyCommand = new MultiplyCommand();
	commands.push_back(multiplyCommand);
}

void CalculatorProcessor::Divide(CalculatorFrame* _frame) {
	std::string text = _frame->GetTextBox()->GetValue().ToStdString();
	baseNumber = std::stoi(text);
	DivideCommand* divideCommand = new DivideCommand();
	commands.push_back(divideCommand);
}

void CalculatorProcessor::Mod(CalculatorFrame* _frame) {
	std::string text = _frame->GetTextBox()->GetValue().ToStdString();
	baseNumber = std::stoi(text);
	ModCommand* modCommand = new ModCommand();
	commands.push_back(modCommand);
}

void CalculatorProcessor::Equals(CalculatorFrame* _frame) {
		std::string text = _frame->GetTextBox()->GetValue().ToStdString();
		secondNumber = std::stoi(text);
	if (commands.empty() != true) {
		for (int i = 0; i < commands.size(); ++i) {
			commands[i]->Execute();
		}
	}
}

void CalculatorProcessor::GetBinary(CalculatorFrame* _frame) {
	std::string text = _frame->GetTextBox()->GetValue().ToStdString();
	baseNumber = std::stoi(text);
	std::string binaryString = "";
	int number = baseNumber;
	for (int i = 0; i < 16; ++i) {
		// Check if number is even/odd
		if (number % 2 == 0)
			binaryString = "0" + binaryString;
		else
			binaryString = "1" + binaryString;

		// Change number for processing
		number = number / 2;
	}
	_frame->GetTextBox()->SetValue(binaryString);	
}

void CalculatorProcessor::GetHexadecimal(CalculatorFrame* _frame) {
	std::string hexString = "";
	std::string text = _frame->GetTextBox()->GetValue().ToStdString();
	baseNumber = std::stoi(text);
	int number = baseNumber;
	while (number > 0) {
		int mod = number % 16;
		if (mod < 10)
			hexString = std::to_string(mod) + hexString;
		else {
			switch (mod) {
			case 10:
				hexString = "A" + hexString;
				break;
			case 11:
				hexString = "B" + hexString;
				break;
			case 12:
				hexString = "C" + hexString;
				break;
			case 13:
				hexString = "D" + hexString;
				break;
			case 14:
				hexString = "E" + hexString;
				break;
			case 15:
				hexString = "F" + hexString;
				break;
			}
		}
		number = number / 16;
	}
	hexString = "0x" + hexString;
	_frame->GetTextBox()->SetValue(hexString);
}

void CalculatorProcessor::GetDecimal(CalculatorFrame* _frame) {
	_frame->GetTextBox()->SetValue(std::to_string(baseNumber));
}

void CalculatorProcessor::SwitchPosNeg(CalculatorFrame* _frame) {
	std::string text = _frame->GetTextBox()->GetValue().ToStdString();
	baseNumber = std::stoi(text);
	baseNumber = baseNumber * -1;
	_frame->GetTextBox()->SetValue(std::to_string(baseNumber));
}