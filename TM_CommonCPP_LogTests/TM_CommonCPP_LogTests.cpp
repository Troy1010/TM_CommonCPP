#include "pch.h"
#include <iostream>
#include "plog/Log.h"
#include "../TM_CommonCPP/include/TM_CommonCPP/Narrate.h"
#include "../TM_CommonCPP/include/TM_CommonCPP/PlogFormatter.h"

#include <iostream>
#include <fstream>

namespace TM_CommonCPP
{
	static std::string Narrate(float fFloat)
	{
		//return Narrator::Narrate_Stringable<int>(fFloat);
		std::ostringstream ss;
		ss << fFloat;
		std::string s(ss.str());
		return ss.str();
	}
}


int main()
{
	remove("Log_LogTests.txt");
	plog::init<plog::MyFormatter>(plog::debug, "Log_LogTests.txt");
	LOGD << "START";
#pragma region Narrate
	int i = 2;
	LOGD << "i:" << TM_CommonCPP::Narrate(i);
	const char vCString[] = "qwer";
	LOGD << "vCString:" << TM_CommonCPP::Narrate(vCString);
	std::set<int> cSet;
	cSet.insert(43);
	cSet.insert(90);
	cSet.insert(63);
	LOGD << "cSet:" << TM_CommonCPP::Narrate(cSet);
	bool bBool = true;
	LOGD << "bBool:" << TM_CommonCPP::Narrate(bBool);
	float fFloat = 0.46f;
	LOGD << "fFloat:" << TM_CommonCPP::Narrate(fFloat);
#pragma endregion
}
