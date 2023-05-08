#pragma once

#include <Windows.h>
#include <wmistr.h>

#include "TraceWrappers.h"

// https://learn.microsoft.com/en-us/windows/win32/api/_etw/

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
	void* m_pTraceLoggerHandle;
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
	void* m_pTraceLoggerHandle;
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

inline __int64 __fastcall Trace_RequestAddress(
	WMIDPREQUESTCODE RequestCode,
	TraceGuidRequestContext_t* RequestContext,
	ULONG* BufferSize,
	PVOID Buffer)
{
	int v5; // ecx
	__int64 result; // rax
	void* TraceLoggerHandle; // rdi
	ULONG TraceEnableFlags; // eax
	UCHAR TraceEnableLevel; // si

	*BufferSize = 0;
	v5 = RequestCode - 4;
	if (v5)
	{
		if (v5 != 1)
			return 0x57;

		TraceLoggerHandle = 0;
		TraceEnableFlags = 0;
		TraceEnableLevel = 0;
	}
	else
	{
		TraceLoggerHandle = GetTraceLoggerHandle(Buffer);
		TraceEnableLevel = GetTraceEnableLevel(TraceLoggerHandle);
		TraceEnableFlags = GetTraceEnableFlags(TraceLoggerHandle);
	}
	if ((RequestContext->m_UnknownFlags & 2) != 0)
	{
		if (RequestContext->m_pTraceLoggerHandle)
			RequestContext = RequestContext->m_pTraceLoggerHandle;
	}
	RequestContext->m_nTraceEnableFlags = TraceEnableFlags;
	result = 0;
	RequestContext->m_pTraceLoggerHandle = TraceLoggerHandle;
	RequestContext->m_TraceEnableLevel = TraceEnableLevel;
	return result;
}
