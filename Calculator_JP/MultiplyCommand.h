#pragma once

#include "IBaseCommand.h"
#include "CalculatorProcessor.h"

class MultiplyCommand : public IBaseCommand
{
private:
	int baseNumber;
	int secondNumber;
	int total;
public:
	void Multiply();
	void Execute();
};

