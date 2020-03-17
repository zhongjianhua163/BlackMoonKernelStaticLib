#if !defined(AFX_MFCBLACKMOON_H__66A6D0ED_F1AB_4149_9834_F05CAE45D193__INCLUDED_)
#define AFX_MFCBLACKMOON_H__66A6D0ED_F1AB_4149_9834_F05CAE45D193__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCBlackMoonApp
// See MFCBlackMoon.cpp for the implementation of this class
//

class CMFCBlackMoonDLLApp : public CWinApp
{
public:
	CMFCBlackMoonDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCBlackMoonDLLApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMFCBlackMoonDLLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCBLACKMOON_H__66A6D0ED_F1AB_4149_9834_F05CAE45D193__INCLUDED_)
