#pragma once

#include <wx/wx.h>

enum CalculatorButtonId	
{
	ID_BUTTON_0 = wxID_HIGHEST + 1,
	ID_BUTTON_1,
	ID_BUTTON_2,
	ID_BUTTON_3,
	ID_BUTTON_4,
	ID_BUTTON_5,
	ID_BUTTON_6,
	ID_BUTTON_7,
	ID_BUTTON_8,
	ID_BUTTON_9,

	ID_BUTTON_ADD,
	ID_BUTTON_SUBTRACT,
	ID_BUTTON_MULTIPLY,
	ID_BUTTON_DIVIDE,
	ID_BUTTON_MODULO,

	ID_BUTTON_SIN,
	ID_BUTTON_COS,
	ID_BUTTON_TAN,

	ID_BUTTON_EQUALS,
	ID_BUTTON_CLEAR,
	ID_BUTTON_BACKSPACE,
	ID_BUTTON_DECIMAL,
	ID_BUTTON_NEGATIVE
};




class Calculator : public wxFrame
{
public:
	Calculator();


private:
	wxTextCtrl* display;
	void OnButtonClicked(wxCommandEvent& event);
	
	wxDECLARE_EVENT_TABLE();
};
