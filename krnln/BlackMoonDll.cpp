#include "stdafx.h"
INT nBMProtectESP = 0;
INT nBMProtectEBP = 0;
PDESTROY DllEntryFunc();
extern HANDLE hBlackMoonInstanceHandle;
extern "C" PDESTROY DestroyAddress;
extern "C" {

	//PDESTROY ECodeStart();

	int __stdcall DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
	{

		switch (ul_reason_for_call)
		{
		case DLL_PROCESS_ATTACH:
			hBlackMoonInstanceHandle = hModule;
			E_Init();
			DestroyAddress = DllEntryFunc();
			break;
		case DLL_PROCESS_DETACH:
			E_DestroyRes();
			break;
			
			
		}
		
		return 1;
		
	}

}