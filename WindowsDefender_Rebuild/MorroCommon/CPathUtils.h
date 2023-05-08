#pragma once

#include <Windows.h>

namespace MorroCommon
{
	class CPathUtils
	{
	public:
		// Index: 21
		bool IsExecutableFile(const WCHAR* wszString)
		{
			if (PathMatchSpecW(wszString, L"*.exe")
				|| PathMatchSpecW(wszString, L"*.com")
				|| PathMatchSpecW(wszString, L"*.scr"))
			{
				return true;
			}

			return false;
		}
	};
}