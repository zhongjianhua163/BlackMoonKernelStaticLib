#include "stdafx.h"
#include "Myfunctions.h"
#include <stdio.h>
BOOL __cdecl ReadPepi(HANDLE hFile, TBR* tbr)
{
	DWORD nSize;
	char* pBuffer = NULL;
	char* pHH = (char*)"\r\n\0";
	while(1)
	{
		nSize = 0;
		if (!PeekNamedPipe(hFile, NULL, NULL, NULL, &nSize, NULL))
			return FALSE;
		if (!nSize)
			break;
		pBuffer = (char*)malloc(0x400);
		if (!ReadFile(hFile, pBuffer, 0x400, &nSize, NULL))
		{
			if(pBuffer) free(pBuffer);
			return FALSE;
		}
		if (!nSize)
			break;
		tbr->add(pBuffer, nSize);
		tbr->add(pHH, 2);
		pBuffer = NULL;
	}
	if(pBuffer) free(pBuffer);
	return TRUE;
}
/*
// 其他 - 运行控制台程序
调用格式： 〈逻辑型〉 运行控制台程序 （文本型 欲运行的命令行，［文本型变量 标准输出内容存放变量］，［文本型变量 错误输出内容存放变量］，［整数型变量 返回值存放变量］） - 系统核心支持库->其他
英文名称：RunConsoleApp
运行指定的控制台程序(不会打开控制台窗口),返回是否运行成功.本命令为初级命令。
参数<1>的名称为“欲运行的命令行”，类型为“文本型（text）”。提供欲运行控制台程序的命令行文本。
参数<2>的名称为“标准输出内容存放变量”，类型为“文本型（text）”，可以被省略，提供参数数据时只能提供变量。控制台程序在运行期间输出到标准输出设备的所有内容将被存放到此变量中。如果参数被省略，默认值为无。
参数<3>的名称为“错误输出内容存放变量”，类型为“文本型（text）”，可以被省略，提供参数数据时只能提供变量。控制台程序在运行期间输出到标准错误设备的所有内容将被存放到此变量中。如果参数被省略，默认值为无。
参数<4>的名称为“返回值存放变量”，类型为“整数型（int）”，可以被省略，提供参数数据时只能提供变量。控制台程序退出时所提供的返回值将被存放到此变量中。如果参数被省略，默认值为无。

*/
LIBAPI(BOOL, krnln_RunConsoleApp)
{
	PMDATA_INF pArgInf = &ArgInf;
	char* pCMD = pArgInf[0].m_pText;

	char** pStdOut = NULL;
	char** pStdError = NULL;
	PINT pRetn = NULL;
	if (pArgInf[1].m_dtDataType != _SDT_NULL)
		pStdOut = pArgInf[1].m_ppText;
	if (pArgInf[2].m_dtDataType != _SDT_NULL)
		pStdError = pArgInf[2].m_ppText;
	if (pArgInf[3].m_dtDataType != _SDT_NULL)
		pRetn = (PINT)pArgInf[3].m_int;

	if (!pCMD || !*pCMD)
	{
		if (pRetn)
			*pRetn = 0;
		if (pStdOut && *pStdOut)
		{
			E_MFree(((void*)(*pStdOut)));
			*pStdOut = NULL;
		}
		if (pStdError && *pStdError)
		{
			E_MFree(((void*)(*pStdError)));
			*pStdError = NULL;
		}
		return FALSE;
	}

	SECURITY_ATTRIBUTES pa;
	PROCESS_INFORMATION pi;
	STARTUPINFO si;

	memset(&pi, 0, sizeof(pi));
	pi.hProcess = NULL;
	pi.hThread = NULL;
	pi.dwProcessId = NULL;
	pi.dwThreadId = NULL;
	memset(&pa, 0, sizeof(pa));
	pa.lpSecurityDescriptor = NULL;
	pa.nLength = sizeof(pa);
	pa.bInheritHandle = 1;

	HANDLE hFile1 = NULL;
	HANDLE hFile2 = NULL;
	HANDLE hStdOut = NULL;
	HANDLE hStdError = NULL;
	BOOL bSucess = FALSE;
	if(CreatePipe(&hFile1, &hStdOut, &pa, NULL))
	{
		if(CreatePipe(&hFile2, &hStdError, &pa, NULL))
		{
			memset(&si, 0, sizeof(si));
			si.cb = 68;
			si.dwFlags = 257;
			si.wShowWindow = 0;
			si.hStdOutput = hStdOut;
			si.hStdError = hStdError;

			if (CreateProcess(NULL, pCMD, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
			{
				BOOL bWait = TRUE;
				TBR tbrOut;
				TBR tbrError;
				do 
				{
					if (bWait)
						if (WaitForSingleObject(pi.hProcess, 0x64) != WAIT_TIMEOUT)
							bWait = FALSE;
				} while (bWait);
				if (pRetn)
					if (!GetExitCodeProcess(pi.hProcess, (LPDWORD)pRetn))
						*pRetn = 0;
				bSucess = TRUE;
				if (pStdOut)
				{
					ReadPepi(hFile1, &tbrOut);
					if (*pStdOut) E_MFree(*pStdOut);
					*pStdOut = tbrOut.toString();
				}
				if (pStdError)
				{
					ReadPepi(hFile2, &tbrError);
					if (*pStdError) E_MFree(*pStdError);
					*pStdError = tbrError.toString();
				}
			}
		}
	}
	if (hFile1)
		CloseHandle(hFile1);
	if (hFile2)
		CloseHandle(hFile2);
	if (hStdOut)
		CloseHandle(hStdOut);
	if (hStdError)
		CloseHandle(hStdError);
	return bSucess;
}