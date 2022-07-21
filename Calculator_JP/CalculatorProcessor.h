#pragma once

#include <string> 
#include <vector> 
#include "CalculatorFrame.h" 
#include "IBaseCommand.h"
#include "AddCommand.h"

class IBaseCommand;

class CalculatorProcessor : public CalculatorFrame
{
private:
	static CalculatorProcessor* processor; 
	int baseNumber;
	int secondNumber;
	std::vector<IBaseCommand*> commands;

	CalculatorProcessor() {} // Constructor
public:
	static CalculatorProcessor* GetInstance();

	void SetBaseNumber() {
		std::string text = GetTextBox()->GetValue().ToStdString();
		baseNumber = std::stoi(text);
	}

	void SetSecondNumber() {
		std::string text = GetTextBox()->GetValue().ToStdString();
		secondNumber = std::stoi(text);
	}

	int GetBaseNumber() {
		return baseNumber;
	}

	int GetSecondNumber() {
		return secondNumber;
	}
	
	CalculatorProcessor(CalculatorProcessor& _other) = delete; // Copy Constructor
	void operator=(const CalculatorProcessor& _other) = delete; // Assignment Operator

	std::string GetDecimal() {
		return std::to_string(baseNumber);
	}

	std::string GetHexadecimal() {
		std::string hexString = "";
		int number = baseNumber;
		while (number > 0) {
			int mod = number % 16;
			if (mod < 10)
				hexString = std::to_string(mod) + hexString;
			else {
				switch (mod) {
				case 10:
					hexString = "A" + hexString;
					break;
				case 11:
					hexString = "B" + hexString;
					break;
				case 12:
					hexString = "C" + hexString;
					break;
				case 13:
					hexString = "D" + hexString;
					break;
				case 14:
					hexString = "E" + hexString;
					break;
				case 15:
					hexString = "F" + hexString;
					break;
				}
			}
			number = number / 16;
		}
		hexString = "0x" + hexString;
		return hexString;
	}

	std::string GetBinary() {
		std::string binaryString = "";
		int number = baseNumber;
		for (int i = 0; i < 16; ++i) {
			// Check if number is even/odd
			if (number % 2 == 0)
				binaryString = "0" + binaryString;
			else
				binaryString = "1" + binaryString;

			// Change number for processing
			number = number / 2;
		}
		return binaryString;
	}

	void Add();

	float Subtract(float _number) {
		return baseNumber - _number;
	}

	float Multiply(float _number) {
		return baseNumber * _number;
	}

	float Divide(float _number) {
		return baseNumber / _number;
	}

	void Equals() {
		SetSecondNumber();
		for (int i = 0; i < commands.size(); ++i) {
			commands[i]->Execute();
		}
	}

	void ClearCommands() {
		commands.clear();
	}

	bool IsCommandsEmpty() {
		return commands.empty();
	}
};

