#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace TMC
{
	class Str
	{
	public: //Perhaps this should be a struct?
		static std::string Hex(int iInt);
		static std::string Repeat(const std::string& s, int n);
		static std::vector<std::string> Split(const std::string& sString, std::string& sDelimiter, int iMaxSplit = 0);
		static std::vector<std::string> Split(const std::string& sString, const char* sDelimiter, int iMaxSplit = 0);
		static std::vector<std::string> RSplit(const std::string& sString, std::string& sDelimiter, int iMaxSplit = 0);
		static std::vector<std::string> RSplit(const std::string& sString, const char* sDelimiter, int iMaxSplit = 0);
	};
}
