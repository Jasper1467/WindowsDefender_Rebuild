#pragma once

#include <Windows.h>

namespace MorroCommon
{
	// This class has 35 functions, I think all of them are just winapi functions
	class CWin32
	{
	public:
		// Index: 1
		HWND _CreateDialogParamW(
			HINSTANCE hInstance,
			const WCHAR* lpTemplateName,
			HWND hWndParent,
			INT_PTR(__stdcall* lpDialogFunc)(HWND, UINT, WPARAM, LPARAM),
			LPARAM dwInit)
		{
			return CreateDialogParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInit);
		}

		// Index: 2
		HICON _LoadIconW(HINSTANCE hInstance,
			LPCWSTR lpIconName)
		{
			return LoadIconW(hInstance, lpIconName);
		}

		// Index: 3
		BOOL _DestroyWindow(HWND hWnd)
		{
			return DestroyWindow(hWnd);
		}

		// Index: 4
		LRESULT _SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
		{
			return SendMessageW(hWnd, Msg, wParam, lParam);
		}

		// There are more functions
	};
}