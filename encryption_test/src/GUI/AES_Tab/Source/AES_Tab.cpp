#include "../Headers/AES_Tab.h"

AES_Tab::AES_Tab(wxWindow* parent) : 
	wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	wxNotebook* notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);

	notebook->AddPage(new AES_Tab_Encrypt(notebook), "Encrypt");
	notebook->AddPage(new AES_Tab_Decrypt(notebook), "Decrypt");

	//sizer & layout
	wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(notebook, 1, wxEXPAND | wxTOP, 2);

	this->SetSizer(sizer);
	sizer->Layout();
}
