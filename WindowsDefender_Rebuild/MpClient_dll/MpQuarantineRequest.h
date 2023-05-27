#pragma once
#include "BuildNumber.h"
#include "TraceRequest.h"
#include "TraceWrappers.h"

__int64 __fastcall MpQuarantineRequest(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  int v5; // ebx
  TraceGuidRequestContext_t *v11; // rcx
  USHORT v12; // dx
  __int64 v13; // r8
  int v14; // eax

  v5 = 0;
  if ( !a1 || !a2 )
  {
    v11 = g_pTraceGuidRequestContext;
    if ( g_pTraceGuidRequestContext == &g_pTraceGuidRequestContext
      || (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) == 0 )
    {
      return E_INVALIDARG;
    }
    v12 = 10;
    goto LABEL_37;
  }
  if ( *a1 == 1 )
  {
    if ( a3 > 2 )
    {
      v11 = g_pTraceGuidRequestContext;
      if ( g_pTraceGuidRequestContext == &g_pTraceGuidRequestContext
        || (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) == 0 )
      {
        return E_INVALIDARG;
      }
      v12 = 12;
LABEL_37:
      Trace_TraceMessageWrapper_1(v11->m_hTraceLoggerHandle, v12, &stru_75B8A1980);
      return E_INVALIDARG;
    }
    v13 = a5;
    if ( a3 )
    {
      if ( !a5 )
        goto LABEL_22;
    }
    else if ( !a5 )
    {
      v11 = g_pTraceGuidRequestContext;
      if ( g_pTraceGuidRequestContext == &g_pTraceGuidRequestContext
        || (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) == 0 )
      {
        return E_INVALIDARG;
      }
      v12 = 13;
      goto LABEL_37;
    }
    v5 = sub_75B80C950(*(a1 + 8), a2, a5);
    if ( v5 < 0 )
    {
      if ( g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
        && (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0 )
      {
        _mm_lfence();
        Trace_TraceMessageWrapper_0(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 0xEu, &stru_75B8A1980, v5);
      }
      return v5;
    }
LABEL_22:
    if ( a3 )
    {
      if ( a3 == 1 )
      {
        v14 = sub_75B80CBDC(*(a1 + 8), a2, v13);
      }
      else
      {
        if ( a3 != 2 )
        {
          v5 = E_INVALIDARG;
          goto LABEL_30;
        }
        v14 = sub_75B80CA90(*(a1 + 8), a2, a2, a4);
      }
      v5 = v14;
    }
    if ( v5 >= 0 )
      return v5;
LABEL_30:
    if ( g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
      && (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0 )
    {
      _mm_lfence();
      sub_75B80235C(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 15i64, &stru_75B8A1980, a3, v5);
    }
    return v5;
  }
  if ( g_pTraceGuidRequestContext != &g_pTraceGuidRequestContext
    && (g_pTraceGuidRequestContext->m_nTraceEnableFlags & 1) != 0 )
  {
    Trace_TraceMessageWrapper_1(g_pTraceGuidRequestContext->m_hTraceLoggerHandle, 0xBu, &stru_75B8A1980);
  }
  return E_INVALIDARG;
}