#pragma once

#include "IBaseCommand.h"
#include "CalculatorProcessor.h"

class AddCommand : public IBaseCommand
{
private:
	int baseNumber;
	int secondNumber;
	int total;
public:
	void Add(); 
	void Execute();
};

