#include "TM_CommonCPP/ToDisplayStr.h"
#include "TM_CommonCPP/String.h"

namespace TMC
{
	int DisplayStrGenerator::iIndent = 0;
	std::string DisplayStrGenerator::sIndent = " ";
	std::string DisplayStrGenerator::Indent()
	{
		return Str::Repeat(sIndent, iIndent);
	}
	std::string ToDisplayStr(int iInt)
	{
		return std::to_string(iInt);
	}
	std::string ToDisplayStr(const char vCString[])
	{
		return std::string(vCString);
	}
	std::string ToDisplayStr(std::set<int> cSet)
	{
		return DisplayStrGenerator::ToDisplayStr_Collection(cSet);
	}
	std::string ToDisplayStr(std::list<int> cList)
	{
		return DisplayStrGenerator::ToDisplayStr_Collection(cList);
	}
	std::string ToDisplayStr(std::set<std::set<int>> c2dSet)
	{
		return DisplayStrGenerator::ToDisplayStr_Collection(c2dSet, TMC::DisplayStrGenerator::ToDisplayStr_Collection<std::set<int>>);
	}
	std::string ToDisplayStr(bool bBool)
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
	std::string ToDisplayStr(std::string sString)
	{
		return sString;
	}
	std::string ToDisplayStr(float fFloat)
	{
		return DisplayStrGenerator::ToDisplayStr_StringStreamable(fFloat);
	}
	std::string ToDisplayStr(double vDouble)
	{
		return DisplayStrGenerator::ToDisplayStr_StringStreamable(vDouble);
	}
	std::string ToDisplayStr(std::vector<std::string> cStrings)
	{
		return DisplayStrGenerator::ToDisplayStr_Collection(cStrings);
	}
	std::string ToDisplayStr(std::pair<int, std::string> vPair)
	{
		return ToDisplayStr(vPair.first) + ":" + ToDisplayStr(vPair.second);
	}
}
