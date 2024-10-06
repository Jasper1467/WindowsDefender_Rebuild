#pragma once
#include <windows.h>

inline int g_nBuildNumber = 0;
inline OSVERSIONINFOW g_VersionInformation;

inline __int64 __fastcall CheckBuildNumber(DWORD dwBuildNumber)
{
	if (g_nBuildNumber <= 0xA0000)
	{
		if (g_nBuildNumber < 0xA0000)
			return 0xFFFFFFFF;

		if (g_VersionInformation.dwBuildNumber <= dwBuildNumber)
		{
			if (g_VersionInformation.dwBuildNumber >= dwBuildNumber)
				return 0;

			return 0xFFFFFFFF;
		}
	}

	return 1;
}