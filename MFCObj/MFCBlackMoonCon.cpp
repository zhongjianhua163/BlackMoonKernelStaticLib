// test.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma comment(lib, "nafxcw.lib")

extern "C" {
	int ECodeStart();
	void  _cdecl E_Init();
}
/////////////////////////////////////////////////////////////////////////////
// The one and only application object
extern "C" int ECodeStart();
//BOOL bIsEnterFromBMEntrypoint = FALSE;
INT nBMProtectESP = 0;
INT nBMProtectEBP = 0;

CWinApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
	//	CString strHello;
	//	strHello=_T("I am MfcBlackMoon");
	//	cout << (LPCTSTR)strHello << endl;

		E_Init();
		//		int nRet = ECodeStart();
		_asm{
			mov nBMProtectESP,esp;
			mov nBMProtectEBP,ebp;
			call ECodeStart;
			mov nRetCode,eax;
			
		}
	}

	return nRetCode;
}


