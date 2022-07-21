#define _CRT_SECURE_NO_WARNINGS

#include "CalculatorProcessor.h"

CalculatorProcessor* CalculatorProcessor::processor = nullptr;

CalculatorProcessor* CalculatorProcessor::GetInstance() {
	if (processor == nullptr)
		processor = new CalculatorProcessor();
	return processor;
}

void CalculatorProcessor::Add() {
	SetBaseNumber();
	AddCommand* addCommand = new AddCommand();
	commands.push_back(addCommand);
	
}