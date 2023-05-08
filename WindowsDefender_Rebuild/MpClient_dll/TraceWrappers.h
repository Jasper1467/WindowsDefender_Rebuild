#pragma once
#include <emmintrin.h>
#include <Windows.h>

#include "TraceRequest.h"

inline __int64 GetUnknownLastError()
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

// SIG: MpClient.dll 48 83 EC 58 45 33 DB
inline ULONG Trace_TraceMessageWrapper(TRACEHANDLE LoggerHandle, USHORT a2, const GUID* a3, const wchar_t* a4, ...)
{
	__int64 v5; // rax
	__int64 v6; // rcx
	const wchar_t* v7; // rax
	va_list va; // [rsp+80h] [rbp+28h] BYREF

	va_start(va, a4);
	if (a4)
	{
		v5 = -1;
		do
			++v5;
		while (a4[v5]);
		v6 = 2 * v5 + 2;
	}
	else
	{
		v6 = 10;
	}
	v7 = L"NULL";
	if (a4)
		v7 = a4;

	return TraceMessage(LoggerHandle, 0x2Bu, a3, a2, v7, v6, va, 4, 0);
}

// SIG: MpClient.dll 4C 8B DC 45 89 4B 20 48 83 EC 48
inline ULONG __fastcall Trace_TraceMessageWrapper_0(TRACEHANDLE LoggerHandle, USHORT MessageNumber,
	const GUID* MessageGuid, int a4)
{
	int v5; // [rsp+68h] [rbp+20h] BYREF
	v5 = a4;
	return TraceMessage(LoggerHandle, 0x2Bu, MessageGuid, MessageNumber, &v5, 4, 0);
}

inline ULONG __fastcall Trace_TraceMessageWrapper_1(TRACEHANDLE LoggerHandle, USHORT MessageNumber,
	const GUID* MessageGuid)
{
	return TraceMessage(LoggerHandle, 0x2Bu, MessageGuid, MessageNumber, 0);
}

// SIG: MpClient.dll 48 89 5C 24 08 57 48 83 EC 30 41
inline __int64 __fastcall Trace_RegSetValueWrapper(HKEY hKey, LPCWSTR lpValueName, DWORD dwType,
	__int64 cbData, BYTE* lpData)
{
	__int64 result; // rax
	LSTATUS lpStatus; // ebx
	BYTE* lpDataa; // [rsp+20h] [rbp-18h]

	if (cbData != cbData) // Bruh ida...
		return 0x80070057;

	lpStatus = RegSetValueExW(hKey, lpValueName, 0, dwType, lpData, cbData);
	if (!lpStatus)
		return 0i64;
	if (g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
		&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0)
	{
		LODWORD(lpDataa) = lpStatus;
		Trace_TraceMessageWrapper(
			g_pTraceGuidRequestContext->m_hTraceLoggerHandle,
			0x18u,
			&stru_75B8AF638,
			lpValueName,
			lpDataa);
	}
	result = lpStatus | 0x80070000;
	if (lpStatus <= 0)
		result = lpStatus;
	if (result >= 0)
		return 0i64;
	_mm_lfence();
	return result;
}

/*
 * .rdata:000000075B8AF390 g_WrapperGuid   dd 61FC0896h            ; Data1
 * .rdata:000000075B8AF390                                         ; DATA XREF: sub_75B873368+51↑o
 * .rdata:000000075B8AF390                                         ; sub_75B8757CC+30↑o ...
 * .rdata:000000075B8AF390                 dw 1557h                ; Data2
 * .rdata:000000075B8AF390                 dw 391Fh                ; Data3
 * .rdata:000000075B8AF390                 db 0CFh, 56h, 8Bh, 5Eh, 6Ch, 44h, 1Eh, 0CCh; Data4
 */
inline const GUID g_WrapperGuid = GUID(
	0x61FC0896, // Data1
	0x1557, // Data2
	0x391F, // Data3
	{ 0xCF, 0x56, 0x8B, 0x5E, 0x6C, 0x44, 0x1E, 0x0CC } // Data4
);

/*
 * .rdata:000000075B8AF3E0 g_WrapperGuid_0 dd 14D7121Dh            ; Data1
 * .rdata:000000075B8AF3E0                                         ; DATA XREF: QueryPerformanceFrequencyWrapper+36↑o
 * .rdata:000000075B8AF3E0                 dw 5F06h                ; Data2
 * .rdata:000000075B8AF3E0                 dw 3670h                ; Data3
 * .rdata:000000075B8AF3E0                 db 0DCh, 23h, 75h, 9Ah, 0E9h, 0BEh, 7Eh, 2Bh; Data4
 */
inline const GUID g_WrapperGuid_0 = GUID(
	0x14D7121D, // Data1
	0x5F06, // Data2
	0x3670, // Data3
	{ 0x0DC, 0x23, 0x75, 0x9A, 0x0E9, 0x0BE, 0x7E, 0x2B }// Data 4
);

inline __int64 __fastcall Trace_LoadLibraryWrapper(HMODULE* hLibrary, LPCWSTR lpLibFileName)
{
	HMODULE LibraryW; // rax
	unsigned int UnknownLastError; // eax
	unsigned int v6; // ebx
	int v8; // [rsp+20h] [rbp-18h]

	if (g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
		&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 4) != 0)
	{
		sub_75B8022FC(g_pTraceGuidRequestContext->m_hTraceLoggerHandle);
	}
	LibraryW = LoadLibraryW(lpLibFileName);
	*hLibrary = LibraryW;
	if (LibraryW)
		return 0i64;
	UnknownLastError = GetUnknownLastError();
	v6 = UnknownLastError;
	if (g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
		&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0)
	{
		v8 = UnknownLastError;
		Trace_TraceMessageWrapper(
			g_pTraceGuidRequestContext->m_hTraceLoggerHandle,
			0x15u,
			&g_WrapperGuid,
			lpLibFileName,
			v8);
	}
	return v6;
}

inline LARGE_INTEGER Trace_QueryPerformanceFrequencyWrapper()
{
	signed int LastError; // eax
	int v1; // r9d
	LARGE_INTEGER Frequency; // [rsp+30h] [rbp+8h] BYREF

	if (QueryPerformanceFrequency(&Frequency))
		return Frequency;

	LastError = GetLastError();
	if (g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
		&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0)
	{
		v1 = LastError | 0x80070000;
		if (LastError <= 0)
			v1 = LastError;
		Trace_TraceMessageWrapper_0(g_pTraceGuidRequestContext->m_hTraceLoggerHandle,
			0xAu, &g_WrapperGuid_0, v1);
	}

	return 1;
}

// SIG: MpClient.dll 48 85 C9 74 4D 48 89 4C 24 08 48 83 EC 28 48 8D 4C 24 30 FF 15 ?? ?? ?? ?? 85 C0 74 31 48 8B 0D ?? ?? ?? ?? 48 8D 15 ?? ?? ?? ?? 48 3B CA 74 1E F6 41 1C 01 74 18 48 8B 49 10 4C 8D 05 ?? ?? ?? ?? BA 1E 00 00 00 44 8B C8 E8 ?? ?? ?? ?? 48 83 C4 28 C3
inline void __fastcall Trace_RpcSmDestroyClientContextWrapper(void* a1)
{
	int v1; // eax
	void* ContextHandle; // [rsp+30h] [rbp+8h] BYREF

	if (a1)
	{
		ContextHandle = a1;
		v1 = RpcSmDestroyClientContext(&ContextHandle);
		if (v1)
		{
			if (g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
				&& (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0)
			{
				Trace_TraceMessageWrapper_0(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 
					0x1Eu, &stru_75B8A1820, v1);
			}
		}
	}
}

// SIG: MpClient.dll 48 89 5C 24 08 57 48 83 EC 30 48 8B 42
__int64 __fastcall Trace_WaitForMultipleObjectsWrapper(__int64* a1, __int64 a2)
{
	__int64 result; // rax
	DWORD v5; // eax
	HANDLE Handles; // [rsp+20h] [rbp-18h] BYREF

	if (!*(a2 + 8))
		return 0x80070057;

	Handles = *(a2 + 8);
	v5 = WaitForMultipleObjects(1u, &Handles, 0, INFINITE);
	switch (v5)
	{
	case 0u:
		goto LABEL_9;
	case 1u:
		return 0x80004004;
	case 0x80u:
	LABEL_9:
		result = 0i64;
	LABEL_10:
		if (result == 020000040004)
			return result;
		break;
	case 0xFFFFFFFF:
		result = GetUnknownLastError();
		goto LABEL_10;
	}
	result = 0;
	*a1 = a2;
	return result;
}