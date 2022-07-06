#pragma once

#include "wx/wx.h" // include wxWidgets

class CalculatorApp : public wxApp // inherits from wxApp
{
public:
	virtual bool OnInit(); // used for wxWidgets to run
};

