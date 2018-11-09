#include "pch.h"
#include <iostream>
#include "plog/Log.h"
#include "TM_CommonCPP/Narrate.h"
#include "TM_CommonCPP/PlogFormatter.h"
#include "TM_CommonCPP/Misc.h"
#include "TM_CommonCPP/Util_VariadicMacros.h"

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
#pragma region Narrate
	int i = 2;
	LOGD << "i:" << TMC::Narrate(i);
	const char vCString[] = "qwer";
	LOGD << "vCString:" << TMC::Narrate(vCString);
	std::set<int> cSet;
	cSet.insert(43);
	cSet.insert(90);
	cSet.insert(63);
	LOGD << "cSet:" << TMC::Narrate(cSet);
	bool bBool = true;
	LOGD << "bBool:" << TMC::Narrate(bBool);
	float fFloat = 0.46f;
	LOGD << "fFloat:" << TMC::Narrate(fFloat);
	std::set<std::set<int>> c2dSet = std::set<std::set<int>>();
	std::set<int> cSet2;
	cSet2.insert(34);
	cSet2.insert(19);
	cSet2.insert(36);
	std::set<int> cSet3 = std::set<int>();
	c2dSet.insert(cSet);
	c2dSet.insert(cSet2);
	c2dSet.insert(cSet3);
	LOGD << "c2dSet:" << TMC::Narrate(c2dSet);
	std::set<int> cSet4;
	LOGD << "cSetSize:" << cSet.size() << "  cSet3Size:" << cSet3.size() << "  cSet4Size:" << cSet4.size();
	double vDouble = 0.154;
	LOGD << "vDouble:" << TMC::Narrate(vDouble);
	int iInt1 = 2;
	int iInt2 = 34;
	LOGD << "COUNT_ARGS:" << COUNT_ARGS(iInt1, iInt2);
	std::string sString = "how,can,this,be";
	std::string sDelim = std::string(",");
	LOGD << TMC::Narrate(TMC::SplitString(sString, sDelim));
	sString = "look^at^that^landscape";
	LOGD << TMC::Narrate(TMC::SplitString(sString, "^"));
	sString = "am,,I,empty";
	LOGD << TMC::Narrate(TMC::SplitString(sString, ","));
	sString = "How,many,splits,now";
	LOGD << TMC::Narrate(TMC::SplitString(sString, ",", 2));
	LOGD << TMC::Narrate(TMC::SplitString(sString, ",", 5));
	LOGD << TMC::Narrate(TMC::RSplitString(sString, ",", 2));
	LOGD << TMC::Narrate(TMC::RSplitString(sString, ",", 5));
	LOGD << __func__;
	LOGD << "Narrate_Collection(cSet2):" << TMC::Narrator::Narrate_Collection(cSet2);
	LOGD << "Narrate_Collection(cSet2, StringizeInt):" << TMC::Narrator::Narrate_Collection(cSet2, StringizeInt);
	LOGD << "Narrate_Collection(c2dSet,..):" << TMC::Narrator::Narrate_Collection(c2dSet, TMC::Narrator::Narrate_Collection< std::set<int>>);
	LOGD << "Narrate_2dCollection(c2dSet):" << TMC::Narrator::Narrate_2dCollection(c2dSet);
	std::map<int, std::string> cMap;
	cMap.insert({ 14,"c" });
	cMap.insert({ 140,"rthdt" });
	cMap.insert({ -3,"limbo" });
	LOGD << "Narrate_Collection(cMap):" << TMC::Narrator::Narrate_Collection(cMap);
	sString = "look,";
	LOGD << "SplitAlmostEmpty:" << TMC::Narrate(TMC::SplitString(sString,","));
	sString = "JustMe";
	LOGD << "SplitJustMe:" << TMC::Narrate(TMC::SplitString(sString, ","));
	sString = "look,";
	LOGD << "RSplitAlmostEmpty:" << TMC::Narrate(TMC::RSplitString(sString, ","));
	sString = "JustMe";
	LOGD << "RSplitJustMe:" << TMC::Narrate(TMC::RSplitString(sString, ","));

#pragma endregion
}
