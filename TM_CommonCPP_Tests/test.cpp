#include "pch.h"
#include "TM_CommonCPP/Narrate.h"
#include "TM_CommonCPP/Util_VariadicMacros.h"
#include "TM_CommonCPP/String.h"
#include <vector>

TEST(Narrate, NarrateAnInt) {
	int i = 2;
	EXPECT_EQ("2", TMC::Narrate(i));
}

TEST(Narrate, NarrateConstChar) {
	const char vCString[] = "qwer";
	EXPECT_EQ("qwer", TMC::Narrate(vCString));
}

TEST(Narrate, NarrateBool) {
	bool bBool = true;
	EXPECT_EQ("true", TMC::Narrate(bBool));
	bBool = false;
	EXPECT_EQ("false", TMC::Narrate(bBool));
}

TEST(Narrate, NarrateFloat) {
	float fFloat = 0.46f;
	EXPECT_EQ("0.46", TMC::Narrate(fFloat));
}

TEST(Util_VariadicMacros, CountArgs) {
	int iInt1 = 2;
	int iInt2 = 34;
	EXPECT_EQ(2, COUNT_ARGS(iInt1, iInt2));
}

TEST(String, Split) {
	std::string sString = "look^at^that^landscape";
	EXPECT_EQ("look", TMC::Str::Split(sString, "^")[0]);
	EXPECT_EQ("at", TMC::Str::Split(sString, "^")[1]);
	EXPECT_EQ("that", TMC::Str::Split(sString, "^")[2]);
	EXPECT_EQ("landscape", TMC::Str::Split(sString, "^")[3]);
}

TEST(String, Split_Empty) {
	std::string s = "am,,I,empty";
	EXPECT_EQ("am", TMC::Str::Split(s, ",")[0]);
	EXPECT_EQ("", TMC::Str::Split(s, ",")[1]);
	EXPECT_EQ("I", TMC::Str::Split(s, ",")[2]);
	EXPECT_EQ("empty", TMC::Str::Split(s, ",")[3]);
}

TEST(String, Split_Partial) {
	std::string s = "How,many,splits,now";
	std::vector<std::string> vSplitString = TMC::Str::Split(s, ",", 2);
	EXPECT_EQ("How", vSplitString[0]);
	EXPECT_EQ("many,splits,now", vSplitString[1]);
}

TEST(String, Split_Partial_Exclusive) {
	std::string s = "How,many,splits,now";
	std::vector<std::string> vSplitString = TMC::Str::Split(s, ",", 2, false);
	EXPECT_EQ("How", vSplitString[0]);
	EXPECT_EQ("many", vSplitString[1]);
}

TEST(String, Split_Partial_TooMany) {
	std::string s = "How,many,splits,now";
	std::vector<std::string> vSplitString = TMC::Str::Split(s, ",", 5);
	EXPECT_EQ("How", vSplitString[0]);
	EXPECT_EQ("many", vSplitString[1]);
	EXPECT_EQ("splits", vSplitString[2]);
	EXPECT_EQ("now", vSplitString[3]);
}

TEST(String, Split_Reverse) {
	std::string s = "How,many,splits,now";
	std::vector<std::string> vSplitString = TMC::Str::RSplit(s, ",");
	EXPECT_EQ("How", vSplitString[0]);
	EXPECT_EQ("many", vSplitString[1]);
	EXPECT_EQ("splits", vSplitString[2]);
	EXPECT_EQ("now", vSplitString[3]);
	vSplitString = TMC::Str::RSplit(s, ",", 2);
	EXPECT_EQ("How,many,splits", vSplitString[0]);
	EXPECT_EQ("now", vSplitString[1]);
}

TEST(String, Split_Double) {
	std::string s = "Double//the//split//capabilities";
	std::vector<std::string> vSplitString = TMC::Str::Split(s, "//");
	EXPECT_EQ("Double", vSplitString[0]);
	EXPECT_EQ("the", vSplitString[1]);
	EXPECT_EQ("split", vSplitString[2]);
	EXPECT_EQ("capabilities", vSplitString[3]);
	EXPECT_EQ(4, vSplitString.size());
}

TEST(String, Split_OneItem) {
	std::string s = "JustMe";
	std::vector<std::string> vSplitString = TMC::Str::RSplit(s, ",");
	EXPECT_EQ("JustMe", vSplitString[0]);
	EXPECT_EQ(1, vSplitString.size());
}

TEST(String, Replace) {
	std::string s = "Ther%e a%%r%%%e %%%l%ot%%%s of pe%rce%nt%ages% %h%e%re";
	std::string sReplacedString = TMC::Str::Replace(s, "%", "");
	EXPECT_EQ("There are lots of percentages here", sReplacedString);
}

