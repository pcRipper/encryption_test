#include "../Headers/Functions.h"

template <class Iterator, class IteratorType>
void Algo::map(Iterator begin, Iterator end, std::function<void(IteratorType const&)> functor) {
	while (begin != end) {
		functor(*end);
		begin++;
	}
}

std::string Algo::byteToHex(unsigned char byte)
{
	unsigned char left = byte / 16;
	unsigned char right = byte % 16;
	std::string result = std::string(1, left > 9
		? 'A' + left - 10
		: left + '0'
	);
	result += right > 9
		? 'A' + right - 10
		: right + '0'
	;
	return result;
}

wxString Algo::toUniText(std::vector<unsigned char> const& data)
{
	const int RES_LEN = data.size() / 2;
	wxString result;
	result.resize(RES_LEN);

	for (int i = 0; i < RES_LEN; ++i) {
		result[i] = (data[i * 2] << 8) | data[i * 2 + 1];
	}

	return result;
}

wxString Algo::toBits(std::vector<unsigned char> const& data)
{
	wxString result;
	static const wxString bits[2] = { "0", "1" };
	result.reserve(data.size() * 8);

	for (auto c : data) {
		unsigned char mask = 128;
		while (mask != 0) {
			result += bits[c & mask ? 1 : 0];
			mask /= 2;
		}
	}

	return result;
}

wxString Algo::toHex(std::vector<unsigned char> const& data)
{
	wxString result;
	result.reserve(data.size());

	for (auto c : data) {
		std::string hex = Algo::byteToHex(c);
		result += hex[0];
		result += hex[1];
	}

	return result;
}

void Algo::fromUniText(wxString text, std::vector<unsigned char>& destination)
{
	destination.resize(text.length() * 2);

	for (int i = 0; i < text.length(); ++i) {
		uint16_t x = static_cast<uint16_t>(text[i]);
		destination[i * 2] = x >> 8;
		destination[i * 2 + 1] = x & 0xFF;
	}
}

void Algo::fromUniBitsText(wxString text, std::vector<unsigned char>& destination)
{
	const int SIZE = text.size() / 8;
	destination.resize(SIZE);

	int j = 0;
	for (int i = 0; i < SIZE; ++i) {
		unsigned char c = 0;
		for (int n = 0; n < 8; ++n) {
			c = c * 2 + (text[j++] - '0');
		}
		destination[i] = c;
	}
}

void Algo::fromUniHexText(wxString text, std::vector<unsigned char>& destination)
{
	if (text.size() & 1)text.Prepend("0");
	const int SIZE = text.size() / 2;

	int j = 0;
	for (int i = 0; i < SIZE; ++i) {
		//destination[i] = []
	}
}
