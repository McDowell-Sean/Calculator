#include "ButtonFactory.h"
#include "Calculator.h"



wxButton* ButtonFactory::CreateButton(wxWindow* parent, int id, const wxString& label)
{
	return new wxButton(parent, id, label);
}

wxButton* ButtonFactory::CreateZeroButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_0, "0");
}

wxButton* ButtonFactory::CreateOneButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_1, "1");
}

wxButton* ButtonFactory::CreateTwoButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_2, "2");
}

wxButton* ButtonFactory::CreateThreeButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_3, "3");
}

wxButton* ButtonFactory::CreateFourButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_4, "4");
}

wxButton* ButtonFactory::CreateFiveButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_5, "5");
}

wxButton* ButtonFactory::CreateSixButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_6, "6");
}

wxButton* ButtonFactory::CreateSevenButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_7, "7");
}

wxButton* ButtonFactory::CreateEightButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_8, "8");
}

wxButton* ButtonFactory::CreateNineButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_9, "9");
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_ADD, "+");
}

wxButton* ButtonFactory::CreateSubtractButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_SUBTRACT, "-");
}

wxButton* ButtonFactory::CreateMultiplyButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_MULTIPLY, "*");
}

wxButton* ButtonFactory::CreateDivideButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_DIVIDE, "/");
}

wxButton* ButtonFactory::CreateModuloButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_MODULO, "%");
}

wxButton* ButtonFactory::CreateSinButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_SIN, "SIN");
}

wxButton* ButtonFactory::CreateCosButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_COS, "COS");
}

wxButton* ButtonFactory::CreateTanButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_TAN, "TAN");
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_EQUALS, "=");
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_CLEAR, "C");
}

wxButton* ButtonFactory::CreateBackspaceButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_BACKSPACE, "DEL");
}

wxButton* ButtonFactory::CreateDecimalButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_DECIMAL, ".");
}

wxButton* ButtonFactory::CreateNegativeButton(wxWindow* parent)
{
	return CreateButton(parent, ID_BUTTON_NEGATIVE, "+/-");
}



