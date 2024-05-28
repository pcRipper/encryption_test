#include <wx/wx.h>
#include <wx/panel.h>

#include <list>
#include <string>

#include <GUI/General/Headers/Config.h>
#include <GUI/AES_Tab/Headers/ControlPanel_Template.h>

#include <Algo/Headers/Functions.h>

#include <AES256/Headers/aes256.hpp>

class AES_Tab_Decrypt : public ControlPanel_Template {
public:
	AES_Tab_Decrypt(wxWindow* parent);

	~AES_Tab_Decrypt() = default;

	//local variables
private:
	static const std::list<std::string> menu_options;
	ByteArray decrypted;
	
	//events
private:
	virtual void OnActionClick(wxCommandEvent& event) override;
	virtual void OnChoiceSelected(wxCommandEvent& event) override;
};