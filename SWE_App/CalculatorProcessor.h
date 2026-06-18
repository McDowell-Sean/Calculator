#pragma once



#include <wx/wx.h>


class CalculatorProcessor
{
public:
	static CalculatorProcessor* GetInstance();

	bool Calculate(const wxString& expression, double& result);

private:
	CalculatorProcessor();

	CalculatorProcessor(const CalculatorProcessor&) = delete;
	CalculatorProcessor& operator=(const CalculatorProcessor&) = delete;

	wxString input;
	size_t position;

	void SkipSpaces();

	bool ParseExpression(double& result);
	bool ParseTerm(double& result);
	bool ParseFactor(double& result);
	bool ParseNumber(double& result);

	bool MatchFunction(const wxString& functionName);
	bool IsAtEnd();
};



