#include "TM_CommonCPP/ToLogStr.h"
#include "TM_CommonCPP/String.h"

namespace TMC
{
	int LogStrFactory::iIndent = 0;
	std::string LogStrFactory::sIndent = " ";
	std::string LogStrFactory::Indent()
	{
		return Str::Repeat(sIndent, iIndent);
	}
	std::string ToLogStr(int iInt)
	{
		return std::to_string(iInt);
	}
	std::string ToLogStr(const char vCString[])
	{
		return std::string(vCString);
	}
	std::string ToLogStr(std::set<int> cSet)
	{
		return LogStrFactory::ToLogStr_Collection(cSet);
	}
	std::string ToLogStr(std::list<int> cList)
	{
		return LogStrFactory::ToLogStr_Collection(cList);
	}
	std::string ToLogStr(std::set<std::set<int>> c2dSet)
	{
		return LogStrFactory::ToLogStr_Collection(c2dSet, TMC::LogStrFactory::ToLogStr_Collection<std::set<int>>);
	}
	std::string ToLogStr(bool bBool)
	{
		if (bBool)
		{
			return std::string("true");
		}
		else
		{
			return std::string("false");
		}
	}
	std::string ToLogStr(std::string sString)
	{
		return sString;
	}
	std::string ToLogStr(float fFloat)
	{
		return LogStrFactory::ToLogStr_StringStreamable(fFloat);
	}
	std::string ToLogStr(double vDouble)
	{
		return LogStrFactory::ToLogStr_StringStreamable(vDouble);
	}
	std::string ToLogStr(std::vector<std::string> cStrings)
	{
		return LogStrFactory::ToLogStr_Collection(cStrings);
	}
	std::string ToLogStr(std::pair<int, std::string> vPair)
	{
		return ToLogStr(vPair.first) + ":" + ToLogStr(vPair.second);
	}
}
