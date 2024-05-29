#include <wx/wx.h>
#include <wx/panel.h>

#include <list>
#include <string>

#include <GUI/General/Headers/Config.h>
#include <GUI/AES_Tab/Headers/ControlPanel_Template.h>

#include <Algo/Headers/Functions.h>

#include <AES256/Headers/aes256.hpp>

class AES_Tab_Encrypt : public ControlPanel_Template {
public:
	AES_Tab_Encrypt(wxWindow* parent);

	~AES_Tab_Encrypt() = default;

	//local variables
private:
	static const std::list<std::string> input_menu_options;
	static const std::list<std::string> output_menu_options;
	ByteArray encrypted;

	//events
private:
	virtual void OnActionClick(wxCommandEvent& event) override;
	virtual void OnChoiceInputSelected(wxCommandEvent& event) override;
	virtual void OnChoiceOutputSelected(wxCommandEvent& event) override;
};