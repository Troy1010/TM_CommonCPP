#pragma once

#include <string>
#include <sstream>
#include <set>
#include "Misc.h"
#include <iostream>
#include <functional>

namespace TMC
{
#pragma region Narrate Overloads
	std::string Narrate(int iInt);
	std::string Narrate(const char vCString[]);
	std::string Narrate(std::set<int> cSet);
	std::string Narrate(bool bBool);
	std::string Narrate(std::string sString);
	std::string Narrate(float fFloat);
	std::string Narrate(std::set<std::set<int>> c2dSet);
	std::string Narrate(double vDouble);
	std::string Narrate(std::vector<std::string> cStrings);
	std::string Narrate(std::pair<int, std::string> vPair);
#pragma endregion
	class Narrator
	{
	private:
		static std::string sIndent;
		Narrator() {}
		~Narrator() {}
	public:
		static int iIndent;
		static std::string Indent();

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
			std::ostringstream ss;
			//---Empty Collection
			if (vVar.size() == 0)
			{
				return std::string("<Empty Collection>");
			}
			//---
			ss << "Collection(Size:" << vVar.size() << ")..";
			iIndent++;
			for (auto vItem : vVar) {
				ss << "\n" + TMC::Narrator::Indent() << TMC::Narrate(vItem);
			}
			iIndent--;
			return ss.str();
		}
		template<typename T, typename T2>
		static std::string Narrate_Collection(T vVar, T2 vFunc)
		{
			std::ostringstream ss;
			//---Empty Collection
			if (vVar.size() == 0)
			{
				return std::string("<Empty Collection>");
			}
			//---
			ss << "Collection(Size:" << vVar.size() << ")..";
			iIndent++;
			for (auto vItem : vVar) {
				ss << "\n" + TMC::Narrator::Indent() << vFunc(vItem);
			}
			iIndent--;
			return ss.str();
		}
		template<typename T>
		static std::string Narrate_2dCollection(T vVar)
		{
			std::string s = "Collection..";
			iIndent++;
			for (auto vItem : vVar) {
				s += "\n" + TMC::Narrator::Indent() + TMC::Narrator::Narrate_Collection(vItem);
			}
			iIndent--;
			return s;
		}
	};
}




