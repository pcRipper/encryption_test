#pragma once

#include <wx/wx.h>


class SignedTextCtrl : public wxPanel {
public:
	SignedTextCtrl(wxWindow* parent, wxWindowID winid, long textCtrlStyle = 0L);

	~SignedTextCtrl() = default;
public:
	wxSizer* sizer;
	wxTextCtrl* textBox;
	wxStaticText* sign;
};