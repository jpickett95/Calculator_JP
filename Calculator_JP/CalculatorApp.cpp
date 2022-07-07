#include "CalculatorApp.h"

wxIMPLEMENT_APP(CalculatorApp); // Command that sets up the entry point for the app; "int main{}"

bool CalculatorApp::OnInit()
{
	mainFrame = new CalculatorFrame();
	mainFrame->Show();
	return true;
}
