#pragma once

#include <string>
#include <sstream>
#include <set>
#include "Misc.h"
#include <iostream>

#ifdef TMCOMMONCPP_EXPORTS
#define TMCommonCPP_API __declspec(dllexport)   
#else  
#define TMCommonCPP_API __declspec(dllimport)   
#endif 

namespace TM_CommonCPP
{
	class Narrator
	{
	private:
		static int iIndent;
		static std::string sIndent;
		Narrator() {}
		~Narrator() {}
		static std::string TMCommonCPP_API __Indent();
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
				s += "\r\n" + TM_CommonCPP::Narrator::__Indent() + TM_CommonCPP::Narrate(vItem);
			}
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
#pragma endregion
}




