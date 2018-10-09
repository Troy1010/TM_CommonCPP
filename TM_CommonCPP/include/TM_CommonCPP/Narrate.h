#pragma once

#include <string>
#include <sstream>
#include <set>
#include "Misc.h"
#include <iostream>

#ifdef TMCOMMONCPP_EXPORTS
#define TMCommonCPP_API __declspec(dllexport)
#else
//#define TMCommonCPP_API __declspec(dllimport)
#define TMCommonCPP_API
#endif

namespace TM_CommonCPP
{
	class Narrator
	{
	private:
		static std::string sIndent;
		Narrator() {}
		~Narrator() {}
	public:
		static int TMCommonCPP_API iIndent;
		static std::string TMCommonCPP_API Indent();

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
				ss << "\n" + TM_CommonCPP::Narrator::Indent() << TM_CommonCPP::Narrate(vItem);
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
				s += "\n" + TM_CommonCPP::Narrator::Indent() + TM_CommonCPP::Narrator::Narrate_Collection(vItem);
			}
			iIndent--;
			return s;
		}
	};

#pragma region Narrate Overloads
	std::string TMCommonCPP_API Narrate(int iInt);
	std::string TMCommonCPP_API Narrate(const char vCString[]);
	std::string TMCommonCPP_API Narrate(std::set<int> cSet);
	std::string TMCommonCPP_API Narrate(bool bBool);
	std::string TMCommonCPP_API Narrate(std::string sString);
	std::string TMCommonCPP_API Narrate(float fFloat);
	std::string TMCommonCPP_API Narrate(std::set<std::set<int>> c2dSet);
	std::string TMCommonCPP_API Narrate(double vDouble);
#pragma endregion
}




