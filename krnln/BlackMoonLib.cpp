#include "stdafx.h"
INT nBMProtectESP = 0;
INT nBMProtectEBP = 0;
PDESTROY DllEntryFunc();
extern HANDLE hBlackMoonInstanceHandle;
extern "C" PDESTROY DestroyAddress;
extern "C" {
	
	//PDESTROY ECodeStart();
	
	int LibInit()
	{
		hBlackMoonInstanceHandle = GetModuleHandle(NULL);
		E_Init();
		DestroyAddress = DllEntryFunc();
		return 1;
	}

	int LibUnInit()
	{
		E_DestroyRes();
		return 1;
	}
}

typedef int cb(void);

#pragma data_seg(".CRT$XIU")
static cb *autostart[] = { LibInit };

#pragma data_seg(".CRT$XPU")
static cb *autoexit[] = { LibUnInit };

#pragma data_seg() /* reset data-segment */
