#pragma once
#include "wx/wx.h"
class ButtonFactory
{
public:
	wxButton* CreateNumButton(int _number, wxWindow* _parent) const;
	wxButton* CreateClearButton(wxWindow* _parent) const;
	wxButton* CreatePosNegButton(wxWindow* _parent) const;
	wxButton* CreateModButton(wxWindow* _parent) const;
	wxButton* CreateDivideButton(wxWindow* _parent) const;
	wxButton* CreateMultiplyButton(wxWindow* _parent) const;
	wxButton* CreateSubtractButton(wxWindow* _parent) const;
	wxButton* CreateAddButton(wxWindow* _parent) const;
	wxButton* CreateBinHexDecButton(wxWindow* _parent) const;
	wxButton* CreateDecimalPointButton(wxWindow* _parent) const;
	wxButton* CreateEqualsButton(wxWindow* _parent) const;

};

