#pragma once

namespace MpClient
{
	// Has 10 functions in rtti
	class CMpSampleHeaderContext
	{
	public:
		__fastcall CMpSampleHeaderContext(CMpSampleHeaderContext* thisptr)
		{
			// SIG: MpClient.dll 40 53 48 83 EC 30 48 C7 44 24 20 FE FF FF FF 48 8B D9 48 8D 15 ?? ?? ?? ?? B9 58 00 00 00 E8 ?? ?? ?? ?? 33 D2 48 85 C0 74 3
		}

		void __fastcall sub_75B830FD0(CMpSampleHeaderContext* thisptr,
			char a2 // Seems to be used as a flag
		)
		{
			// SIG: MpClient.dll 4C 8B DC 57 48 83 EC 40 49 C7 43 E8 FE FF FF FF 49 89 5B 08 49 89 73 18 8B F2 48 8B D9 48 8D 05 ?? ?? ?? ?? 48 89 01 48 8D 79 20 48 83 3F 00 0F 84 8B 00 00 00 83 64 24 58 00 49 8D 43 10 49 89 43 E0 49 89 7B D8 4C 8B 49 18 45 33 C0 41 8D 50 7A
		}

		int vtable;
		char pad[28];
		void* m_pContextHandle;
		// There are some more pointers that get MpFreeMemory'd in sub_75B830FD0
	};
}