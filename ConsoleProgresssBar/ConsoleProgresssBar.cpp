// ConsoleProgresssBar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "ConsoleProgresssBar.h"


_declspec(dllexport) unsigned short CreateBar(PB* lpbar, float max_progress, unsigned int max_length, char full_char, char empty_char) {
	if (lpbar == NULL) return 1;
	lpbar->max_progress = max_progress;
	lpbar->max_length = max_length;
	lpbar->full_char = full_char;
	lpbar->empty_char = empty_char;
	return 0;
}

_declspec(dllexport) unsigned short DeleteBar(PB* lpbar) {
	if (lpbar == NULL) return 1;
	memset(lpbar, 0x00, sizeof(PB));
	return 0;
}

_declspec(dllexport) unsigned short RefreshBar(PB* lpbar, float progress) {
	if (lpbar == NULL) return 1;
	lpbar->progress = progress;
	return 0;
}

_declspec(dllexport) unsigned short PrintBar(PB* lpbar) {
	if (lpbar == NULL) return 1;
	double rate = lpbar->progress / lpbar->max_progress;
	int redering_sum = rate * lpbar->max_length;
	printf("[");
	for (unsigned int i = 0, j = 0; i < lpbar->max_length; i++)
		printf("%c", i < redering_sum ? lpbar->full_char : lpbar->empty_char);
	printf("]");
	printf("%lf%c", rate*100,'%');
	printf("%c", rate != 1 ? '\r':'\n');
	return 0;
}

int main()
{
	PB bar;
	CreateBar(&bar, 256, 32, '#', ' ');
	for (int i = 1; i <= 256; i++) {
		Sleep(10);
		RefreshBar(&bar, i);
		PrintBar(&bar);
	}
    return 0;
}

