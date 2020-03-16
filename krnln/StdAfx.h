// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__F1B1835D_D6C8_463B_BD64_E80802519246__INCLUDED_)
#define AFX_STDAFX_H__F1B1835D_D6C8_463B_BD64_E80802519246__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

//#include <afx.h>
//#include <afxwin.h>
#include <windows.h>

// TODO: reference additional headers your program requires here
#ifndef DOUBLE
typedef double DOUBLE;
#endif

#ifndef DATE
typedef double DATE;
#endif

#include "lib2.h"


//**********************************************//
// 调用格式： LIBAPI (返回值类型,  函数名)
// nArgCount	参数数量
// ArgInf		参数一，如需访问其他参数，可取指针出来，如 PMDATA_INF pArgInf = &ArgInf;然后：
//					pArgInf[0] 第一个参数
//					pArgInf[1] 第二个参数
//					... 依此类推
//**********************************************//
#define LIBAPI(rType, fnName) extern "C" rType _cdecl fnName(INT nArgCount,MDATA_INF ArgInf,...)

typedef void (*PDESTROY)(void);
extern "C" {
	void  _cdecl E_DestroyRes();
	void  _cdecl E_Init();
	void  _cdecl E_End (DWORD Param1);
	void  _cdecl E_ReportError (DWORD Param1, DWORD MethodId, DWORD position);
	void*  _cdecl E_MAlloc (DWORD Param1);
	void*  _cdecl E_MAlloc_Nzero (DWORD Param1);
	void*  _cdecl E_MRealloc (void * Param1,DWORD Param2);
	void  _cdecl E_MFree (void * Param1);
	void  _cdecl E_Destroy (PDESTROY Param1);
	char* _cdecl krnln_BJCase (INT nArgCount,MDATA_INF ArgInf,...);
	char* _cdecl krnln_LTrim (INT nArgCount,MDATA_INF ArgInf,...);
	void*  _cdecl E_NULLARRAY ();
}

void* GetAryElementInf(void* pAryData ,DWORD& AryElementCount);
void FreeAryElement (void* pAryData);
void GetTimePart(DATE dt,INT& nHour,INT& nMinute,INT& nSecond);
void GetDatePart(DATE dt,INT& nYear,INT& nMonth,INT& nDay);
void DateTimeFormat(LPSTR strValue,DATE dt,BOOL bOnlyDatePart=FALSE);
double GetSpecDateTime(INT nYear, INT nMonth, INT nDay, INT nHour,INT nMinute,INT nSecond);

#define DTT_IS_NULL_DATA_TYPE   0
#define DTT_IS_SYS_DATA_TYPE    1
#define DTT_IS_USER_DATA_TYPE   2
#define DTT_IS_LIB_DATA_TYPE    3
#define ASSERT(x)
INT GetDataTypeType (DATA_TYPE dtDataType);
LPBYTE CloneBinData (LPBYTE pData, INT nDataSize);
char* CloneTextData (char* ps, INT nTextLen);
char* CloneTextData (char* ps);
INT GetSysDataTypeDataSize (DATA_TYPE dtSysDataType);

#define		VAR_BYTE		MAKELONG (MAKEWORD (1, 1), 0xa000)		// 字节
#define		VAR_SHORT		MAKELONG (MAKEWORD (1, 2), 0xa000)		// 短整数
#define		VAR_INT			MAKELONG (MAKEWORD (1, 3), 0xa000)		// 整数
#define		VAR_INT64		MAKELONG (MAKEWORD (1, 4), 0xa000)		// 长整数
#define		VAR_FLOAT		MAKELONG (MAKEWORD (1, 5), 0xa000)		// 小数
#define		VAR_DOUBLE		MAKELONG (MAKEWORD (1, 6), 0xa000)		// 双精度小数
#define		VAR_BOOL		MAKELONG (MAKEWORD (2, 0), 0xa000)		// 逻辑
#define		VAR_DATE_TIME	MAKELONG (MAKEWORD (3, 0), 0xa000)		// 日期时间
#define		VAR_TEXT		MAKELONG (MAKEWORD (4, 0), 0xa000)		// 文本
#define		VAR_BIN			MAKELONG (MAKEWORD (5, 0), 0xa000)		// 字节集
#define		VAR_SUB_PTR		MAKELONG (MAKEWORD (6, 0), 0xa000)		// 记录用户易语言子程序的代码地址

LPSTR IntNumToChn (double dNum,BOOL bSml,INT& nPre);
LPSTR FloatNumToChn (double dNum,BOOL bSml);
LPSTR FloatNumToRMB (double dNum,BOOL bSml);

INT GetDaysOfSpecMonth(INT nYear,INT nMonth);
INT GetWeekDay(DATE date);

typedef struct
{
	INT nType;  
	void* FileHandle;
	void* pLast;
	unsigned char strMD5[32];
	unsigned char strTable[258];
	INT nCryptStart;
}
FILEELEMENT, *PFILEELEMENT;

BOOL IsInFileMangerList(PFILEELEMENT pFile);
void ResetFileIO();
void CloseEfile(PFILEELEMENT pFile);
void AddFileMangerList(PFILEELEMENT pFile);

char* SDataToStr (PMDATA_INF pArgInf);
HKEY GetRegRootVal(INT nVal);

typedef struct
{
	LPDISPATCH pDisp;  
	HRESULT hRet;
}
EYDISPATCH, *PEYDISPATCH;

typedef INT (__stdcall*EError_CALLBACK)(int nCode, char* errText);
extern EError_CALLBACK fnEError_callback;

BOOL replaceText(LPSTR& pDest,LPSTR pSub,LPSTR pRplStr,BOOL bNeedFree);
//支持调用其它支持库实现函数
void BlackMoonInitAllElib();
void BlackMoonFreeAllElib();
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__F1B1835D_D6C8_463B_BD64_E80802519246__INCLUDED_)
