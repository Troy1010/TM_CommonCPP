#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace TMC
{
	class Str
	{
	public: //Perhaps this should be a struct?
		static std::string to_string_hex(int iInt);
		static std::string string_repeat(int n, std::string s);
		static std::vector<std::string> SplitString(const std::string& sString, std::string& sDelimiter, int iMaxSplit = 0);
		static std::vector<std::string> SplitString(const std::string& sString, const char* sDelimiter, int iMaxSplit = 0);
		static std::vector<std::string> RSplitString(const std::string& sString, std::string& sDelimiter, int iMaxSplit = 0);
		static std::vector<std::string> RSplitString(const std::string& sString, const char* sDelimiter, int iMaxSplit = 0);
	};
}
