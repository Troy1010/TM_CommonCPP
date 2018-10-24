#pragma once

#include <string>
#include <vector>

std::string to_string_hex(int iInt);
std::string string_repeat(int n, std::string s);
std::string Hello();
std::vector<std::string> SplitString(std::string& sString, std::string& sDelimiter);
std::vector<std::string> SplitString(std::string& sString, const char* sDelimiter);
int IntFromString(std::string sString);
