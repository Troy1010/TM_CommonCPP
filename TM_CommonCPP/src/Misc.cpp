#include "stdafx.h"
#include "TM_CommonCPP/Misc.h"
#include <sstream>

namespace TMC
{
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

	std::vector<std::string> SplitString(std::string &sString, std::string &sDelimiter)
	{
		std::vector<std::string> cStrings;
		size_t prev = 0, pos = 0;
		do
		{
			pos = sString.find(sDelimiter, prev);
			if (pos == std::string::npos) pos = sString.length();
			std::string token = sString.substr(prev, pos - prev);
			//if (!token.empty()) cStrings.push_back(token); // Lets not skip empty
			cStrings.push_back(token);
			prev = pos + sDelimiter.length();
		} while (pos < sString.length() && prev < sString.length());
		return cStrings;
	}
	std::vector<std::string> SplitString(std::string& sString, const char* sDelimiter)
	{
		std::string sTemp = std::string(sDelimiter);
		return SplitString(sString, sTemp);
		//return SplitString(sString, std::string(sDelimiter)); // Errors. Why?
	}

	int IntFromString(std::string sString)
	{
		int iTemp = 0;
		std::istringstream(sString) >> iTemp;
		return iTemp;
	}
}
