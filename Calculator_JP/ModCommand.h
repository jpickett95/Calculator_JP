#pragma once

#include "IBaseCommand.h"
#include "CalculatorProcessor.h"

class ModCommand : public IBaseCommand
{
private:
	int baseNumber;
	int secondNumber;
	int total;
public:
	void Mod();
	void Execute();
};

