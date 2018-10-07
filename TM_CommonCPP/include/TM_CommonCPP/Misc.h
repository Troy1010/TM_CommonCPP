#pragma once

#include <string>

#ifdef TMCOMMONCPP_EXPORTS
#define TMCommonCPP_API __declspec(dllexport)   
#else  
#define TMCommonCPP_API __declspec(dllimport)   
#endif 

std::string TMCommonCPP_API to_string_hex(int iInt);
std::string TMCommonCPP_API string_repeat(int n, std::string s);
std::string TMCommonCPP_API Hello();
