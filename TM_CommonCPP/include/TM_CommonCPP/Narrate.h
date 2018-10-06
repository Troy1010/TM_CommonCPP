#pragma once

#include <string>
#include <sstream>
#include <set>
#include "Misc.h"
#include <iostream>

namespace TM_CommonCPP
{
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

		template<typename T>
		static std::string Narrate_Stringable(T vVar)
		{
			return std::to_string(vVar);
		}
		template<typename T>
		static std::string Narrate_StringStreamable(T vVar)
		{
			std::ostringstream ss;
			ss << vVar;
			return ss.str();
		}
		template<typename T>
		static std::string Narrate_Collection(T vVar)
		{
			std::string s = "Collection..";
			for (auto vItem : vVar) {
				s += "\r\n" + __Indent() + TM_CommonCPP::Narrate(vItem);
			}
			return s;
		}
	};
	int Narrator::iIndent = 5;
	std::string Narrator::sIndent = " ";

#pragma region Narrate Overloads
	static std::string Narrate(int iInt)
	{
		return Narrator::Narrate_Stringable<int>(iInt);
	}
	static std::string Narrate(const char vCString[])
	{
		return std::string(vCString);
	}
	static std::string Narrate(std::set<int> cSet)
	{
		return Narrator::Narrate_Collection<std::set<int>>(cSet);
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
	static std::string Narrate(float fFloat)
	{
		return Narrator::Narrate_StringStreamable(fFloat);
	}
#pragma endregion
}




