#pragma once
#include <Windows.h>

__int64 GetUnknownLastError()
{
	signed int LastError; // eax
	signed int v1; // ecx

	LastError = GetLastError();
	v1 = LastError | 0x80070000;
	if (LastError <= 0)
		v1 = LastError;
	if (v1 >= 0)

		return 0x80004005;

	return v1;
}

namespace MPClient
{

	class CSharedHashCache
	{
	public:

		// Incomplete
		char pad[16];
		HANDLE m_hFileMapping;
	};
}