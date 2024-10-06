#pragma once

#include <Windows.h>
#include <wmistr.h>
#include <evntrace.h>

#include "TraceRequest.h"
#include "TraceWrappers.h"

// https://learn.microsoft.com/en-us/windows/win32/api/_etw/


inline __int64 __fastcall Trace_RequestAddress(
	WMIDPREQUESTCODE RequestCode,
	TraceGuidRequestContext_t* RequestContext,
	ULONG* BufferSize,
	PVOID Buffer)
{
	int v5; // ecx
	// rax
	TRACEHANDLE TraceLoggerHandle; // rdi
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
		if (RequestContext->m_hTraceLoggerHandle)
			RequestContext = RequestContext->m_hTraceLoggerHandle;
	}

	RequestContext->m_nTraceEnableFlags = TraceEnableFlags;
	RequestContext->m_hTraceLoggerHandle = TraceLoggerHandle;
	RequestContext->m_TraceEnableLevel = TraceEnableLevel;
	return 0;
}
