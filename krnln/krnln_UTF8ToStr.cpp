#include "stdafx.h"

// 调用格式： 〈文本型〉 UTF8到文本 （字节集 待转换的UTF8文本数据） - 系统核心支持库->文本操作
// 英文名称：UTF8ToStr
// 将所指定UTF8文本数据转换到通常文本后返回。本命令为初级命令。
// 参数<1>的名称为“待转换的UTF8文本数据”，类型为“字节集（bin）”。提供待转换到通常文本的UTF8文本数据。
// 
// 操作系统需求： Windows、Linux
LIBAPI(char*, krnln_UTF8ToStr)
{
	char* pSrc;
	char* pRet = NULL;
	int nUnicodeLen, nAnsiLen;
	WCHAR *unicodetext;

	if (ArgInf.m_pBin == NULL || ArgInf.m_pInt[1] <= 0) 
		return NULL;

	pSrc = (char*)ArgInf.m_pBin;
	pSrc += 2*sizeof(INT);

	//先从UTF-8转成UNICODE
	nUnicodeLen = MultiByteToWideChar(CP_UTF8, 0, pSrc, ArgInf.m_pInt[1], NULL, 0);
	if (nUnicodeLen <= 0) 
		return NULL;

	unicodetext = new WCHAR[nUnicodeLen + 1];
	MultiByteToWideChar(CP_UTF8, 0, pSrc, ArgInf.m_pInt[1], unicodetext, nUnicodeLen);
	unicodetext[nUnicodeLen] = '\0';

	//再由UNICDOE转成ANSI
	nAnsiLen = WideCharToMultiByte(936, 0, unicodetext, -1, NULL, 0, NULL, NULL);
	if (nAnsiLen > 0)
	{
		pRet = (char*)E_MAlloc_Nzero(nAnsiLen); //nAnsiLen包含空中止
		if (pRet)
			WideCharToMultiByte(936, 0, unicodetext, -1, pRet, nAnsiLen, NULL, NULL);
	}
	delete []unicodetext;
	return pRet;
}

//    调用格式： 〈文本型〉 UTF16到文本 （字节集 待转换的UTF16文本数据） - 系统核心支持库->文本操作
//    英文名称：UTF16ToStr
//    将所指定UTF16文本数据转换到通常文本后返回。本命令为初级命令。
//    参数<1>的名称为“待转换的UTF16文本数据”，类型为“字节集（bin）”。提供待转换到通常文本的UTF16文本数据。
//
//    操作系统需求： Windows
LIBAPI(char*, krnln_fnUTF16ToStr)
{
	char* pSrc;
	int nl, al;
	WCHAR *unicodetext;
	
	if(ArgInf.m_pBin == NULL || ArgInf.m_pInt[1] <= 0)
		return NULL;
	
	pSrc = (char*)ArgInf.m_pBin;
	pSrc += 2*sizeof(INT);
	
	//先从UTF-16转成UTF-8
	nl = WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)pSrc, ArgInf.m_pInt[1], NULL, 0, NULL, NULL);
	if (nl <= 0) return NULL;

	char* pszUtf8 = new char[nl + 1];
	nl = WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)pSrc, ArgInf.m_pInt[1], pszUtf8, nl, NULL, NULL);
	pszUtf8[nl] = '\0';

	pSrc = pszUtf8;

	//从UTF-8转成UNICODE
	nl = MultiByteToWideChar(CP_UTF8, 0, pSrc, -1, NULL, 0);
	if (nl <= 0) {
		delete []pszUtf8;
		return NULL;
	}
	
	unicodetext = new WCHAR[nl];
	nl = MultiByteToWideChar(CP_UTF8, 0, pSrc, -1, unicodetext, nl);
	if (0 >= nl)
	{
		delete []pszUtf8;
		delete []unicodetext;
		return NULL;
	}
	
	//再由UNICDOE转成ANSI
	al = WideCharToMultiByte(936, 0, unicodetext, -1, NULL, 0, NULL, NULL);
	pSrc = NULL;
	if (al > 0)
	{
		pSrc = (char*)E_MAlloc_Nzero(al);
		if (pSrc)
			WideCharToMultiByte(936, 0, unicodetext, -1, pSrc, al, NULL, NULL);
	}
	delete []pszUtf8;
	delete []unicodetext;
	return pSrc;
}
