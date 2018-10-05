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
	static std::string Narrate(int iInt)
	{
		return Narrate_Stringable<int>(iInt);
	}
	static std::string Narrate(std::set<int> cSet)
	{
		return Narrate_Collection<std::set<int>>(cSet);
	}

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
