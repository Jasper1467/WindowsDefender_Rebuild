#pragma once
#include <intrin.h>

#include "MpScanResults.h"
#include "TraceRequest.h"
#include "TraceWrappers.h"

inline __int64 __fastcall MpScanControl(__int64 a1, unsigned int a2)
{
  TraceGuidRequestContext_t *v4; // rcx
  USHORT v5; // dx
  __int64 v7; // rcx
  int Pointer; // ebx
  __int64 v9; // rdx
  int v10; // [rsp+50h] [rbp+8h] BYREF
  __int64 v11; // [rsp+60h] [rbp+18h] BYREF

  v4 = g_pTraceGuidRequestContext;
  if ( g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
    && (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 4) != 0 )
  {
    Trace_TraceMessageWrapper_1(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 0x13u, &g_MpScanGuid);
    v4 = g_pTraceGuidRequestContext;
  }
  v10 = 0;
  if ( !a1 )
  {
    if ( v4 == &g_pTraceGuidRequestContext || (v4->m_nTraceEnableFlags & 1) == 0 )
      return E_INVALIDARG;
    v5 = 20;
LABEL_17:
    Trace_TraceMessageWrapper_1(v4->m_hTraceLoggerHandle, v5, &g_MpScanGuid);
    return E_INVALIDARG;
  }
  if ( (*a1 - 1) <= 1 )
  {
    if ( a2 > 2 )
    {
      if ( v4 == &g_pTraceGuidRequestContext || (v4->m_nTraceEnableFlags & 1) == 0 )
        return E_INVALIDARG;
      v5 = 22;
      goto LABEL_17;
    }
    _mm_lfence();
    v7 = *(a1 + 8);
    if ( *a1 == 2 )
    {
      Pointer = NdrClientCall3(&pProxyInfo, 9u, nullptr, *(v7 + 32), a2, &v10).Pointer;
      if ( v10 )
        Pointer = v10 | 0x80010000;
      if ( Pointer >= 0
        || g_pTraceGuidRequestContext == &g_pTraceGuidRequestContext
        || (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) == 0 )
      {
        return Pointer;
      }
      v9 = 23i64;
    }
    else
    {
      Pointer = EndMutex(v7, &v11);
      if ( Pointer < 0 )
      {
        if ( g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
          && (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0 )
        {
          _mm_lfence();
          Trace_TraceMessageWrapper_0(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 0x18u, &g_MpScanGuid, Pointer);
        }
        return Pointer;
      }
      Pointer = NdrClientCall3(&pProxyInfo, 0xAu, nullptr, v11, a2, &v10).Pointer;
      if ( v10 )
        Pointer = v10 | 0x80010000;
      if ( Pointer >= 0
        || g_pTraceGuidRequestContext == &g_pTraceGuidRequestContext
        || (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) == 0 )
      {
        return Pointer;
      }
      v9 = 25i64;
    }
    _mm_lfence();
    sub_75B80235C(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, v9, &g_MpScanGuid, a2, Pointer);
    return Pointer;
  }
  if ( v4 != &g_pTraceGuidRequestContext && (v4->m_nTraceEnableFlags & 1) != 0 )
    Trace_TraceMessageWrapper_1(v4->m_hTraceLoggerHandle, 0x15u, &g_MpScanGuid);
  return E_HANDLE;
}
