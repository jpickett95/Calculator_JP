#define _CRT_SECURE_NO_WARNINGS

#include "DivideCommand.h"

void DivideCommand::Divide()
{
	CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
	baseNumber = processor->GetBaseNumber();
	secondNumber = processor->GetSecondNumber();
	total = baseNumber / secondNumber;
	processor->SetTotal(total);
}

void DivideCommand::Execute()
{
	Divide();
}
