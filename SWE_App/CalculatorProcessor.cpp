#include "CalculatorProcessor.h"
#include <cmath>






CalculatorProcessor::CalculatorProcessor()
{
	position = 0;
}



CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	static CalculatorProcessor instance;

	return &instance;
}

bool CalculatorProcessor::Calculate(const wxString& expression, double& result)
{
	input = expression;
	position = 0;

	SkipSpaces();

	if (IsAtEnd())
	{
		return false;
	}

	if (!ParseExpression(result))
	{
		return false;
	}

	SkipSpaces();

	return IsAtEnd();
}


void CalculatorProcessor::SkipSpaces()
{
	while (!IsAtEnd() && input[position] == ' ')
	{
		position++;
	}
}




bool CalculatorProcessor::IsAtEnd()
{
	return position >= input.length();
}


bool CalculatorProcessor::MatchFunction(const wxString& functionName)
{
	SkipSpaces();

	if (position + functionName.length() > input.length())
	{
		return false;
	}

	wxString possibleFunction = input.Mid(position, functionName.length());
	possibleFunction.MakeLower();

	wxString targetFunction = functionName;
	targetFunction.MakeLower();

	if (possibleFunction == targetFunction)
	{
		position += functionName.length();
		return true;
	}

	return false;
}

bool CalculatorProcessor::ParseExpression(double& result)
{
	if (!ParseTerm(result))
	{
		return false;
	}

	while (true)
	{
		SkipSpaces();

		if (IsAtEnd())
		{
			return true;
		}

		wxChar operation = input[position];

		if (operation != '+' && operation != '-')
		{
			return true;
		}

		position++;

		double rightValue = 0.0;

		if (!ParseTerm(rightValue))
		{
			return false;
		}

		switch (operation)
		{
		case '+':
			result = result + rightValue;
			break;

		case '-':
			result = result - rightValue;
			break;
		}
	}
}

bool CalculatorProcessor::ParseTerm(double& result)
{
	if (!ParseFactor(result))
	{
		return false;
	}

	while (true)
	{
		SkipSpaces();

		if (IsAtEnd())
		{
			return true;
		}

		wxChar operation = input[position];

		if (operation != '*' && operation != '/' && operation != '%')
		{
			return true;
		}

		position++;

		double rightValue = 0.0;

		if (!ParseFactor(rightValue))
		{
			return false;
		}

		switch (operation)
		{
		case '*':
			result = result * rightValue;
			break;

		case '/':
			if (rightValue == 0)
			{
				return false;
			}

			result = result / rightValue;
			break;

		case '%':
			if (rightValue == 0)
			{
				return false;
			}

			result = std::fmod(result, rightValue);
			break;
		}
	}
}



bool CalculatorProcessor::ParseFactor(double& result)
{
	SkipSpaces();

	if (IsAtEnd())
	{
		return false;
	}

	if (input[position] == '-')
	{
		position++;

		double value = 0.0;

		if (!ParseFactor(value))
		{
			return false;
		}

		result = -value;
		return true;
	}




	if (MatchFunction("sin"))
	{
		double value = 0.0;

		if (!ParseFactor(value))
		{
			return false;
		}

		result = std::sin(value);
		return true;
	}

	if (MatchFunction("cos"))
	{
		double value = 0.0;

		if (!ParseFactor(value))
		{
			return false;
		}

		result = std::cos(value);
		return true;
	}


	if (MatchFunction("tan"))
	{
		double value = 0.0;

		if (!ParseFactor(value))
		{
			return false;
		}

		result = std::tan(value);
		return true;
	}



	return ParseNumber(result);
}




bool CalculatorProcessor::ParseNumber(double& result)
{
	SkipSpaces();

	size_t startPosition = position;

	bool foundDigit = false;
	bool foundDecimal = false;

	while (!IsAtEnd())
	{
		wxChar currentCharacter = input[position];

		if (currentCharacter >= '0' && currentCharacter <= '9')
		{
			foundDigit = true;
			position++;
		}
		else if (currentCharacter == '.' && !foundDecimal)
		{
			foundDecimal = true;
			position++;
		}
		else
		{
			break;
		}

	}

	if (!foundDigit)
	{
		return false;
	}



	wxString numberText = input.Mid(startPosition, position - startPosition);

	return numberText.ToDouble(&result);
}



