#pragma once
#include <cstdint>
#include <cstring>

namespace MorroCommon
{
	class CCertCheck
	{
	private:
    static long __cdecl HrWinVerifyTrust(struct HWND__* p1, struct _GUID* p2, struct _WINTRUST_DATA* wtd)
    {
        int64_t v3;
        long v1; // rax
        uint32_t v2; // rbx
        int32_t v4; // rax

        v1 = __imp_WinVerifyTrust(p1, p2, wtd);
        if (v1 != 0) {
            if (v1 < 0) {
                v2 = v1;
            }
            else {
                if (v1 > 0) {
                    v3 = (uint32_t)(uint16_t)v1 | 0x80070000;
                }
                else {
                    v3 = v1;
                }
                v4 = (int32_t)v3;
                if ((int32_t)v3 >= 0) {
                    v4 = -2147467259;
                }
                v2 = (uint32_t)v4;
            }
            if (wtd->dwStateAction == 1) {
                MorroCommon::CCertCheck::CloseWinVerifyTrust(wtd);
            }
            if (&WPP_GLOBAL_Control != WPP_GLOBAL_Control && (uint8_t)(*(WPP_GLOBAL_Control + 28) & 0x1) != 0) {
                WPP_SF_d(*(WPP_GLOBAL_Control + 16), 10, &WPP_85f6ef443cd634233fb343557d45d487_Traceguids, v2);
            }
            v1 = v2;
        }
        return v1;
    }


		 void CloseWinVerifyTrust(_WINTRUST_DATA& wtd)
		 {
             int64_t v1; // [rsp-72]
             uint32_t local_0x28; // [rsp-40]
             uint32_t local_0x24; // [rsp-36]
             uint32_t local_0x20; // [rsp-32]
             uint32_t local_0x1C; // [rsp-28]
             uint64_t local_0x18; // [rsp-24]
             long v2; // rax

             if (wtd != 0) {
                 local_0x18 = __security_cookie ^ &v1;
                 local_0x28 = 11191659;
                 local_0x24 = 298896708;
                 local_0x20 = (uint32_t)18446744072635859596;
                 local_0x1C = (uint32_t)18446744073417376335;
                 if (wtd->hWVTStateData != 0) {
                     wtd->dwStateAction = 2;
                     v2 = this->HrWinVerifyTrust(0, &local_0x28, wtd);
                     if (v2 < 0 && &WPP_GLOBAL_Control != WPP_GLOBAL_Control && (uint8_t)(*(WPP_GLOBAL_Control + 28) & 0x1) != 0) {
                         WPP_SF_(*(WPP_GLOBAL_Control + 16), 14, &WPP_85f6ef443cd634233fb343557d45d487_Traceguids);
                     }
                     memset(wtd, 0, 80);
                 }
                 __security_check_cookie(local_0x18 ^ &v1);
             }
         }
	};
}
