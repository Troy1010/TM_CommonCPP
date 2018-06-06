#include "pch.h"

#include "TM_CommonCPP/Narrate.h"
#include <set>
#include <vector>
//#include "../"

//Acceptance test
TEST(TestCaseName, TestName) {

	std::set<int> cSet;
	cSet.insert(5);
	cSet.insert(99);
	cSet.insert(36);
	std::cout << IsCollection<std::vector<int>>::value << std::endl; //true
	std::cout << IsCollection<std::set<int>>::value << std::endl;
	//std::cout << "cSet:" + Narrate(cSet);
	/*
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);*/
}