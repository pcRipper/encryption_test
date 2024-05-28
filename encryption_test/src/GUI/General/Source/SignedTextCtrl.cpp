#include "../Headers/SignedTextCtrl.h"

SignedTextCtrl::SignedTextCtrl(wxWindow* parent, wxWindowID winid, long textCtrlStyle)
	:wxPanel(parent, winid)
{
	this->sign = new wxStaticText(this, wxID_ANY, "Label");
	this->textBox = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, textCtrlStyle);

	this->sizer = new wxBoxSizer(wxVERTICAL);

	this->sizer->Add(sign, 0, wxBOTTOM | wxEXPAND, 2);
	this->sizer->Add(textBox, 1, wxALL | wxEXPAND, 0);

	this->sizer->Layout();
	this->SetSizer(this->sizer);
}
