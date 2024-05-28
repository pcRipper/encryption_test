#include "../Headers/ControlPanel_Template.h"

ControlPanel_Template::ControlPanel_Template(wxWindow* parent, std::list<std::string> const* menuOptions):
	wxPanel(parent)
{
	//Left side
	this->leftPanel = new wxPanel(this, wxID_ANY);
	{
		//plain text box
		this->inputText = new SignedTextCtrl(leftPanel, wxID_ANY, wxTE_MULTILINE);
		{
			this->inputText->textBox->SetHint("Input your text");
			this->inputText->sign->SetLabel("Input text");
			this->inputText->sign->SetFont(GUI::Config::Fonts::RobotoFont<12, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD>);
		}

		//key box
		this->keyText = new SignedTextCtrl(leftPanel, wxID_ANY); 
		{
			this->keyText->textBox->SetHint("Input your key here");
			this->keyText->sign->SetLabel("Cipher password");
			this->keyText->sign->SetFont(GUI::Config::Fonts::RobotoFont<12, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD>);
			this->keyText->SetMaxSize(wxSize(-1, 50));
		}

		//button
		this->actionButton = new wxButton(leftPanel, wxID_ANY, "Action");
		this->actionButton->SetMaxSize(wxSize(125, 25));
		this->actionButton->SetFont(GUI::Config::Fonts::RobotoFont<12, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL>);
	}
	//Right side
	this->rightPanel = new wxPanel(this, wxID_ANY);
	{
		//result text
		this->outputText = new SignedTextCtrl(rightPanel, wxID_ANY, wxTE_MULTILINE | wxTE_READONLY); 
		{
			this->outputText->sign->SetLabel("Output text");
			this->outputText->sign->SetFont(GUI::Config::Fonts::RobotoFont<12, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD>);
		}

		//choice
		this->options = std::vector<wxString>(menuOptions->begin(), menuOptions->end());
		this->types_output = new wxChoice(rightPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, int(this->options.size()), &this->options[0]);
		this->types_output->SetMaxSize(wxSize(100, 25));
		this->types_output->SetLabelText("Output Type");
		this->types_output->SetFont(GUI::Config::Fonts::RobotoFont<11, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM>);
	}

	//sizers & layout
	wxSizer* horizontal = new wxBoxSizer(wxHORIZONTAL);
	{
		wxSizer* verticalLeft = new wxBoxSizer(wxVERTICAL);
		verticalLeft->Add(inputText, 3, wxEXPAND | wxALL, 4);
		verticalLeft->Add(keyText, 1, wxEXPAND | wxALL, 4);
		verticalLeft->Add(actionButton, 1, wxEXPAND | wxALL, 4);

		leftPanel->SetSizer(verticalLeft);
		verticalLeft->Layout();

		wxSizer* verticalRight = new wxBoxSizer(wxVERTICAL);
		verticalRight->Add(outputText, 1, wxEXPAND | wxALL, 4);
		verticalRight->Add(types_output, 0, wxEXPAND | wxALL, 4);

		rightPanel->SetSizer(verticalRight);
		verticalRight->Layout();
	}
	horizontal->Add(leftPanel, 1, wxEXPAND | wxBOTTOM | wxTOP, 4);
	horizontal->Add(rightPanel, 1, wxEXPAND | wxBOTTOM | wxTOP, 4);
	this->SetSizer(horizontal);
	horizontal->Layout();
}

ControlPanel_Template::~ControlPanel_Template()
{

}


//static vars
const std::vector<std::function<wxString(std::vector<unsigned char> const&)>> ControlPanel_Template::FromBytesMapper = {
	Algo::toUniText,
	Algo::toBits,
	Algo::toHex
};

const std::vector<std::function<void(wxString, std::vector<unsigned char>&)>> ControlPanel_Template::FromUniMapper = {
	Algo::fromUniText,
	Algo::fromUniBitsText,
	Algo::fromUniHexText
};