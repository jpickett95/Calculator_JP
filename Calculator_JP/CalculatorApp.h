#pragma once
 
/*
* ***********Solution Properties***************
* C/C++ -> Additional Include Directories: C:\wxWidgets\include; C:\wxWidgets\include\msvc
* Linker -> Additional Library Directories: C:\wxWidgets\lib\vc_lib
* Linker -> System -> SubSystem: Windows(/SUBSYSTEM:WINDOWS)
*/

#include "wx/wx.h" // include wxWidgets
#include "CalculatorFrame.h"

class CalculatorApp : public wxApp // inherits from wxApp
{
private:
	CalculatorFrame* mainFrame = nullptr;
public:
	virtual bool OnInit(); // used for wxWidgets to run
};

