#pragma once
// ----------------------------------------------------------------------------------------------

class Controller
{
public:
	bool	Load();
	void Load(HINSTANCE hins);
	// ----
	static	LRESULT WINAPI Mouse(int Code, WPARAM wParam, LPARAM lParam);
	static	LRESULT WINAPI Keyboard(int Code, WPARAM wParam, LPARAM lParam);
	static	LRESULT WINAPI Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam);
	void	ProcInterface(WPARAM wPAram);
	BOOL VKF9_State;
	// ----
	HINSTANCE	Instance;
private:
	HHOOK		MouseHook;
	HHOOK		KeyboardHook;
	// ----
}; extern Controller gController;
// ----------------------------------------------------------------------------------------------

extern char AutoOn[1024];
extern char AutoOff[1024];
