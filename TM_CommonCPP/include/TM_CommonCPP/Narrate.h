#pragma once

#include <string>
#include <sstream>
#include <set>
#include "Misc.h"
#include <iostream>

class Narrator
{
private:
	static int iIndent;
	static std::string sIndent;
	Narrator() {}
	~Narrator() {}

	static std::string __Indent()
	{
		return string_repeat(iIndent, sIndent);
	}

public:
#pragma region Narrate Overloads
	static std::string Narrate(int iInt)
	{
		return Narrate_Stringable<int>(iInt);
	}
	static std::string Narrate(const char vCString[])
	{
		return std::string(vCString);
	}
	static std::string Narrate(std::set<int> cSet)
	{
		return Narrate_Collection<std::set<int>>(cSet);
	}
	static std::string Narrate(bool bBool)
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
	static std::string Narrate(std::string sString)
	{
		return sString;
	}
#pragma endregion

	template<typename T>
	static std::string Narrate_Stringable(T vVar)
	{
		return std::to_string(vVar);
	}
	template<typename T>
	static std::string Narrate_Collection(T vVar)
	{
		std::string s = "Collection..";
		for (auto vItem : vVar) {
			s += "\r\n" + __Indent() + Narrate_Stringable(vItem);
		}
		return s;
	}
};
int Narrator::iIndent = 5;
std::string Narrator::sIndent = " ";
