#include "stdafx.h"

// 调用格式： 〈字节集〉 文本到UTF8 （文本型 待转换的文本） - 系统核心支持库->文本操作
// 英文名称：StrToUTF8
// 将所指定文本转换到UTF8格式后返回,注意所返回UTF8文本数据包括结束零字符.本命令为初级命令。
// 参数<1>的名称为“待转换的文本”，类型为“文本型（text）”。提供待转换到UTF8格式的文本。
// 
// 操作系统需求： Windows、Linux
LIBAPI(void*, krnln_StrToUTF8)
{
	PMDATA_INF pArgInf = &ArgInf;
	char* pSrc = pArgInf[0].m_pText;
	if (!pSrc || !*pSrc) return NULL;

	//先将ASCII转成UNICODE
	int nNum = MultiByteToWideChar(CP_ACP, NULL, pSrc, -1, NULL, NULL);
	if (nNum <=0) return NULL;

	WCHAR* wcsUnicode = new WCHAR[nNum + 1];
	nNum = MultiByteToWideChar(CP_ACP, NULL, pSrc, -1, wcsUnicode, nNum);
	wcsUnicode[nNum] = 0;

	//再由UNICODE转UTF8
	nNum = WideCharToMultiByte(CP_UTF8, NULL, wcsUnicode, -1, NULL, NULL, NULL, NULL);
	pSrc = NULL;
	if (nNum > 0)
	{
		pSrc = (char*)E_MAlloc_Nzero(nNum + 2*sizeof(int));
		if (pSrc)
		{
			*(LPINT)pSrc = 1;
			char* pDes = pSrc + 2*sizeof(int);
			nNum = WideCharToMultiByte(CP_UTF8, NULL, wcsUnicode, -1, pDes, nNum, NULL, NULL);
			*(LPINT)(pSrc + sizeof(int)) = nNum;
		}
	}
	delete []wcsUnicode;
	return pSrc;
}

