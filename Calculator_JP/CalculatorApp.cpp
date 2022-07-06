#include "CalculatorApp.h"

bool CalculatorApp::OnInit()
{
	mainFrame = new CalculatorFrame();
	mainFrame->Show();
	return false;
}
