#define _CRT_SECURE_NO_WARNINGS

# include "AddCommand.h"

void AddCommand::Add() {
	CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
	baseNumber = processor->GetBaseNumber();
	secondNumber = processor->GetSecondNumber();
	total = baseNumber + secondNumber;
	processor->SetTotal(total);
}

void AddCommand::Execute() {
	Add();
}