#pragma once

#include <string>

#ifdef TMCOMMONCPP_EXPORTS
#define TMCommonCPP_API __declspec(dllexport)
#else
//#define TMCommonCPP_API __declspec(dllimport)
#define TMCommonCPP_API
#endif

std::string to_string_hex(int iInt);
std::string string_repeat(int n, std::string s);
std::string Hello();
