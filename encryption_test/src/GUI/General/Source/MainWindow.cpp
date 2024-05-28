#include "../Headers/MainWindow.h"

MainWindow::MainWindow(wxString title):
	wxFrame(nullptr, -1, title)
{
	this->Center(wxBOTH);
	this->SetMinSize(wxSize(450,450));
	
	wxPanel* panel = new wxPanel(this);

	wxNotebook* typesPanel = new wxNotebook(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize);
		
	//AES
	auto aes_page = new AES_Tab(typesPanel);
	typesPanel->AddPage(aes_page, "AES");


	//SHA
	//auto sha_page = new

	//sizer & layout
	wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(typesPanel, 1, wxEXPAND | wxALL, 0);

	panel->SetSizer(sizer);
	sizer->Layout();
	
}

MainWindow::~MainWindow()
{
	this->Close();
}
