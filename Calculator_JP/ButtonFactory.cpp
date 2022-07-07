#include "ButtonFactory.h"
#include "wx/wx.h"

wxButton* ButtonFactory::CreateNumButton(int _number, wxWindow* _parent ) const {
	std::string title;
	title = std::to_string(_number);
	return new wxButton(_parent, 100+_number, title);
}