#pragma once
#include <tuple>

#define COUNT_ARGS(...) std::tuple_size<decltype(std::make_tuple(__VA_ARGS__))>::value
