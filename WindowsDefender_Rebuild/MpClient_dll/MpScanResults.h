#pragma once
#include "TraceRequest.h"
#include "TraceWrappers.h"

/*
 * g_MpScanGuid  dd 0B25ADC58h           ; Data1
 * .rdata:000000075B8A1930                                         ; DATA XREF: MpScanStartEx_0+72↑o
 * .rdata:000000075B8A1930                                         ; MpScanStartEx_0+C8↑o ...
 * .rdata:000000075B8A1930                 dw 22D8h                ; Data2
 * .rdata:000000075B8A1930                 dw 3E9Eh                ; Data3
 * .rdata:000000075B8A1930                 db 0Fh, 3Ah, 56h, 6Ah, 69h, 64h, 23h, 0A7h; Data4
 */
const GUID g_MpScanGuid = {
	0x0B25ADC58, // Data1
	0x22D8, // Data2
	0x3E9E, // Data3
	{ 0x0F, 0x3A, 0x56, 0x6A, 0x69, 0x64, 0x23, 0x0A7 } // Data4
};

const int unk_75B8A34A2 = 0;
const int unk_75B899A20 = 4;

const MIDL_STUBLESS_PROXY_INFO g_pProxyInfo = { off_75B896D80, unk_75B8A34A2,
	unk_75B8A5710, unk_75B8A5848, 2, unk_75B899A20 };

// SIG MpClient.dll 48 89 5C 24 10 48 89 6C 24 18 48 89 74 24 20 57 48 83 EC 30 48
inline __int64 __fastcall MpScanResult(__int64 a1, void* a2)
{
	TraceGuidRequestContext_t* v4; // rcx
	USHORT v5; // dx
	int Pointer; // ebx
	int v8; // [rsp+40h] [rbp+8h] BYREF

	v4 = g_pTraceGuidRequestContext;
	if (g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
		&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 4) != 0)
	{
		Trace_TraceMessageWrapper_1(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 0x1Au,
			&g_MpScanGuid);

		v4 = g_pTraceGuidRequestContext;
	}
	v8 = 0;
	if (!a1)
	{
		if (v4 == g_pTraceGuidRequestContext || (v4->m_nTraceEnableFlags & 1) == 0)
			return 0x80070057;
		v5 = 27;

		Trace_TraceMessageWrapper_1(v4->m_hTraceLoggerHandle, v5, &g_MpScanGuid);
		return 0x80070057;
	}
	if (a1 == 2)
	{
		if (!a2)
		{
			if (v4 == g_pTraceGuidRequestContext || (v4->m_nTraceEnableFlags & 1) == 0)
				return 0x80070057;
			v5 = 29;
			Trace_TraceMessageWrapper_1(v4->m_hTraceLoggerHandle, v5, &g_MpScanGuid);
			return 0x80070057;
		}

		memset(a2, 0, 0x90ui64);
		Pointer = NdrClientCall3(&pProxyInfo, 8u, nullptr, *(*(a1 + 8) + 32i64), a2, &v8).Pointer;
		if (v8)
			Pointer = v8 | 0x80010000;
		if (Pointer < 0
			&& g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
			&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0)
		{
			_mm_lfence();
			Trace_TraceMessageWrapper_0(g_pTraceGuidRequestContext->m_hTraceLoggerHandle,
				0x1Eu, &g_MpScanGuid, Pointer);
		}
		return Pointer;
	}

	if (v4 != g_pTraceGuidRequestContext && (v4->m_nTraceEnableFlags & 1) != 0)
		Trace_TraceMessageWrapper_1(v4->m_hTraceLoggerHandle, 0x1Cu, &g_MpScanGuid);

	return 0x80070006;

}