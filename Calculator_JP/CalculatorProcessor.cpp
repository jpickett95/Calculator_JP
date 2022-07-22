#define _CRT_SECURE_NO_WARNINGS

#include "CalculatorProcessor.h"

CalculatorProcessor* CalculatorProcessor::processor = nullptr;

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