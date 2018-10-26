#pragma once
#include "stdafx.h"
#include "TM_CommonCPP/PlogFormatter.h"

namespace plog
{
	class MyFormatter
	{
	public:
		static util::nstring header() // This method returns a header for a new file. In our case it is empty.
		{
			return util::nstring();
		}

		static util::nstring format(const Record& record) // This method returns a string from a record.
		{
			util::nostringstream ss;
			ss << record.getMessage() << "\n"; // Produce a simple string with a log message.

			return ss.str();
		}
	};
}
