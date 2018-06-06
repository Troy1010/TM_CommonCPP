// TM_CommonCPP_ConsoleTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "TM_CommonCPP/Narrate.h"
#include <set>
#include <vector>
#include <iostream>



int main()
{
	std::set<int> cSet;
	cSet.insert(5);
	cSet.insert(99);
	cSet.insert(36);
	std::cout << IsCollection<std::vector<int>>::value << std::endl; //true
	std::cout << IsCollection<std::set<int>>::value << std::endl;
	std::cout << "23:" + Narrate(23);
	std::cin.get();
    return 0;
}
