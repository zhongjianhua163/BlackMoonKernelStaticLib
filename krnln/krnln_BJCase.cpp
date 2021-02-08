#include "stdafx.h"
#include "Myfunctions.h"


//文本操作 - 到半角
/*
    调用格式： 〈文本型〉 到半角 （文本型 欲变换的文本） - 系统核心支持库->文本操作
    英文名称：BJCase
    将文本中的全角字母、空格或数字变换为半角，返回变换后的结果文本。本命令为初级命令。
    参数<1>的名称为“欲变换的文本”，类型为“文本型（text）”。

' 数字范围163开头，176--185
' 大写字母，163开头，193--218
' 小写字母，163开头，225--250
' ///////////以上为全角的，下面是半角的
' 数字范围，48--57
' 大写字母，65--90
' 小写字母，97-122
到字节集 (“．－”)  ' 163,174,163,173
*/
LIBAPI(char*, krnln_BJCase)
{
	PMDATA_INF pArgInf = &ArgInf;
	size_t nLen = mystrlen(ArgInf.m_pText);
	if (nLen == 0) return NULL;

	char* pszLast = ArgInf.m_pText + nLen;
	char* pszFirst = ArgInf.m_pText;
	char* pszSrc = (char*)malloc(nLen + 1);
	char* pszTmp = pszSrc;
	size_t sSublen;
	for (;;)
	{
		char* pPos = strstr(pszFirst, "＼");
		if (!pPos) break;
		sSublen = pPos - pszFirst;
		if (sSublen > 0)
		{
			memcpy(pszTmp, pszFirst, sSublen);
		}
		pszTmp[sSublen] = '\\';
		pszTmp += sSublen + 1;
		pszFirst = pPos	+ 2;
	}
	sSublen = pszLast - pszFirst;
	if (sSublen > 0)
	{
		memcpy(pszTmp, pszFirst, sSublen);
		pszTmp += sSublen;
	}
	pszTmp[0] = '\0';

	nLen = mystrlen(pszSrc);
	INT nBufLen = nLen + 1;
	char *pBJText = (char*)E_MAlloc(nBufLen);
	LCMapString (2052, LCMAP_HALFWIDTH, pszSrc, nLen, pBJText, nBufLen);
	free(pszSrc);
	return pBJText;
}
