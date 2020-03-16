#include "stdafx.h"
extern "C" int ECodeStart();
//BOOL bIsEnterFromBMEntrypoint = FALSE;
INT nBMProtectESP = 0;
INT nBMProtectEBP = 0;
extern "C" {


	int _cdecl BMEntrypoint (){
		//bIsEnterFromBMEntrypoint = TRUE;

		E_Init();
		ECodeStart();
		return 0;

	}
}




int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
		E_Init();
		int nRet;
//		int nRet = ECodeStart();
		_asm{
			mov nBMProtectESP,esp;
			mov nBMProtectEBP,ebp;
			call ECodeStart;
			mov nRet,eax;

		}
		//MessageBox(NULL,"I am Back",NULL,nRet);
		return nRet;
}

int main(int argc, char* argv[])
{
		E_Init();
		int nRet;
//		int nRet = ECodeStart();
		_asm{
			mov nBMProtectESP,esp;
			mov nBMProtectEBP,ebp;
			call ECodeStart;
			mov nRet,eax;

		}
		return nRet;
}
