#pragma once

#include <string>
#include <vector>

namespace TMC
{
	std::string to_string_hex(int iInt);
	std::string string_repeat(int n, std::string s);
	std::vector<std::string> SplitString(std::string& sString, std::string& sDelimiter, int iMaxSplit = 0);
	std::vector<std::string> SplitString(std::string& sString, const char* sDelimiter, int iMaxSplit = 0);
	std::vector<std::string> RSplitString(std::string& sString, std::string& sDelimiter, int iMaxSplit = 0);
	std::vector<std::string> RSplitString(std::string& sString, const char* sDelimiter, int iMaxSplit = 0);

	int IntFromString(std::string sString);
}
