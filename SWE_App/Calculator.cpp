#include "Calculator.h"
#include <cmath>
#include "ButtonFactory.h"



//Temp here for push and submit
wxBEGIN_EVENT_TABLE(Calculator, wxFrame)
EVT_BUTTON(ID_BUTTON_0, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_1, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_2, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_3, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_4, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_5, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_6, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_7, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_8, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_9, Calculator::OnButtonClicked)

EVT_BUTTON(ID_BUTTON_ADD, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_SUBTRACT, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_MULTIPLY, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_DIVIDE, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_MODULO, Calculator::OnButtonClicked)

EVT_BUTTON(ID_BUTTON_SIN, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_COS, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_TAN, Calculator::OnButtonClicked)

EVT_BUTTON(ID_BUTTON_EQUALS, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_CLEAR, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_BACKSPACE, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_DECIMAL, Calculator::OnButtonClicked)
EVT_BUTTON(ID_BUTTON_NEGATIVE, Calculator::OnButtonClicked)

wxEND_EVENT_TABLE()




Calculator::Calculator()
	:wxFrame(nullptr, wxID_ANY, "Calculator", wxDefaultPosition, wxSize(400, 500))
{
	SetMinSize(wxSize(400, 500));
	wxPanel* panel = new wxPanel(this);
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	display = new wxTextCtrl(panel, wxID_ANY, "0", wxDefaultPosition, wxSize(-1, 60), wxTE_RIGHT | wxTE_READONLY);
	wxFont displayFont = display->GetFont();
	displayFont.SetPointSize(20);
	display->SetFont(displayFont);
	mainSizer->Add(display, 0, wxEXPAND | wxALL, 10);

	wxGridSizer* buttonSizer = new wxGridSizer(5, 5, 5, 5);



	auto addButtonToGrid = [buttonSizer](wxButton* button)
		{
			buttonSizer->Add(button, 0, wxEXPAND);
		};

	addButtonToGrid(ButtonFactory::CreateSinButton(panel));
	addButtonToGrid(ButtonFactory::CreateCosButton(panel));
	addButtonToGrid(ButtonFactory::CreateTanButton(panel));
	addButtonToGrid(ButtonFactory::CreateClearButton(panel));
	addButtonToGrid(ButtonFactory::CreateBackspaceButton(panel));

	addButtonToGrid(ButtonFactory::CreateSevenButton(panel));
	addButtonToGrid(ButtonFactory::CreateEightButton(panel));
	addButtonToGrid(ButtonFactory::CreateNineButton(panel));
	addButtonToGrid(ButtonFactory::CreateDivideButton(panel));
	addButtonToGrid(ButtonFactory::CreateModuloButton(panel));

	addButtonToGrid(ButtonFactory::CreateFourButton(panel));
	addButtonToGrid(ButtonFactory::CreateFiveButton(panel));
	addButtonToGrid(ButtonFactory::CreateSixButton(panel));
	addButtonToGrid(ButtonFactory::CreateMultiplyButton(panel));
	addButtonToGrid(ButtonFactory::CreateSubtractButton(panel));

	addButtonToGrid(ButtonFactory::CreateOneButton(panel));
	addButtonToGrid(ButtonFactory::CreateTwoButton(panel));
	addButtonToGrid(ButtonFactory::CreateThreeButton(panel));
	addButtonToGrid(ButtonFactory::CreateAddButton(panel));
	addButtonToGrid(ButtonFactory::CreateEqualsButton(panel));

	addButtonToGrid(ButtonFactory::CreateNegativeButton(panel));
	addButtonToGrid(ButtonFactory::CreateZeroButton(panel));
	addButtonToGrid(ButtonFactory::CreateDecimalButton(panel));





/*	auto addButton = [panel, buttonSizer](int id, const wxString& label)
		{
			wxButton* button = new wxButton(panel, id, label);

			buttonSizer->Add(button, 0, wxEXPAND);
		};

	addButton(ID_BUTTON_SIN, "SIN");
	addButton(ID_BUTTON_COS, "COS");
	addButton(ID_BUTTON_TAN, "TAN");
	addButton(ID_BUTTON_CLEAR, "C");
	addButton(ID_BUTTON_BACKSPACE, "DEL");

	addButton(ID_BUTTON_7, "7");
	addButton(ID_BUTTON_8, "8");
	addButton(ID_BUTTON_9, "9");
	addButton(ID_BUTTON_DIVIDE, "/");
	addButton(ID_BUTTON_MODULO, "%");

	addButton(ID_BUTTON_4, "4");
	addButton(ID_BUTTON_5, "5");
	addButton(ID_BUTTON_6, "6");
	addButton(ID_BUTTON_MULTIPLY, "*");
	addButton(ID_BUTTON_SUBTRACT, "-");

	addButton(ID_BUTTON_1, "1");
	addButton(ID_BUTTON_2, "2");
	addButton(ID_BUTTON_3, "3");
	addButton(ID_BUTTON_ADD, "+");
	addButton(ID_BUTTON_EQUALS, "=");

	addButton(ID_BUTTON_NEGATIVE, "+/-");
	addButton(ID_BUTTON_0, "0");
	addButton(ID_BUTTON_DECIMAL, "."); //temp outcomment for testin
*/
	buttonSizer->AddSpacer(0);
	buttonSizer->AddSpacer(0);
	mainSizer->Add(buttonSizer, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);
	panel->SetSizer(mainSizer);




	Centre();
}

void Calculator::OnButtonClicked(wxCommandEvent& event)
{
	int buttonId = event.GetId();
	if (buttonId == ID_BUTTON_CLEAR)
	{
		display->Clear();
		return;
	}
	if (buttonId == ID_BUTTON_BACKSPACE)
	{
		wxString currentText = display->GetValue();

		if (!currentText.IsEmpty())
		{
			currentText.RemoveLast();
			display->SetValue(currentText);
		}
		return;

	}

	if (buttonId == ID_BUTTON_EQUALS)
	{
		double result = 0.0;
		if (EvaluateExpression(display->GetValue(), result) && std::isfinite(result))
		{
			display->Clear();
			display-> SetValue(wxString::Format("%.12g", result));
		}
		else
		{
			display->Clear();
			display->SetValue("Error");
		}
		return;
	}


	wxButton* clickedButton = static_cast<wxButton*>(event.GetEventObject());

	wxString textToAdd = clickedButton->GetLabel();
	if (buttonId == ID_BUTTON_NEGATIVE)
	{
		textToAdd = "-";
	}
	if (buttonId == ID_BUTTON_SIN)
	{
		textToAdd = "sin ";
	}
	if (buttonId == ID_BUTTON_COS)
	{
		textToAdd = "cos ";
	}
	if (buttonId == ID_BUTTON_TAN)
	{
		textToAdd = "tan ";
	}

	if (display->GetValue() == "0")
	{
		display->Clear();
	}
	display->AppendText(textToAdd);


}

namespace
{
	bool IsOperator(wxChar character)
	{
		return character == '+' || character == '-' || character == '*' || character == '/' || character == '%';
	}
	wxString TrimText(wxString text)
	{
		text.Trim(true);
		text.Trim(false);

		return text;
	}
	bool ConvertToDouble(wxString text, double& value)
	{
		text = TrimText(text);
		if (text.IsEmpty())
		{
			return false;
		}

		if (text.StartsWith("+")) {	return false; }
		return text.ToDouble(&value);
	}

	bool FindBinaryOperator(const wxString& expression, size_t& operatorIndex)
	{
		for (size_t i = 1; i < expression.length(); i++)
		{
			wxChar currentCharacter = expression[i];
			if (!IsOperator(currentCharacter))
			{
				continue;
			}

			if (currentCharacter == '-' && IsOperator(expression[i - 1]))
			{
				continue;
			}
			operatorIndex = i;
			return true;

		}
		return false;
	}

}

bool Calculator::EvaluateExpression(const wxString& expression, double& result)
{
	wxString text = TrimText(expression);

	if (text.IsEmpty()) { return false; }

	if (text.StartsWith("sin"))
	{
		double value = 0.0;

		if (!ConvertToDouble(text.Mid(3), value))
		{
			return false;
		}
		result = std::sin(value);
		return true;
	}

	if (text.StartsWith("cos"))
	{
		double value = 0.0;

		if (!ConvertToDouble(text.Mid(3), value))
		{
			return false;
		}
		result = std::cos(value);
		return true;
	}

	if (text.StartsWith("tan"))
	{
		double value = 0.0;

		if (!ConvertToDouble(text.Mid(3), value))
		{
			return false;
		}
		result = std::tan(value);
		return true;
	}

	size_t operatorIndex = 0; 
	if (!FindBinaryOperator(text, operatorIndex)) { return ConvertToDouble(text, result);	 }

	double leftNumber = 0.0;
	double rightNumber = 0.0;

	wxString leftText = text.Left(operatorIndex);
	wxString rightText = text.Mid(operatorIndex + 1);

	if (!ConvertToDouble(leftText, leftNumber)) { return false;	}
	if (!ConvertToDouble(rightText, rightNumber)) { return false; }

	wxChar operation = text[operatorIndex];
	switch (operation)
	{
	case '+':
		result = leftNumber + rightNumber;
		return true;

	case '-':
		result = leftNumber - rightNumber;
		return true;

	case '*':
		result = leftNumber * rightNumber;
		return true;

	case '/':
		if (rightNumber == 0) { return false; }
		result = leftNumber / rightNumber;
		return true;

	case '%':
		if (rightNumber == 0) { return false;  }
		result = std::fmod(leftNumber, rightNumber);
		return true;


	default: return false;
	}

}

