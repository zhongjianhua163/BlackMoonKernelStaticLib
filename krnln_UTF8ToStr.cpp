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
	int nl, al;
	WCHAR *unicodetext;

	if(ArgInf.m_pBin == NULL) return NULL;
	if (ArgInf.m_pInt[1] <= 0) return NULL;

	pSrc = (char*)ArgInf.m_pBin;
	pSrc += 2*sizeof(INT);

	//先从UTF-8转成UNICODE
	nl = MultiByteToWideChar(CP_UTF8, NULL, pSrc, -1, NULL, NULL);
	if (nl <= 0) return NULL;

	unicodetext = new WCHAR[nl + 1];
	nl = MultiByteToWideChar(CP_UTF8, NULL, pSrc, -1, unicodetext, nl);
	unicodetext[nl] = 0;

	//再由UNICDOE转成ANSI
	al = WideCharToMultiByte(936, NULL, unicodetext, -1, NULL, NULL, NULL, NULL);
	pSrc = NULL;
	if (al > 0)
	{
		pSrc = (char*)E_MAlloc_Nzero(al + 1);
		if (pSrc)
		{
			al = WideCharToMultiByte(936, NULL, unicodetext, -1, pSrc, al, NULL, NULL);
			pSrc[al] = 0;
		}
	}
	delete []unicodetext;
	return pSrc;
}
