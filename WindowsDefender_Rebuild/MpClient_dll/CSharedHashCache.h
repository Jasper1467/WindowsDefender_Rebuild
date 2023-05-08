#pragma once
#include <Windows.h>

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