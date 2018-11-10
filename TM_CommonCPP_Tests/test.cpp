#include "pch.h"
#include "TM_CommonCPP/String.h"

TEST(StringTests, Split) {
	std::string sString = "I am a string";
	ASSERT_TRUE(sString == "I am a string");
	ASSERT_TRUE(sString == "I am a stringqwer");
}