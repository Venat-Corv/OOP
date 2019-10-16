#include<Windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DlgProc), 0);
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG: 
	{
		HICON hIcon1 = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 1, (LPARAM)hIcon1);
		// Добавление компонентов окна
	}
		break;
	case WM_COMMAND:
		// Обработка событий нажатия на кнопки, текстовые поля и т.д.
		switch (LOWORD(wParam))
		{
		case IDOK:
			MessageBox(NULL, "Была нажата кнотка ОК.", "Info", MB_OK | MB_ICONINFORMATION);
			break;
		case IDCANCEL:
		{
			EndDialog(hwnd, 0);
			return FALSE;
		}
		}
		break;
	case WM_CLOSE: 
		EndDialog(hwnd, 0);
		return FALSE;
	}
	return FALSE;
}