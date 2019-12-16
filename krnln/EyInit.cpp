#include "stdafx.h"

extern "C" PDESTROY DestroyAddress;

extern "C" PDESTROY HFileDestroyAddress;

extern "C" PDESTROY DestroyMidiPlayer;
extern "C" HANDLE hBlackMoonHeap;
extern "C" {


	void  _cdecl E_Init(){
		
		hBlackMoonHeap =::GetProcessHeap();
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
	}

}