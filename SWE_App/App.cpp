#include "App.h"
#include "Calculator.h"

wxIMPLEMENT_APP(App);
bool App::OnInit()
{
	Calculator* calculator = new Calculator();
	calculator->Show();
	return true;
}

