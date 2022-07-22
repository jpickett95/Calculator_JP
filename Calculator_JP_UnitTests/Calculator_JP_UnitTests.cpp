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
		TEST_METHOD(ProcessorTest1) {

		}
		TEST_METHOD(ProcessorTest2) {

		}
		TEST_METHOD(ProcessorTest3) {

		}
		TEST_METHOD(ProcessorTest4) {

		}
		TEST_METHOD(ProcessorTest5) {

		}
		TEST_METHOD(ProcessorTest6) {

		}
		TEST_METHOD(ProcessorTest7) {

		}
		TEST_METHOD(ProcessorTest8) {

		}
		TEST_METHOD(ProcessorTest9) {

		}
		TEST_METHOD(ProcessorTest10) {

		}
	};
}
