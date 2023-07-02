#pragma once

#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <iostream>
#include <functional>
#include <list>

namespace TMC
{
	std::string ToDisplayStr(int iInt);
	std::string ToDisplayStr(const char vCString[]);
	std::string ToDisplayStr(std::set<int> cSet);
	std::string ToDisplayStr(std::list<int> cList);
	std::string ToDisplayStr(bool bBool);
	std::string ToDisplayStr(std::string sString);
	std::string ToDisplayStr(float fFloat);
	std::string ToDisplayStr(std::set<std::set<int>> c2dSet);
	std::string ToDisplayStr(double vDouble);
	std::string ToDisplayStr(std::vector<std::string> cStrings);
	std::string ToDisplayStr(std::pair<int, std::string> vPair);
	class DisplayStrGenerator
	{
	private:
		static std::string sIndent;
		DisplayStrGenerator() {}
		~DisplayStrGenerator() {}
	public:
		static int iIndent;
		static std::string Indent();

		template<typename T>
		static std::string ToDisplayStr_StringStreamable(T vVar)
		{
			std::ostringstream ss;
			ss << vVar;
			return ss.str();
		}
		template<typename T>
		static std::string ToDisplayStr_Collection(T vVar)
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
				ss << "\n" + TMC::DisplayStrGenerator::Indent() << TMC::ToDisplayStr(vItem);
			}
			iIndent--;
			return ss.str();
		}
		template<typename T, typename T2>
		static std::string ToDisplayStr_Collection(T vVar, T2 vFunc)
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
				ss << "\n" + TMC::DisplayStrGenerator::Indent() << vFunc(vItem);
			}
			iIndent--;
			return ss.str();
		}
		template<typename T>
		static std::string ToDisplayStr_2dCollection(T vVar)
		{
			std::string s = "Collection..";
			iIndent++;
			for (auto vItem : vVar) {
				s += "\n" + TMC::DisplayStrGenerator::Indent() + TMC::DisplayStrGenerator::ToDisplayStr_Collection(vItem);
			}
			iIndent--;
			return s;
		}
	};
}




