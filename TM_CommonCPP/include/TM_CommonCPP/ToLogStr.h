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
	std::string ToLogStr(int iInt);
	std::string ToLogStr(const char vCString[]);
	std::string ToLogStr(std::set<int> cSet);
	std::string ToLogStr(std::list<int> cList);
	std::string ToLogStr(bool bBool);
	std::string ToLogStr(std::string sString);
	std::string ToLogStr(float fFloat);
	std::string ToLogStr(std::set<std::set<int>> c2dSet);
	std::string ToLogStr(double vDouble);
	std::string ToLogStr(std::vector<std::string> cStrings);
	std::string ToLogStr(std::pair<int, std::string> vPair);
	class LogStrFactory
	{
	private:
		static std::string sIndent;
		LogStrFactory() {}
		~LogStrFactory() {}
	public:
		static int iIndent;
		static std::string Indent();

		template<typename T>
		static std::string ToLogStr_StringStreamable(T vVar)
		{
			std::ostringstream ss;
			ss << vVar;
			return ss.str();
		}
		template<typename T>
		static std::string ToLogStr_Collection(T vVar)
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
				ss << "\n" + TMC::LogStrFactory::Indent() << TMC::ToLogStr(vItem);
			}
			iIndent--;
			return ss.str();
		}
		template<typename T, typename T2>
		static std::string ToLogStr_Collection(T vVar, T2 vFunc)
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
				ss << "\n" + TMC::LogStrFactory::Indent() << vFunc(vItem);
			}
			iIndent--;
			return ss.str();
		}
		template<typename T>
		static std::string ToLogStr_2dCollection(T vVar)
		{
			std::string s = "Collection..";
			iIndent++;
			for (auto vItem : vVar) {
				s += "\n" + TMC::LogStrFactory::Indent() + TMC::LogStrFactory::ToLogStr_Collection(vItem);
			}
			iIndent--;
			return s;
		}
	};
}




