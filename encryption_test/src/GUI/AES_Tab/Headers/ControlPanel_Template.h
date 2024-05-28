#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/button.h>

#include <list>
#include <vector>
#include <string>

#include <Algo/Headers/Functions.h>
#include <GUI/General/Headers/SignedTextCtrl.h>
#include <GUI/General/Headers/Config.h>

class ControlPanel_Template : public wxPanel {
public:
	ControlPanel_Template(wxWindow* parent, std::list<std::string> const* menu_options);

	static const std::vector<std::function<wxString(std::vector<unsigned char> const&)>> FromBytesMapper;
	static const std::vector<std::function<void(wxString, std::vector<unsigned char> &)>> FromUniMapper;

	~ControlPanel_Template();

//local variables
protected:
	std::vector<wxString> options;

//gui elements
protected:
	wxPanel* leftPanel;
	SignedTextCtrl* inputText;
	SignedTextCtrl* keyText;
	wxButton* actionButton;

	wxPanel* rightPanel;
	SignedTextCtrl* outputText;
	wxChoice* types_output;

//events
protected:
	virtual void OnActionClick(wxCommandEvent& event) = 0;
	virtual void OnChoiceSelected(wxCommandEvent& event) = 0;
};