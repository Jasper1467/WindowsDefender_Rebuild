#pragma once
#include <cstdlib>

namespace MorroCommon
{
	class ILockedCertCheck
	{
	public:
		ILockedCertCheck(bool bFree = false)
		{
			if (bFree)
				free(this);
		}
	};

	class CLockEntireFile
	{
	public:
		CLockEntireFile(bool bFree = false)
		{
			this->m_pLockedCertCheck = new ILockedCertCheck(bFree);
			if (bFree)
				free(this);
		}

		ILockedCertCheck* m_pLockedCertCheck;
	};

	class CLockedCertCheckImpl
	{
	public:
		CLockedCertCheckImpl(bool bFree = false)
		{
			this->m_pLockEntireFile = new CLockEntireFile(bFree);
			this->m_pLockedCertCheck = new ILockedCertCheck(bFree);

			if (bFree)
				free(this);
		}

		ILockedCertCheck* m_pLockedCertCheck;
		CLockEntireFile* m_pLockEntireFile;
	};

	class CCertCheckFactory
	{
	public:
		CCertCheckFactory()
		{
			auto v0 = malloc(0x18u);
			if (v0)
			{
				this->m_nUnknownInt = -1;
				this->m_pLockCertCheckImpl = new CLockedCertCheckImpl();
				this->m_pLockEntireFile = new CLockEntireFile();
			}
		}

		CLockedCertCheckImpl* m_pLockCertCheckImpl;
		CLockEntireFile* m_pLockEntireFile;
		int m_nUnknownInt;
	};
}
