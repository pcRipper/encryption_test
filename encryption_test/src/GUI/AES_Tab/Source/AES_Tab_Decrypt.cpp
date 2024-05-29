#include "../Headers/AES_Tab_Decrypt.h"

const std::list<std::string> AES_Tab_Decrypt::input_menu_options = {"Text", "Binary", "Hex"};
const std::list<std::string> AES_Tab_Decrypt::output_menu_options = {"Text", "Binary", "Hex"};

AES_Tab_Decrypt::AES_Tab_Decrypt(wxWindow* parent):
	ControlPanel_Template(
		parent, 
		&AES_Tab_Decrypt::input_menu_options,
		&AES_Tab_Decrypt::output_menu_options
	)
{
	this->keyText->textBox->SetHint("Input password of length 16");
	this->actionButton->SetLabel("Decrypt");
	
	//binds
	this->actionButton->Bind(wxEVT_BUTTON, &AES_Tab_Decrypt::OnActionClick, this);
	this->types_input->Bind(wxEVT_CHOICE, &AES_Tab_Decrypt::OnChoiceInputSelected, this);
	this->types_output->Bind(wxEVT_CHOICE, &AES_Tab_Decrypt::OnChoiceOutputSelected, this);
	
	//misc
	this->types_input->SetSelection(0);
	this->types_output->SetSelection(0);
}

void AES_Tab_Decrypt::OnActionClick(wxCommandEvent& event)
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

		ByteArray encrypted;
		ControlPanel_Template::FromUniMapper[this->types_input->GetCurrentSelection()](
			this->inputText->textBox->GetValue(),
			encrypted
		);

		this->decrypted.clear();
		Aes256::decrypt(key, encrypted, this->decrypted);

		this->outputText->textBox->SetValue(ControlPanel_Template::FromBytesMapper[this->types_output->GetCurrentSelection()](this->decrypted));
	}
	catch (std::exception const& ex) {
		wxMessageBox("Error occured: " + std::string(ex.what()));
	}
}

void AES_Tab_Decrypt::OnChoiceInputSelected(wxCommandEvent& event)
{
	//empty...
}

void AES_Tab_Decrypt::OnChoiceOutputSelected(wxCommandEvent& event)
{
	this->outputText->textBox->SetValue(ControlPanel_Template::FromBytesMapper[event.GetSelection()](this->decrypted));
}
