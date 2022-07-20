#pragma once

#include <string> 
#include "CalculatorFrame.h" 

class CalculatorProcessor : public CalculatorFrame
{
private:
	static CalculatorProcessor* processor; 
	float baseNumber;
	CalculatorProcessor() {} // Constructor
public:
	static CalculatorProcessor* GetInstance() { 
		if (processor == nullptr)
			processor = new CalculatorProcessor();
		return processor;
	}

	void SetBaseNumber() {
		std::string text = (std::string)GetTextBox()->GetLineText(0);
		baseNumber = std::stof(text);
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

	float Add(float _number) {
		SetBaseNumber();
		return baseNumber + _number;
	}

	float Subtract(float _number) {
		return baseNumber - _number;
	}

	float Multiply(float _number) {
		return baseNumber * _number;
	}

	float Divide(float _number) {
		return baseNumber / _number;
	}
};

CalculatorProcessor* CalculatorProcessor::processor = nullptr;