#pragma once

#include <string>
#include <sstream>

std::string to_string_hex(int iInt)
{
	std::stringstream s;
	s << "0x" << std::hex << iInt;
	return s.str();
}