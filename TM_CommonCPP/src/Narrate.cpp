#include "stdafx.h"
#include "TM_CommonCPP/Narrate.h"

namespace TM_CommonCPP
{
	int Narrator::iIndent = 5;
	std::string Narrator::sIndent = " ";
	std::string TMCommonCPP_API Narrator::__Indent()
	{
		return string_repeat(iIndent, sIndent);
	}
#pragma region Narrate Overloads
	std::string Narrate(int iInt)
	{
		return Narrator::Narrate_Stringable<int>(iInt);
	}
	std::string Narrate(const char vCString[])
	{
		return std::string(vCString);
	}
	std::string Narrate(std::set<int> cSet)
	{
		return Narrator::Narrate_Collection<std::set<int>>(cSet);
	}
	std::string Narrate(bool bBool)
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
	std::string Narrate(std::string sString)
	{
		return sString;
	}
	/*std::string Narrate(float fFloat)
	{
		return Narrator::Narrate_StringStreamable(fFloat);
	}*/
#pragma endregion
}
