#include "stdafx.h"
#include "Myfunctions.h"
//文本操作 - 取重复文本
/*
    调用格式： 〈文本型〉 取重复文本 （整数型 重复次数，文本型 待重复文本） - 系统核心支持库->文本操作
    英文名称：string
    返回一个文本，其中包含指定次数的文本重复结果。本命令为初级命令。
    参数<1>的名称为“重复次数”，类型为“整数型（int）”。
    参数<2>的名称为“待重复文本”，类型为“文本型（text）”。该文本将用于建立返回的文本。如果为空，将返回一个空文本。
*/
LIBAPI(char*, krnln_string)
{
	PMDATA_INF pArgInf = &ArgInf;
	INT nLen = mystrlen(pArgInf[1].m_pText);
	if(nLen == 0 || ArgInf.m_int <=0 ) return NULL;

	INT nBuf = nLen * ArgInf.m_int;
	char *pText = (char*)E_MAlloc_Nzero(nBuf+1);
	char* pDest = pText;
	for(INT i=0;i< ArgInf.m_int;i++)
	{
		strncpy(pDest,pArgInf[1].m_pText,nLen);
		pDest+=nLen;
	}
	*pDest = 0;
	return pText;
}
