#pragma once

#include <wx/wx.h>

namespace GUI {
	namespace Config {
		namespace Colours {
			const wxColour Blue = wxColour(66, 135, 245);
			const wxColour Bricks = wxColour(235, 121, 87);
		}
		namespace Fonts {
			template <size_t FontSize, wxFontStyle FontStyle, wxFontWeight FontWeight>
			static const wxFont RobotoFont = wxFont(FontSize, wxFONTFAMILY_DEFAULT, FontStyle, FontWeight, false, "Robot");
		}
	}
}