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
	ControlPanel_Template(
		wxWindow* parent,
		std::list<std::string> const* input_options_list,
		std::list<std::string> const* output_options_list
	);

	static const std::vector<std::function<wxString(std::vector<unsigned char> const&)>> FromBytesMapper;
	static const std::vector<std::function<void(wxString, std::vector<unsigned char> &)>> FromUniMapper;

	~ControlPanel_Template();

//local variables
protected:
	std::vector<wxString> input_options;
	std::vector<wxString> output_options;

//gui elements
protected:
	wxPanel* leftPanel;
	SignedTextCtrl* inputText;
	wxChoice* types_input;
	SignedTextCtrl* keyText;
	wxButton* actionButton;

	wxPanel* rightPanel;
	SignedTextCtrl* outputText;
	wxChoice* types_output;

//events
protected:
	virtual void OnActionClick(wxCommandEvent& event) = 0;
	virtual void OnChoiceInputSelected(wxCommandEvent& event) = 0;
	virtual void OnChoiceOutputSelected(wxCommandEvent& event) = 0;
};