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

void CalculatorProcessor::Equals(CalculatorFrame* _frame) {
		std::string text = _frame->GetTextBox()->GetValue().ToStdString();
		secondNumber = std::stoi(text);
	if (commands.empty() != true) {
		for (int i = 0; i < commands.size(); ++i) {
			commands[i]->Execute();
		}
	}
}