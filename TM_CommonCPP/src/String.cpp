#include "stdafx.h"
#include "TM_CommonCPP/String.h"

namespace TMC
{
	std::string Str::Hex(int iInt) //perhaps this shouldn't be here
	{
		std::stringstream s;
		s << "0x" << std::hex << iInt;
		return s.str();
	}

	std::string Str::Repeat(const std::string& s, int n) {
		std::ostringstream os;
		for (int i = 0; i < n; i++)
			os << s;
		return os.str();
	}

	std::vector<std::string> Str::Split(const std::string& sString, const std::string &sDelimiter, const int iMaxSplit)
	{
		std::vector<std::string> cReturningStrings;
		size_t prev = 0, pos;
		int iSplitCount = 0;
		do
		{
			pos = sString.find(sDelimiter, prev);
			if (pos == std::string::npos) pos = sString.length();
			std::string token = sString.substr(prev, pos - prev);
			cReturningStrings.push_back(token);
			prev = pos + sDelimiter.length();
			iSplitCount++;
		} while (pos < sString.length() && pos < sString.length() && ((iMaxSplit == 0) || iSplitCount < iMaxSplit));
		return cReturningStrings;
	}
	std::vector<std::string> Str::RSplit(const std::string& sString, const std::string &sDelimiter, const int iMaxSplit)
	{
		std::vector<std::string> cReturningStrings;
		size_t vDelimSize = sDelimiter.length();
		size_t prev = sString.length() - vDelimSize, pos;
		int iSplitCount = 0;
		std::string token;
		do
		{
			pos = sString.rfind(sDelimiter, prev);
			if (pos == std::string::npos)
			{
				pos = 0 - vDelimSize;
			}
			std::string token = sString.substr(pos + vDelimSize, prev - pos);
			cReturningStrings.push_back(token);
			prev = pos - vDelimSize;
			iSplitCount++;
		} while (pos < sString.length() && prev < sString.length() && ((iMaxSplit == 0) || iSplitCount < iMaxSplit));
		std::reverse(cReturningStrings.begin(), cReturningStrings.end());
		return cReturningStrings;
	}
	std::string Str::Replace(std::string& s, const std::string& sFrom, const std::string& sTo)
	{
		if (sFrom.empty())
			return s;
		size_t findPos = 0;
		while ((findPos = s.find(sFrom, findPos)) != std::string::npos) {
			s.replace(findPos, sFrom.length(), sTo);
			findPos += sTo.length();
		}
		return s;
	}
}
