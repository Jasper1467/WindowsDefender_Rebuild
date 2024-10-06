#pragma once
#include "BuildNumber.h"
#include "TraceRequest.h"
#include "TraceWrappers.h"
#include "UnknownTraceReturn.h"

//.rdata:000000075B8A2B78 g_OfflineScanGuid dd 860B9559h            ; Data1
//.rdata:000000075B8A2B78                                         ; DATA XREF: MpOfflineScanInstall+33↑o
// .rdata:000000075B8A2B78                                         ; MpOfflineScanInstall+70↑o ...
// .rdata:000000075B8A2B78                 dw 0E413h               ; Data2
// .rdata:000000075B8A2B78                 dw 3D66h                ; Data3
//.rdata:000000075B8A2B78                 db 0D2h, 0BDh, 28h, 31h, 0F7h, 0BEh, 0DEh, 46h; Data4
inline GUID g_OfflineScanGuid = GUID(
	0x860B9559, // Data1
	0x0E413, // Data2
	0x3D66, // Data3
	{ 0xD2, 0x0BD, 0x28, 0x31, 0x0F7, 0x0BE, 0x0DE, 0x46 } // Data4
);

__int64 __fastcall MpOfflineScanStatusQuery(UnknownStruct_t* a1, __int64 a2, _DWORD* a3)
{
	unsigned int Pointer; // ebx
	USHORT v6; // dx
	int v7; // [rsp+40h] [rbp+8h] BYREF
	__int64 v8; // [rsp+58h] [rbp+20h] BYREF

	v8 = 0i64;
	v7 = 0;
	if (a1 && a3)
	{
		if (a1->m_nUnknownInt != 1)
		{
			if (g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
				&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0)
			{
				Trace_TraceMessageWrapper_1(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 0xFu, &g_OfflineScanGuid);
			}
			return E_HANDLE;
		}
		Pointer = EndMutex(a1->m_pHandles, &v8);
		if ((Pointer & 0x80000000) == 0)
		{
			Pointer = NdrClientCall3(&pProxyInfo, 0x6Du, 0i64, v8, a3, &v7).Pointer;
			if (v7)
				Pointer = v7 | 0x80010000;
			if ((Pointer & 0x80000000) == 0)
			{
				if (g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
					&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 4) != 0)
				{
					_mm_lfence();
					sub_75B80235C(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 18i64, &g_OfflineScanGuid, Pointer, *a3);
				}
				return Pointer;
			}
			if (g_pTraceGuidRequestContext == &g_pTraceGuidRequestContext
				|| (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) == 0)
			{
				return Pointer;
			}
			v6 = 17;
		}
		else
		{
			if (g_pTraceGuidRequestContext == &g_pTraceGuidRequestContext
				|| (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) == 0)
			{
				return Pointer;
			}
			v6 = 16;
		}
		_mm_lfence();
		Trace_TraceMessageWrapper_0(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, v6, &g_OfflineScanGuid, Pointer);
		return Pointer;
	}
	if (g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
		&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0)
	{
		Trace_TraceMessageWrapper_1(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 0xEu, &g_OfflineScanGuid);
	}
	return E_INVALIDARG;
}