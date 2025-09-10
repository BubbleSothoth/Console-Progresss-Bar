#pragma once

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct ProgressBar {
	float progress;
	float max_progress;
	unsigned int max_length;
	char full_char;
	char empty_char;
}PB;

_declspec(dllexport) unsigned short CreateBar(PB* lpbar, float max_progress, unsigned int max_length, char full_char, char empty_char);
_declspec(dllexport) unsigned short DeleteBar(PB* lpbar);
_declspec(dllexport) unsigned short RefreshBar(PB* lpbar, float progress);
_declspec(dllexport) unsigned short PrintBar(PB* lpbar);