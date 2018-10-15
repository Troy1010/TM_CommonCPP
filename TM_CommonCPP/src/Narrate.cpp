#include "stdafx.h"
#include "TM_CommonCPP/Narrate.h"

namespace TMC
{
	int Narrator::iIndent = 0;
	std::string Narrator::sIndent = " ";
	std::string Narrator::Indent()
	{
		return string_repeat(iIndent, sIndent);
	}
#pragma region Narrate Overloads
	std::string Narrate(int iInt)
	{
		return std::to_string(iInt);
	}
	std::string Narrate(const char vCString[])
	{
		return std::string(vCString);
	}
	std::string Narrate(std::set<int> cSet)
	{
		return Narrator::Narrate_Collection(cSet);
	}
	std::string Narrate(std::set<std::set<int>> c2dSet)
	{
		return Narrator::Narrate_2dCollection(c2dSet);
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
	std::string Narrate(float fFloat)
	{
		return Narrator::Narrate_StringStreamable(fFloat);
	}
	std::string Narrate(double vDouble)
	{
		return Narrator::Narrate_StringStreamable(vDouble);
	}
#pragma endregion
}
