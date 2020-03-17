// MFCBlackMoon.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "MFCBlackMoon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CMFCBlackMoonApp

BEGIN_MESSAGE_MAP(CMFCBlackMoonApp, CWinApp)
	//{{AFX_MSG_MAP(CMFCBlackMoonApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCBlackMoonApp construction

CMFCBlackMoonApp::CMFCBlackMoonApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMFCBlackMoonApp object
//#pragma comment(lib, "nafxcw.lib")
CMFCBlackMoonApp theApp;
extern "C" {
	int ECodeStart();
	void  _cdecl E_Init();
}
INT nBMProtectESP = 0;
INT nBMProtectEBP = 0;
BOOL CMFCBlackMoonApp::InitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
//	MessageBox(NULL,"I am MfcBlackMoon","NULL",MB_OK);
		E_Init();
		int nRet;
//		int nRet = ECodeStart();
		_asm{
			mov nBMProtectESP,esp;
			mov nBMProtectEBP,ebp;
			call ECodeStart;
			mov nRet,eax;

		}
	return CWinApp::InitInstance();
}



