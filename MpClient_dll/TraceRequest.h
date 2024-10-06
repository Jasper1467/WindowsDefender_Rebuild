#pragma once
#include "BuildNumber.h"
#include <evntrace.h>

/*
 * NOTE: This only seems to be used in Trace_RequestAddress, which is also where it's initialized;
 * There is a similar struct used in sub_75B829300, the offsets are very different.
 * The struct from sub_75B829300 is bigger, and does more.
 * sub_75B829300:
 * MpClient.dll 48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 56 41 57 48 83 EC 20 45
 */
struct TraceGuidRequestContext_t
{
	char pad[8];
	PTRACE_GUID_REGISTRATION m_pTraceGuidReg;
	TRACEHANDLE m_hTraceLoggerHandle;
	char pad1[1];
	UCHAR m_TraceEnableLevel;
	UCHAR m_UnknownFlags;
	ULONG m_nTraceEnableFlags;
	// I don't know if there are more members
};

/*
 * NOTE: This seems to not be used very much, It seems to get initialized in sub_75B829300.
 *
 */
struct sub_75B829300_TraceGuidRequestContext_t
{
	char pad[8];
	TRACEHANDLE m_hTraceLoggerHandle;
	char pad1[16];
	ULONG m_nTraceEnableFlags;
	bool m_bUnknownBool;
	char pad2[3];
	UCHAR m_TraceEnableLevel;
	UCHAR m_UnknownChar;
	BYTE m_UnknownBytes[2];
	void* m_UnknownArray;
	void* m_UnknownArray2;
	int m_nUnknownInt;
	// I don't know if there are more members
};

// Is only used in sub_75B8015D0, This is the RequestContext argument of RegisterTraceGuidsW
inline TraceGuidRequestContext_t* g_pSub_75B8015D0_TraceGuidRequestContext = nullptr;

// This is a copy of g_pSub_75B8015D0_TraceGuidRequestContext; it is used in 3473 functions
inline TraceGuidRequestContext_t* g_pTraceGuidRequestContext = g_pSub_75B8015D0_TraceGuidRequestContext;