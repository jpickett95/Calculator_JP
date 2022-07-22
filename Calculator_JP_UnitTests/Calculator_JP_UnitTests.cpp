#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator_JP/ButtonFactory.h"
#include "../Calculator_JP/CalculatorProcessor.h"
#include "../Calculator_JP/CalculatorFrame.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorJPUnitTests
{
	TEST_CLASS(CalculatorJPUnitTests)
	{
	public:
		CalculatorFrame* frame = new CalculatorFrame();
		ButtonFactory factory;
		CalculatorProcessor* processor = CalculatorProcessor::GetInstance();

		// ButtonFactory Tests
		TEST_METHOD(FactoryTest1_AddButton) {
			wxButton* button = factory.CreateAddButton(frame);
			bool isTrue;
			if (button->GetLabel() == "+")
				isTrue = true;
			else
				isTrue = false;
			Assert::AreEqual(isTrue, true);
		}
		TEST_METHOD(FactoryTest2_ClearButton) {
			wxButton* button = factory.CreateClearButton(frame);
			bool isTrue;
			if (button->GetLabel() == "C")
				isTrue = true;
			else
				isTrue = false;
			Assert::AreEqual(isTrue, true);
		}
		TEST_METHOD(FactoryTest3_PosNegButton) {
			wxButton* button = factory.CreatePosNegButton(frame);
			bool isTrue;
			if (button->GetLabel() == "+/-")
				isTrue = true;
			else
				isTrue = false;
			Assert::AreEqual(isTrue, true);
		}
		TEST_METHOD(FactoryTest4_ModButton) {
			wxButton* button = factory.CreateModButton(frame);
			bool isTrue;
			if (button->GetLabel() == "%")
				isTrue = true;
			else
				isTrue = false;
			Assert::AreEqual(isTrue, true);
		}
		TEST_METHOD(FactoryTest5_DivideButton) {
			wxButton* button = factory.CreateDivideButton(frame);
			bool isTrue;
			if (button->GetLabel() == "/")
				isTrue = true;
			else
				isTrue = false;
			Assert::AreEqual(isTrue, true);
		}
		TEST_METHOD(FactoryTest6_MultiplyButton) {
			wxButton* button = factory.CreateMultiplyButton(frame);
			bool isTrue;
			if (button->GetLabel() == "*")
				isTrue = true;
			else
				isTrue = false;
			Assert::AreEqual(isTrue, true);
		}
		TEST_METHOD(FactoryTest7_SubtractButton) {
			wxButton* button = factory.CreateSubtractButton(frame);
			bool isTrue;
			if (button->GetLabel() == "-")
				isTrue = true;
			else
				isTrue = false;
			Assert::AreEqual(isTrue, true);
		}
		TEST_METHOD(FactoryTest8_DecimalButton) {
			wxButton* button = factory.CreateDecimalButton(frame);
			bool isTrue;
			if (button->GetLabel() == "DEC")
				isTrue = true;
			else
				isTrue = false;
			Assert::AreEqual(isTrue, true);
		}
		TEST_METHOD(FactoryTest9_BinaryButton) {
			wxButton* button = factory.CreateBinaryButton(frame);
			bool isTrue;
			if (button->GetLabel() == "BIN")
				isTrue = true;
			else
				isTrue = false;
			Assert::AreEqual(isTrue, true);
		}
		TEST_METHOD(FactoryTest10_HexadecimalButton) {
			wxButton* button = factory.CreateHexadecimalButton(frame);
			bool isTrue;
			if (button->GetLabel() == "HEX")
				isTrue = true;
			else
				isTrue = false;
			Assert::AreEqual(isTrue, true);
		}
		 
		// CalculatorProcessor Tests
		TEST_METHOD(ProcessorTest1_Add) {
			frame->GetTextBox()->SetValue("100");
			processor->Add(frame);
			frame->GetTextBox()->SetValue("200");
			processor->Equals(frame);
			Assert::AreEqual(processor->GetTotal(), 300);
		}
		TEST_METHOD(ProcessorTest2_Subtract) {
			frame->GetTextBox()->SetValue("400");
			processor->Subtract(frame);
			frame->GetTextBox()->SetValue("200");
			processor->Equals(frame);
			Assert::AreEqual(processor->GetTotal(), 200);
		}
		TEST_METHOD(ProcessorTest3_GetBinary1) {
			frame->GetTextBox()->SetValue("100");
			processor->GetBinary(frame);
			Assert::AreEqual(frame->GetTextBox()->GetValue(), "0000000001100100");
		}
		TEST_METHOD(ProcessorTest4_GetBinary2) {
			frame->GetTextBox()->SetValue("465");
			processor->GetBinary(frame);
			Assert::AreEqual(frame->GetTextBox()->GetValue(), "0000000111010001");
		}
		TEST_METHOD(ProcessorTest5_GetHexadecimal1) {
			frame->GetTextBox()->SetValue("100");
			processor->GetHexadecimal(frame);
			Assert::AreEqual(frame->GetTextBox()->GetValue(), "0x64");
		}
		TEST_METHOD(ProcessorTest6_GetHexadecimal2) {
			frame->GetTextBox()->SetValue("465");
			processor->GetHexadecimal(frame);
			Assert::AreEqual(frame->GetTextBox()->GetValue(), "0x1D1");
		}
		TEST_METHOD(ProcessorTest7_Multiply) {
			frame->GetTextBox()->SetValue("400");
			processor->Multiply(frame);
			frame->GetTextBox()->SetValue("200");
			processor->Equals(frame);
			Assert::AreEqual(processor->GetTotal(), 80000);
		}
		TEST_METHOD(ProcessorTest8_Divide) {
			frame->GetTextBox()->SetValue("400");
			processor->Divide(frame);
			frame->GetTextBox()->SetValue("200");
			processor->Equals(frame);
			Assert::AreEqual(processor->GetTotal(), 2);
		}
		TEST_METHOD(ProcessorTest9_Mod) {
			frame->GetTextBox()->SetValue("400");
			processor->Mod(frame);
			frame->GetTextBox()->SetValue("200");
			processor->Equals(frame);
			Assert::AreEqual(processor->GetTotal(), 0);
		}
		TEST_METHOD(ProcessorTest10_SwitchPosNeg) {
			frame->GetTextBox()->SetValue("100");
			processor->SwitchPosNeg(frame);
			Assert::AreEqual(frame->GetTextBox()->GetValue(), "-100");
		}
	};
}
