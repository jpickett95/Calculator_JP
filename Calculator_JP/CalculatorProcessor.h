#pragma once

#include <string> 
#include <vector> 
#include "CalculatorFrame.h" 
#include "IBaseCommand.h"
#include "AddCommand.h"
#include "SubtractCommand.h"
#include "MultiplyCommand.h"
#include "DivideCommand.h"
#include "ModCommand.h"

class IBaseCommand;
class CalculatorFrame;
class CalculatorProcessor
{
private:
	static CalculatorProcessor* processor; 
	int baseNumber;
	int secondNumber;
	int total;
	std::vector<IBaseCommand*> commands;

	CalculatorProcessor() {} // Constructor
public:
	static CalculatorProcessor* GetInstance();

	//void SetBaseNumber() {
	//	std::string text = GetTextBox()->GetValue().ToStdString();
	//	baseNumber = std::stoi(text);
	//}

	//void SetSecondNumber() {
	//	std::string text = GetTextBox()->GetValue().ToStdString();
	//	secondNumber = std::stoi(text);
	//}

	int GetBaseNumber() {
		return baseNumber;
	}

	int GetSecondNumber() {
		return secondNumber;
	}

	int GetTotal() {
		return total;
	}

	void SetTotal(int _number) {
		total = _number;
	}
	
	CalculatorProcessor(CalculatorProcessor& _other) = delete; // Copy Constructor
	void operator=(const CalculatorProcessor& _other) = delete; // Assignment Operator

	void GetDecimal(CalculatorFrame* _frame);

	void GetHexadecimal(CalculatorFrame* _frame);

	void GetBinary(CalculatorFrame* _frame);

	void Add(CalculatorFrame* _frame);

	void Subtract(CalculatorFrame* _frame);

	void Multiply(CalculatorFrame* _frame);

	void Divide(CalculatorFrame* _frame);

	void Equals(CalculatorFrame* _frame);

	void Mod(CalculatorFrame* _frame);

	void SwitchPosNeg(CalculatorFrame* _frame);

	void ClearCommands() {
		if (commands.empty() != true) {
			commands.clear();
		}
	}
};

