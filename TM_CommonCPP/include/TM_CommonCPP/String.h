#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace TMC
{
	class Str
	{
	public:
		static std::string Hex(int iInt);
		static std::string Repeat(const std::string& s, int n);
		static std::vector<std::string> Split(const std::string& sString, const std::string& sDelimiter, const int iMaxSplit = 0);
		static std::vector<std::string> RSplit(const std::string& sString, const std::string& sDelimiter, const int iMaxSplit = 0);
		static std::string Replace(std::string& s, const std::string& sFrom, const std::string& sTo);
	};
}
