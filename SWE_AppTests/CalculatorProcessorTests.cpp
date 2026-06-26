#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/CalculatorProcessor.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SWEAppTests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:

		TEST_METHOD(AdditionWorks)
		{
			double result = 0.0;

			bool success = CalculatorProcessor::GetInstance()->Calculate("2+2", result);

			Assert::IsTrue(success);
			Assert::AreEqual(4.0, result, 0.000001);
		}

		TEST_METHOD(SubtractionWorks)
		{
			double result = 0.0;

			bool success = CalculatorProcessor::GetInstance()->Calculate("10-3", result);

			Assert::IsTrue(success);
			Assert::AreEqual(7.0, result, 0.000001);
		}

		TEST_METHOD(MultiplicationWorks)
		{
			double result = 0.0;

			bool success = CalculatorProcessor::GetInstance()->Calculate("6*7", result);

			Assert::IsTrue(success);
			Assert::AreEqual(42.0, result, 0.000001);
		}

		TEST_METHOD(DivisionWorks)
		{
			double result = 0.0;

			bool success = CalculatorProcessor::GetInstance()->Calculate("8/2", result);

			Assert::IsTrue(success);
			Assert::AreEqual(4.0, result, 0.000001);
		}

		TEST_METHOD(ModuloWorks)
		{
			double result = 0.0;

			bool success = CalculatorProcessor::GetInstance()->Calculate("10%3", result);

			Assert::IsTrue(success);
			Assert::AreEqual(1.0, result, 0.000001);
		}

		TEST_METHOD(OrderOfOperationsWorks)
		{
			double result = 0.0;

			bool success = CalculatorProcessor::GetInstance()->Calculate("2+2*3", result);

			Assert::IsTrue(success);
			Assert::AreEqual(8.0, result, 0.000001);
		}

		TEST_METHOD(UnaryNegativeWorks)
		{
			double result = 0.0;

			bool success = CalculatorProcessor::GetInstance()->Calculate("1--4", result);

			Assert::IsTrue(success);
			Assert::AreEqual(5.0, result, 0.000001);
		}

		TEST_METHOD(SinWorks)
		{
			double result = 0.0;

			bool success = CalculatorProcessor::GetInstance()->Calculate("sin5", result);

			Assert::IsTrue(success);
			Assert::AreEqual(-0.958924274663, result, 0.000001);
		}

		TEST_METHOD(ComplexExpressionWorks)
		{
			double result = 0.0;

			bool success = CalculatorProcessor::GetInstance()->Calculate("2+2.5/sin5", result);

			Assert::IsTrue(success);
			Assert::AreEqual(-0.60708803192, result, 0.000001);
		}



		TEST_METHOD(DivideByZeroFails)
		{
			double result = 0.0;

			bool success = CalculatorProcessor::GetInstance()->Calculate("5/0", result);

			Assert::IsFalse(success);
		}



	};


}



