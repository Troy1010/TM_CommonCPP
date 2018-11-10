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

	std::vector<std::string> Str::Split(const std::string& sString, const std::string &sDelimiter, const int iMaxSplit, const bool bInclusive)
	{
		std::vector<std::string> cReturningStrings;
		int iSplitCountdown = iMaxSplit - 1;
		size_t findPos = 0, startSearchPos = 0;
		while (((findPos = sString.find(sDelimiter, startSearchPos)) != std::string::npos) && (iSplitCountdown > 0 || iMaxSplit == 0)) {
			cReturningStrings.push_back(sString.substr(startSearchPos, findPos - startSearchPos));
			startSearchPos = findPos + sDelimiter.length(); iSplitCountdown--;
		}
		if (bInclusive || findPos == std::string::npos)
			cReturningStrings.push_back(sString.substr(startSearchPos, std::string::npos));
		else
			cReturningStrings.push_back(sString.substr(startSearchPos, findPos - startSearchPos));
		return cReturningStrings;
	}
	std::vector<std::string> Str::RSplit(const std::string& sString, const std::string &sDelimiter, const int iMaxSplit, const bool bInclusive)
	{
		std::vector<std::string> cReturningStrings;
		int iSplitCountdown = iMaxSplit - 1;
		size_t findPos = 0, startSearchPos = sString.length() - 1;
		while (((findPos = sString.rfind(sDelimiter, startSearchPos)) != std::string::npos) && (iSplitCountdown > 0 || iMaxSplit == 0)) {
			cReturningStrings.push_back(sString.substr(findPos + sDelimiter.length(), startSearchPos + 1 - (findPos + sDelimiter.length())));
			startSearchPos = findPos - 1; iSplitCountdown--;
		}
		if (bInclusive || findPos == std::string::npos)
			cReturningStrings.push_back(sString.substr(0, startSearchPos + 1));
		else
			cReturningStrings.push_back(sString.substr(findPos + sDelimiter.length(), startSearchPos + 1 - (findPos + sDelimiter.length())));
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
