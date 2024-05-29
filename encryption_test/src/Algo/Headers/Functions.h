#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <string>

#include <functional>
#include <algorithm>
#include <numeric>
#include <conio.h>

#include <wx/wx.h>

namespace Algo {

	template <class Iterator, class IteratorType>
	void map(Iterator begin, Iterator end, std::function<void(IteratorType const&)> functor);
	
	std::string byteToHex(unsigned char byte);
	unsigned char hexToByte(char hex);

	wxString toUniText(std::vector<unsigned char> const& data);
	wxString toBits   (std::vector<unsigned char> const& data);
	wxString toHex    (std::vector<unsigned char> const& data);


	void fromUniText    (wxString text, std::vector<unsigned char>& destination);
	void fromUniBitsText(wxString text, std::vector<unsigned char>& destination);
	void fromUniHexText (wxString text, std::vector<unsigned char>& destination);
}
