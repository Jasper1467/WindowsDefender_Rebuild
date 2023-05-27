#pragma once
#include <Windows.h>

#include "TraceRequest.h"
#include "TraceWrappers.h"

/*
 * .rdata:000000075B8ADF58 ; const GUID g_ServiceGuid
 * .rdata:000000075B8ADF58 g_ServiceGuid dd 5FC4DFE5h            ; Data1
 * .rdata:000000075B8ADF58                                         ; DATA XREF: sub_75B86AD24+39↑o
 * .rdata:000000075B8ADF58                                         ; sub_75B86ADA0+41↑o ...
 * .rdata:000000075B8ADF58                 dw 3054h                ; Data2
 * .rdata:000000075B8ADF58                 dw 394Ch                ; Data3
 * .rdata:000000075B8ADF58                 db 6Ah, 11h, 6Ch, 0C3h, 19h, 50h, 0A6h, 0CAh; Data4
 */
inline GUID g_ServiceGuid = GUID(
	0x5FC4DFE5, // Data1
	0x3054, // Data2
	0x394C, // Data3
	{ 0x6A, 0x11, 0x6C, 0x0C3, 0x19, 0x50, 0x0A6, 0x0CA } // Data4
);

inline void __fastcall ChangeConfigAndStartService(SC_HANDLE hSCManager, const WCHAR* wszServiceName)
{
	SC_HANDLE Service; // rax
	SC_HANDLE v3; // rdi
	int v4; // eax
	int UnknownLastError; // eax
	TraceGuidRequestContext_t* v6; // rcx
	USHORT Msg; // dx

	Service = OpenServiceW(hSCManager, wszServiceName, PROCESS_VM_READ | PROCESS_CREATE_THREAD);
	v3 = Service;
	if (Service)
	{
		if (ChangeServiceConfigW(Service, -1, SERVICE_AUTO_START, -1, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr))
		{
			if (StartServiceW(v3, 0, nullptr))
				goto LABEL_14;
			UnknownLastError = GetUnknownLastError();
			v6 = g_pTraceGuidRequestContext;
			if (g_pTraceGuidRequestContext == &g_pTraceGuidRequestContext
				|| (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) == 0)
			{
				goto LABEL_14;
			}
			Msg = '-';
		}
		else
		{
			UnknownLastError = GetUnknownLastError();
			v6 = g_pTraceGuidRequestContext;
			if (g_pTraceGuidRequestContext == &g_pTraceGuidRequestContext
				|| (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) == 0)
			{
				goto LABEL_14;
			}
			Msg = ',';
		}
		Trace_TraceMessageWrapper_0(v6->m_hTraceLoggerHandle, Msg, &g_ServiceGuid, UnknownLastError);
	LABEL_14:
		CloseServiceHandle(v3);
		return;
	}
	v4 = GetUnknownLastError();
	if (g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
		&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0)
	{
		Trace_TraceMessageWrapper_0(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 0x2Bu, &g_ServiceGuid, v4);
	}
}