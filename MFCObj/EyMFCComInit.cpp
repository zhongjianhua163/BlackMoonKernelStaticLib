#include "stdafx.h"
typedef void (*PDESTROY)(void);
extern "C" PDESTROY DestroyAddress;

extern "C" PDESTROY HFileDestroyAddress;

extern "C" PDESTROY DestroyMidiPlayer;

extern "C" HANDLE hBlackMoonHeap;

void BlackMoonInitAllElib();
void BlackMoonFreeAllElib();

extern "C" {


	void  _cdecl E_Init(){
		hBlackMoonHeap =::GetProcessHeap();
		AfxOleInit();
		//CoInitialize(0);
		BlackMoonInitAllElib();
	}

	void  _cdecl E_DestroyRes(){
		
		if(DestroyAddress)
			DestroyAddress();

		if(HFileDestroyAddress)
			HFileDestroyAddress();

		if(DestroyMidiPlayer)
			DestroyMidiPlayer();
		BlackMoonFreeAllElib();
		//CoUninitialize();
	}


}