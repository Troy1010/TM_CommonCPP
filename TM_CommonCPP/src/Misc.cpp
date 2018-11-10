#include "stdafx.h"
#include "TM_CommonCPP/Misc.h"
#include <sstream>
#include <algorithm>

namespace TMC
{
	int IntFromString(std::string sString)
	{
		int iTemp = 0;
		std::istringstream(sString) >> iTemp;
		return iTemp;
	}
}
