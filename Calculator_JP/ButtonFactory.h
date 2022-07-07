#pragma once
#include "wx/wx.h"
class ButtonFactory
{
public:
	wxButton* CreateNumButton(int _number, wxWindow* _parent) const;
};

