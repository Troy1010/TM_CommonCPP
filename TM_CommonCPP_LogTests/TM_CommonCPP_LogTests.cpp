#include "pch.h"
#include <iostream>
#include "plog/Log.h"
#include "TM_CommonCPP/Narrate.h"
#include "TM_CommonCPP/PlogFormatter.h"
#include "TM_CommonCPP/Misc.h"
#include "TM_CommonCPP/Util_VariadicMacros.h"
#include "TM_CommonCPP/String.h"

#include <iostream>
#include <fstream>
#include <map>

std::string Hello(int i)
{
	return "Hello";
}
std::string StringizeInt(int i)
{
	return TMC::Narrate(i);
}


int main()
{
	remove("Log_LogTests.txt");
	plog::init<plog::MyFormatter>(plog::debug, "Log_LogTests.txt");
	// start
	std::set<int> cSet;
	cSet.insert(43);
	cSet.insert(90);
	cSet.insert(63);
	LOGD << "cSet:" << TMC::Narrate(cSet);
	std::set<std::set<int>> c2dSet = std::set<std::set<int>>();
	std::set<int> cSet2;
	cSet2.insert(34);
	cSet2.insert(19);
	cSet2.insert(36);
	std::set<int> cSet3 = std::set<int>();
	c2dSet.insert(cSet);
	c2dSet.insert(cSet2);
	c2dSet.insert(cSet3);
	LOGD << "Narrate_Collection(cSet2):" << TMC::Narrator::Narrate_Collection(cSet2);
	LOGD << "Narrate_Collection(cSet2, StringizeInt):" << TMC::Narrator::Narrate_Collection(cSet2, StringizeInt);
	LOGD << "Narrate_Collection(c2dSet,..):" << TMC::Narrator::Narrate_Collection(c2dSet, TMC::Narrator::Narrate_Collection< std::set<int>>);
	LOGD << "Narrate_2dCollection(c2dSet):" << TMC::Narrator::Narrate_2dCollection(c2dSet);
	std::map<int, std::string> cMap;
	cMap.insert({ 14,"c" });
	cMap.insert({ 140,"rthdt" });
	cMap.insert({ -3,"limbo" });
	LOGD << "Narrate_Collection(cMap):" << TMC::Narrator::Narrate_Collection(cMap);
}
