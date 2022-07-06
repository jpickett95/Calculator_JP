#pragma once

#include "wx/wx.h" // include wxWidgets
#include "CalculatorFrame.h"

class CalculatorApp : public wxApp // inherits from wxApp
{
private:
	CalculatorFrame* mainFrame = nullptr;
public:
	virtual bool OnInit(); // used for wxWidgets to run
};

