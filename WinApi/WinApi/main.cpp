#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
	MessageBox(NULL, "Hello its my first window in Windows API", "Hello WinAPI", MB_OK | MB_ICONWARNING);
	int answer = MessageBox(NULL, "Вы хотите изучить WinAPI?", "", MB_YESNOCANCEL | MB_ICONQUESTION | MB_DEFBUTTON3);
	if (answer == IDYES)
	{
		MessageBox(NULL, "Зачислить в Академию!", "Результат", MB_OK | MB_ICONINFORMATION);
	}
	else if(answer == IDNO)
	{
		MessageBox(NULL, "Выйди с класса!", "Розбийнык", MB_OK | MB_ICONINFORMATION);
	}
}