#pragma once

#include <Windows.h>

/*
.rdata:0000000180020ED8                   ; const MorroCommon::CWin32::`vftable'
.rdata:0000000180020ED8 40 51 01 80 01 00+??_7CWin32@MorroCommon@@6B@ dq offset MorroCommon__CWin32__CreateDirectoryW
.rdata:0000000180020ED8 00 00                                                     ; DATA XREF: sub_180016908+A9↑o
.rdata:0000000180020EE0 60 51 01 80 01 00+                dq offset MorroCommon__CWin32__CreateDialogParamW
.rdata:0000000180020EE8 A0 51 01 80 01 00+                dq offset MorroCommon__CWin32__LoadIconW
.rdata:0000000180020EF0 C0 51 01 80 01 00+                dq offset MorroCommon__CWin32__DestroyWindow
.rdata:0000000180020EF8 E0 51 01 80 01 00+                dq offset MorroCommon__CWin32__SendMessageW
.rdata:0000000180020F00 10 52 01 80 01 00+                dq offset MorroCommon__CWin32__PathFileExistsW
.rdata:0000000180020F08 30 52 01 80 01 00+                dq offset MorroCommon__CWin32__PathIsDirectoryW
.rdata:0000000180020F10 50 52 01 80 01 00+                dq offset MorroCommon__CWin32__GetTempPathW
.rdata:0000000180020F18 70 52 01 80 01 00+                dq offset MorroCommon__CWin32__GetTempFileNameW
.rdata:0000000180020F20 A0 52 01 80 01 00+                dq offset MorroCommon__CWin32__GetLastError
.rdata:0000000180020F28 C0 52 01 80 01 00+                dq offset MorroCommon__CWin32__GetModuleFileNameW
.rdata:0000000180020F30 E0 52 01 80 01 00+                dq offset MorroCommon__CWin32__CopyFileW
.rdata:0000000180020F38 00 53 01 80 01 00+                dq offset MorroCommon__CWin32__RegCreateKeyExW
.rdata:0000000180020F40 80 53 01 80 01 00+                dq offset MorroCommon__CWin32__RegSetValueExW
.rdata:0000000180020F48 D0 53 01 80 01 00+                dq offset MorroCommon__CWin32__RegCloseKey
.rdata:0000000180020F50 F0 53 01 80 01 00+                dq offset MorroCommon__CWin32__RegDeleteKeyW
.rdata:0000000180020F58 10 54 01 80 01 00+                dq offset MorroCommon__CWin32__RegDeleteValueW
.rdata:0000000180020F60 30 54 01 80 01 00+                dq offset MorroCommon__CWin32__ShowWindow
.rdata:0000000180020F68 50 54 01 80 01 00+                dq offset MorroCommon__CWin32__LoadLibraryExW
.rdata:0000000180020F70 70 54 01 80 01 00+                dq offset MorroCommon__CWin32__LoadLibraryExW_0
.rdata:0000000180020F78 90 54 01 80 01 00+                dq offset MorroCommon__CWin32__GetLocaleInfoW
.rdata:0000000180020F80 C0 54 01 80 01 00+                dq offset MorroCommon__CWin32__CreateProcessW
.rdata:0000000180020F88 40 55 01 80 01 00+                dq offset MorroCommon__CWin32__FreeLibrary
.rdata:0000000180020F90 60 55 01 80 01 00+                dq offset MorroCommon__CWin32__CreateMutexW
.rdata:0000000180020F98 80 55 01 80 01 00+                dq offset MorroCommon__CWin32__WaitForSingleObject
.rdata:0000000180020FA0 A0 55 01 80 01 00+                dq offset MorroCommon__CWin32__ReleaseMutex
.rdata:0000000180020FA8 C0 55 01 80 01 00+                dq offset MorroCommon__CWin32__ConvertStringSecurityDescriptorToSecurityDescriptorW
.rdata:0000000180020FB0 F0 55 01 80 01 00+                dq offset MorroCommon__CWin32__CloseHandle
.rdata:0000000180020FB8 10 56 01 80 01 00+                dq offset MorroCommon__CWin32__RegOpenKeyExW
.rdata:0000000180020FC0 50 56 01 80 01 00+                dq offset MorroCommon__CWin32__RegQueryValueExW
.rdata:0000000180020FC8 A0 56 01 80 01 00+                dq offset MorroCommon__CWin32__GetFileVersionInfoSizeW
.rdata:0000000180020FD0 C0 56 01 80 01 00+                dq offset MorroCommon__CWin32__GetFileVersionInfoW
.rdata:0000000180020FD8 F0 56 01 80 01 00+                dq offset MorroCommon__CWin32__VerQueryValueW
.rdata:0000000180020FE0 20 57 01 80 01 00+                dq offset MorroCommon__CWin32__IsWow64Process
.rdata:0000000180020FE8 40 57 01 80 01 00+                dq offset MorroCommon__CWin32__LoadStringW
.rdata:0000000180020FF0 70 57 01 80 01 00+                dq offset MorroCommon__CWin32__PostMessageW
.rdata:0000000180020FF8 A0 57 01 80 01 00+                dq offset MorroCommon__CWin32__LocalFree
.rdata:0000000180021000 C0 57 01 80 01 00+                dq offset MorroCommon__CWin32__Sleep
.rdata:0000000180021008 E0 57 01 80 01 00+                dq offset MorroCommon__CWin32__GetExitCodeProcess
.rdata:0000000180021010 00 58 01 80 01 00+                dq offset MorroCommon__CWin32__GetWindowsDirectoryW
.rdata:0000000180021018 20 58 01 80 01 00+                dq offset MorroCommon__CWin32__GetSystemDirectoryW
.rdata:0000000180021020 40 58 01 80 01 00+                dq offset MorroCommon__CWin32__GetDiskFreeSpaceExW
.rdata:0000000180021028 70 58 01 80 01 00+                dq offset MorroCommon__CWin32__SetWindowTextW
.rdata:0000000180021030 90 58 01 80 01 00+                dq offset MorroCommon__CWin32__GetSystemMetrics
.rdata:0000000180021038 B0 58 01 80 01 00+                dq offset MorroCommon__CWin32__OpenProcess
.rdata:0000000180021040 D0 58 01 80 01 00+                dq offset MorroCommon__CWin32__OpenProcessToken
.rdata:0000000180021048 F0 58 01 80 01 00+                dq offset MorroCommon__CWin32__GetTokenInformation
.rdata:0000000180021050 30 59 01 80 01 00+                dq offset MorroCommon__CWin32__GetSidSubAuthorityCount
.rdata:0000000180021058 50 59 01 80 01 00+                dq offset MorroCommon__CWin32__FindWindowW
.rdata:0000000180021060 70 59 01 80 01 00+                dq offset MorroCommon__CWin32__GetWindowThreadProcessId
.rdata:0000000180021068 90 59 01 80 01 00+                dq offset MorroCommon__CWin32__GetCurrentProcessId
.rdata:0000000180021070 B0 59 01 80 01 00+                dq offset MorroCommon__CWin32__DuplicateTokenEx
.rdata:0000000180021078 00 5A 01 80 01 00+                dq offset MorroCommon__CWin32__CreateToolhelp32Snapshot
.rdata:0000000180021080 20 5A 01 80 01 00+                dq offset MorroCommon__CWin32__Process32FirstW
.rdata:0000000180021088 40 5A 01 80 01 00+                dq offset MorroCommon__CWin32__Process32NextW
.rdata:0000000180021090 60 5A 01 80 01 00+                dq offset MorroCommon__CWin32__TerminateProcess
.rdata:0000000180021098 80 5A 01 80 01 00+                dq offset MorroCommon__CWin32__MessageBoxW
.rdata:00000001800210A0 B0 5A 01 80 01 00+                dq offset MorroCommon__CWin32__SetForegroundWindow
.rdata:00000001800210A8 D0 5A 01 80 01 00+                dq offset MorroCommon__CWin32__FindResourceW
.rdata:00000001800210B0 F0 5A 01 80 01 00+                dq offset MorroCommon__CWin32__LoadResource
.rdata:00000001800210B8 10 5B 01 80 01 00+                dq offset MorroCommon__CWin32__LockResource
.rdata:00000001800210C0 30 5B 01 80 01 00+                dq offset MorroCommon__CWin32__FreeResource
.rdata:00000001800210C8 50 5B 01 80 01 00+                dq offset MorroCommon__CWin32__FindFirstFileW
.rdata:00000001800210D0 70 5B 01 80 01 00+                dq offset MorroCommon__CWin32__FindNextFileW
.rdata:00000001800210D8 90 5B 01 80 01 00+                dq offset MorroCommon__CWin32__FindClose
.rdata:00000001800210E0 B0 5B 01 80 01 00+                dq offset MorroCommon__CWin32__RemoveDirectoryW
.rdata:00000001800210E8 D0 5B 01 80 01 00+                dq offset MorroCommon__CWin32__DeleteFileW
.rdata:00000001800210F0 F0 5B 01 80 01 00+                dq offset MorroCommon__CWin32__GetCurrentProcess
.rdata:00000001800210F8 10 5C 01 80 01 00+                dq offset MorroCommon__CWin32__HeapAlloc
.rdata:0000000180021100 30 5C 01 80 01 00+                dq offset MorroCommon__CWin32__GetProcessHeap
.rdata:0000000180021108 50 5C 01 80 01 00+                dq offset MorroCommon__CWin32__HeapFree
.rdata:0000000180021110 70 5C 01 80 01 00+                dq offset MorroCommon__CWin32__GetSidSubAuthority
.rdata:0000000180021118 90 5C 01 80 01 00+                dq offset MorroCommon__CWin32___wchmod
.rdata:0000000180021120 B0 5C 01 80 01 00+                dq offset MorroCommon__CWin32__K32GetModuleFileNameExW
.rdata:0000000180021128 E0 5C 01 80 01 00+                dq offset MorroCommon__CWin32__AllocateAndInitializeSid
.rdata:0000000180021130 70 5D 01 80 01 00+                dq offset MorroCommon__CWin32__CheckTokenMembership
.rdata:0000000180021138 90 5D 01 80 01 00+                dq offset MorroCommon__CWin32__FreeSid
.rdata:0000000180021140 B0 5D 01 80 01 00+                dq offset MorroCommon__CWin32__CoCreateGuid
.rdata:0000000180021148 D0 5D 01 80 01 00+                dq offset MorroCommon__CWin32__StringFromGUID2
.rdata:0000000180021150 C0 67 01 80 01 00+                dq offset MorroCommon__CWin32__GetVersionExW
.rdata:0000000180021158 F0 5D 01 80 01 00+                dq offset MorroCommon__CWin32__VerifyVersionInfoW
.rdata:0000000180021160 10 5E 01 80 01 00+                dq offset MorroCommon__CWin32__CreateFileW
.rdata:0000000180021168 70 5E 01 80 01 00+                dq offset MorroCommon__CWin32__ReadFile
.rdata:0000000180021170 B0 5E 01 80 01 00+                dq offset MorroCommon__CWin32__WriteFile
.rdata:0000000180021178 F0 5E 01 80 01 00+                dq offset MorroCommon__CWin32__GetFileSize
.rdata:0000000180021180 10 5F 01 80 01 00+                dq offset MorroCommon__CWin32__OpenSCManagerW
.rdata:0000000180021188 30 5F 01 80 01 00+                dq offset MorroCommon__CWin32__OpenServiceW
.rdata:0000000180021190 50 5F 01 80 01 00+                dq offset MorroCommon__CWin32__ChangeServiceConfigW
.rdata:0000000180021198 F0 5F 01 80 01 00+                dq offset MorroCommon__CWin32__ControlService
.rdata:00000001800211A0 10 60 01 80 01 00+                dq offset MorroCommon__CWin32__QueryServiceStatus
.rdata:00000001800211A8 30 60 01 80 01 00+                dq offset MorroCommon__CWin32__GetFileSizeEx
.rdata:00000001800211B0 50 60 01 80 01 00+                dq offset MorroCommon__CWin32__GetLongPathNameW
.rdata:00000001800211B8 70 60 01 80 01 00+                dq offset MorroCommon__CWin32__SetTimer
.rdata:00000001800211C0 A0 60 01 80 01 00+                dq offset MorroCommon__CWin32__KillTimer
.rdata:00000001800211C8 C0 60 01 80 01 00+                dq offset MorroCommon__CWin32__LookupPrivilegeValueW
.rdata:00000001800211D0 E0 60 01 80 01 00+                dq offset MorroCommon__CWin32__PrivilegeCheck
.rdata:00000001800211D8 00 61 01 80 01 00+                dq offset MorroCommon__CWin32__AdjustTokenPrivileges
.rdata:00000001800211E0 50 61 01 80 01 00+                dq offset MorroCommon__CWin32__InitiateSystemShutdownExW
.rdata:00000001800211E8 C0 61 01 80 01 00+                dq offset MorroCommon__CWin32__MoveFileW
.rdata:00000001800211F0 E0 61 01 80 01 00+                dq offset MorroCommon__CWin32__CreateThread
.rdata:00000001800211F8 30 62 01 80 01 00+                dq offset MorroCommon__CWin32__SetEvent
.rdata:0000000180021200 50 62 01 80 01 00+                dq offset MorroCommon__CWin32__IsDialogMessageW
.rdata:0000000180021208 70 62 01 80 01 00+                dq offset MorroCommon__CWin32__ResetEvent
.rdata:0000000180021210 90 62 01 80 01 00+                dq offset MorroCommon__CWin32__CreateEventW
.rdata:0000000180021218 C0 62 01 80 01 00+                dq offset MorroCommon__CWin32__GetCurrentThreadId
.rdata:0000000180021220 E0 62 01 80 01 00+                dq offset MorroCommon__CWin32__PostThreadMessageW
.rdata:0000000180021228 10 63 01 80 01 00+                dq offset MorroCommon__CWin32__GetExitCodeThread
.rdata:0000000180021230 30 63 01 80 01 00+                dq offset MorroCommon__CWin32__GetPrivateProfileStringW
.rdata:0000000180021238 80 63 01 80 01 00+                dq offset MorroCommon__CWin32__GetPrivateProfileIntW
.rdata:0000000180021240 B0 63 01 80 01 00+                dq offset MorroCommon__CWin32__WritePrivateProfileStringW
.rdata:0000000180021248 E0 63 01 80 01 00+                dq offset MorroCommon__CWin32__GetSystemDefaultUILanguage
.rdata:0000000180021250 00 64 01 80 01 00+                dq offset MorroCommon__CWin32__GetUserDefaultUILanguage
.rdata:0000000180021258 20 64 01 80 01 00+                dq offset MorroCommon__CWin32__ProcessIdToSessionId
.rdata:0000000180021260 70 64 01 80 01 00+                dq offset MorroCommon__CWin32__CloseServiceHandle
.rdata:0000000180021268 90 64 01 80 01 00+                dq offset MorroCommon__CWin32__PathRemoveFileSpecW
.rdata:0000000180021270 B0 64 01 80 01 00+                dq offset MorroCommon__CWin32__SHGetSpecialFolderLocation
.rdata:0000000180021278 D0 64 01 80 01 00+                dq offset MorroCommon__CWin32__SHGetPathFromIDListW
.rdata:0000000180021280 F0 64 01 80 01 00+                dq offset MorroCommon__CWin32__SetLastError
.rdata:0000000180021288 10 65 01 80 01 00+                dq offset MorroCommon__CWin32__PathIsRelativeW
.rdata:0000000180021290 30 65 01 80 01 00+                dq offset MorroCommon__CWin32__GetNativeSystemInfo
.rdata:0000000180021298 50 65 01 80 01 00+                dq offset MorroCommon__CWin32__WTSFreeMemory
.rdata:00000001800212A0 70 65 01 80 01 00+                dq offset MorroCommon__CWin32__DestroyEnvironmentBlock
.rdata:00000001800212A8 90 65 01 80 01 00+                dq offset MorroCommon__CWin32__LookupPrivilegeNameW
.rdata:00000001800212B0 C0 65 01 80 01 00+                dq offset MorroCommon__CWin32__CreateEnvironmentBlock
.rdata:00000001800212B8 E0 65 01 80 01 00+                dq offset MorroCommon__CWin32__CreateProcessAsUserW
.rdata:00000001800212C0 70 66 01 80 01 00+                dq offset MorroCommon__CWin32__WTSEnumerateSessionsW
.rdata:00000001800212C8 B0 66 01 80 01 00+                dq offset MorroCommon__CWin32__WTSQueryUserToken
.rdata:00000001800212D0 D0 66 01 80 01 00+                dq offset MorroCommon__CWin32__WTSQuerySessionInformationW
.rdata:00000001800212D8 10 67 01 80 01 00+                dq offset MorroCommon__CWin32__PathFindFileNameW
.rdata:00000001800212E0 30 67 01 80 01 00+                dq offset MorroCommon__CWin32__GetProcAddress
.rdata:00000001800212E8 50 67 01 80 01 00+                dq offset MorroCommon__CWin32__AdjustWindowRectEx
.rdata:00000001800212F0 80 67 01 80 01 00+                dq offset MorroCommon__CWin32__SystemTimeToFileTime
.rdata:00000001800212F8 A0 67 01 80 01 00+                dq offset MorroCommon__CWin32__GetLocalTime
.rdata:0000000180021300 E0 67 01 80 01 00+                dq offset MorroCommon__CWin32__GetProductInfo ; #STR: "GetProductInfo", "Kernel32.dll"
.rdata:0000000180021308 D0 68 01 80 01 00+                dq offset MorroCommon__CWin32__GetDriveTypeW
.rdata:0000000180021310 F0 68 01 80 01 00+                dq offset MorroCommon__CWin32__GlobalFindAtomW
*/

namespace MorroCommon
{
	// This class has 35 functions, all of them just winapi functions, some are wrappers
	class CWin32
	{
	public:
		// INDEX: 1
		HWND _CreateDialogParamW(
			HINSTANCE hInstance,
			const WCHAR* lpTemplateName,
			HWND hWndParent,
			INT_PTR(__stdcall* lpDialogFunc)(HWND, UINT, WPARAM, LPARAM),
			LPARAM dwInit)
		{
			return CreateDialogParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInit);
		}

		// INDEX: 2
		HICON _LoadIconW(HINSTANCE hInstance,
			LPCWSTR lpIconName)
		{
			return LoadIconW(hInstance, lpIconName);
		}

		// INDEX: 3
		BOOL _DestroyWindow(HWND hWnd)
		{
			return DestroyWindow(hWnd);
		}

		// INDEX: 4
		LRESULT _SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
		{
			return SendMessageW(hWnd, Msg, wParam, lParam);
		}

		// There are more functions
	};
}