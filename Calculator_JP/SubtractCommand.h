#pragma once

#include "IBaseCommand.h"
#include "CalculatorProcessor.h"

class SubtractCommand : public IBaseCommand
{
private:
	int baseNumber;
	int secondNumber;
	int total;
public:
	void Subtract();
	void Execute();
};

