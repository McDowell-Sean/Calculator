#include "Calculator.h"
// Temp here for merge
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

	auto addButton = [panel, buttonSizer](int id, const wxString& label)
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
	addButton(ID_BUTTON_DECIMAL, ".");

	buttonSizer->AddSpacer(0);
	buttonSizer->AddSpacer(0);
	mainSizer->Add(buttonSizer, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);
	panel->SetSizer(mainSizer);




	Centre();
}