
#include "stdafx.h"
#include "EyMFCComInit.h"
//#define _EDLLMAIN
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCBlackMoonDLLApp

BEGIN_MESSAGE_MAP(CMFCBlackMoonDLLApp, CWinApp)
	//{{AFX_MSG_MAP(CMFCBlackMoonDLLApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCBlackMoonDLLApp construction

CMFCBlackMoonDLLApp::CMFCBlackMoonDLLApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMFCBlackMoonDLLApp object
#pragma comment(lib, "nafxcw.lib")
CMFCBlackMoonDLLApp theApp;

typedef void (*PDESTROY)(void);
PDESTROY DllEntryFunc();
extern HANDLE hBlackMoonInstanceHandle;
extern "C" PDESTROY DestroyAddress;
extern "C" {
	//PDESTROY ECodeStart();
	void  _cdecl E_Init();
	void  _cdecl E_DestroyRes();
#ifdef _EDLLMAIN
	int __stdcall EDllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 );
#endif
}
INT nBMProtectESP = 0;
INT nBMProtectEBP = 0;
BOOL CMFCBlackMoonDLLApp::InitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	//MessageBox(NULL,"I am MfcBlackMoon","DLL",MB_OK);
	hBlackMoonInstanceHandle = m_hInstance;
	E_Init();
	DestroyAddress = DllEntryFunc();
	
#ifdef _EDLLMAIN
	int nRet = EDllMain(m_hInstance,DLL_PROCESS_ATTACH,0);
	if(nRet==0)
		return nRet;
#endif
	


	return CWinApp::InitInstance();
}

int CMFCBlackMoonDLLApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
#ifdef _EDLLMAIN
	int nRet = EDllMain(m_hInstance,DLL_PROCESS_DETACH,0);
#endif
	E_DestroyRes();
	
	return CWinApp::ExitInstance();
}


