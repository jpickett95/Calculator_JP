#define _CRT_SECURE_NO_WARNINGS

#include "SubtractCommand.h"

void SubtractCommand::Subtract()
{
	CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
	baseNumber = processor->GetBaseNumber();
	secondNumber = processor->GetSecondNumber();
	total = baseNumber - secondNumber;
	processor->SetTotal(total);
}

void SubtractCommand::Execute()
{
	Subtract();
}
