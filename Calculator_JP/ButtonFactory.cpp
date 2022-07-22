#include "ButtonFactory.h"
#include "wx/wx.h"
#include "CalculatorFrame.h"


wxButton* ButtonFactory::CreateNumButton(int _number, wxWindow* _parent ) const{
	std::string title; 
	title = std::to_string(_number);
	return new wxButton(_parent, wxID_ANY, title);	
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "C");
}

wxButton* ButtonFactory::CreatePosNegButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "+/-");
}

wxButton* ButtonFactory::CreateModButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "%");
}

wxButton* ButtonFactory::CreateDivideButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "/");
}

wxButton* ButtonFactory::CreateMultiplyButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "*");
}

wxButton* ButtonFactory::CreateSubtractButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "-");
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "+");
}

wxButton* ButtonFactory::CreateBinaryButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "BIN");
}

wxButton* ButtonFactory::CreateHexadecimalButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "HEX");
}

wxButton* ButtonFactory::CreateDecimalButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "DEC");
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* _parent) const {
	return new wxButton(_parent, wxID_ANY, "=");
}