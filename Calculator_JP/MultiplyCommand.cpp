#define _CRT_SECURE_NO_WARNINGS

#include "MultiplyCommand.h"

void MultiplyCommand::Multiply()
{
	CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
	baseNumber = processor->GetBaseNumber();
	secondNumber = processor->GetSecondNumber();
	total = baseNumber * secondNumber;
	processor->SetTotal(total);
}

void MultiplyCommand::Execute()
{
	Multiply();
}
