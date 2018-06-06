#pragma once

#include <string>
#include <sstream>

std::string to_string_hex(int iInt)
{
	std::stringstream s;
	s << "0x" << std::hex << iInt;
	return s.str();
}

std::string string_repeat(int n, std::string s) {
	std::ostringstream os;
	for (int i = 0; i < n; i++)
		os << s;
	return os.str();
}