#include "pch.h"
#include <iostream>

#include "plog/Log.h"
#include "../TM_CommonCPP/include/TM_CommonCPP/Narrate.h"



int main()
{
	plog::init<plog::MyFormatter>(plog::debug, "Log_LogTests.txt");
	LOGD << "START";
#pragma region Narrate
	int i = 2;
	LOGD << "i:" << Narrate(i);
	const char vCString[] = "qwer";
	LOGD << "vCString:" << Narrate(vCString);
	std::set<int> cSet;
	cSet.insert(43);
	cSet.insert(90);
	cSet.insert(63);
	LOGD << "cSet:" << Narrate(cSet);
#pragma endregion
}
