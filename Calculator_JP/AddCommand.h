#pragma once

#include "IBaseCommand.h"
#include "CalculatorFrame.h"
#include "CalculatorProcessor.h"

class AddCommand : public IBaseCommand, public CalculatorFrame
{
private:
	int baseNumber;
	int secondNumber;
	int total;
public:
	void Add();

	void Execute();

	
	
};
