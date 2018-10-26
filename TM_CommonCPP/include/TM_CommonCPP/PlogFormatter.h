#pragma once
#include "plog/Log.h"

namespace plog
{
	class MyFormatter
	{
	public:
		static util::nstring header();
		static util::nstring format(const Record& record);
	};
}
