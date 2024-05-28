#include "../Headers/AES_Tab_Encrypt.h"

const std::list<std::string> AES_Tab_Encrypt::menu_options = { "Text", "Binary", "Hex" };

AES_Tab_Encrypt::AES_Tab_Encrypt(wxWindow* parent) :
	ControlPanel_Template(parent, &AES_Tab_Encrypt::menu_options)
{
	this->keyText->textBox->SetHint("Input password of length 16");
	this->actionButton->SetLabel("Encrypt");

	//binds
	this->actionButton->Bind(wxEVT_BUTTON, &AES_Tab_Encrypt::OnActionClick, this);
	this->types_output->Bind(wxEVT_CHOICE, &AES_Tab_Encrypt::OnChoiceSelected, this);
	this->types_output->SetSelection(0);
}

void AES_Tab_Encrypt::OnActionClick(wxCommandEvent& event)
{
	if (this->inputText->textBox->GetValue().size() == 0) {
		wxMessageBox("No input data!");
		return;
	}
	if (this->keyText->textBox->GetValue().size() != 16) {
		wxMessageBox("Password length should be of length 16");
		return;
	}

	try {

		ByteArray key;
		Algo::fromUniText(this->keyText->textBox->GetValue(), key);
		
		ByteArray plain;
		Algo::fromUniText(this->inputText->textBox->GetValue(), plain);

		//unnecessary in current implementation
		this->encrypted.clear();
		Aes256::encrypt(key, plain, this->encrypted);

		if (encrypted.size() & 1)encrypted.push_back(0);

		this->outputText->textBox->SetValue(ControlPanel_Template::FromBytesMapper[event.GetSelection()](this->encrypted));
	}
	catch (std::exception const& ex) {
		wxMessageBox("Error occured: " + std::string(ex.what()));
	}
}

void AES_Tab_Encrypt::OnChoiceSelected(wxCommandEvent& event)
{
	this->outputText->textBox->SetValue(ControlPanel_Template::FromBytesMapper[event.GetSelection()](this->encrypted));
}