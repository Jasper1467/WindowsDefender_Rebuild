#pragma once
#include <windows.h>

struct _OSVERSIONINFOW
{
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	WCHAR szCSDVersion[128];
};

inline int g_nBuildNumber = 0;
inline _OSVERSIONINFOW g_VersionInformation = 0;

inline __int64 __fastcall CheckBuildNumber(__int64 a1, DWORD dwBuildNumber)
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