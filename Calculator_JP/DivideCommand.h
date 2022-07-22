#pragma once

#include "IBaseCommand.h"
#include "CalculatorProcessor.h"

class DivideCommand : public IBaseCommand
{
private:
	int baseNumber;
	int secondNumber;
	int total;
public:
	void Divide();
	void Execute();
};

