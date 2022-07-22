#define _CRT_SECURE_NO_WARNINGS

#include "ModCommand.h"

void ModCommand::Mod()
{
	CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
	baseNumber = processor->GetBaseNumber();
	secondNumber = processor->GetSecondNumber();
	total = baseNumber % secondNumber;
	processor->SetTotal(total);
}

void ModCommand::Execute()
{
	Mod();
}
