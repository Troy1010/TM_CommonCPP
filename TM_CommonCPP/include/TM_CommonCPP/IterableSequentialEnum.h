#pragma once

#define IterableSequentialEnum(Name,...) \
enum Name { __VA_ARGS__ }; \
static const std::initializer_list<Name> Name##_List{ __VA_ARGS__ };
