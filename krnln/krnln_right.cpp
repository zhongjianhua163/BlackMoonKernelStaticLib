#include "stdafx.h"
#include "Myfunctions.h"
//文本操作 - 取文本右边
/*
    调用格式： 〈文本型〉 取文本右边 （文本型 欲取其部分的文本，整数型 欲取出字符的数目） - 系统核心支持库->文本操作
    英文名称：right
    返回一个文本，其中包含指定文本中从右边算起指定数量的字符。本命令为初级命令。
    参数<1>的名称为“欲取其部分的文本”，类型为“文本型（text）”。
    参数<2>的名称为“欲取出字符的数目”，类型为“整数型（int）”。
*/
LIBAPI(char*, krnln_right)
{// 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	INT nSubLen = pArgInf[1].m_int;
	if (nSubLen <= 0) 
		return NULL;
	INT nLen = mystrlen(ArgInf.m_pText);
	if (nLen == 0) 
		return NULL;
	if (nSubLen > nLen)
		nSubLen = nLen;
	char* pText = (char*)E_MAlloc_Nzero(nSubLen + 1);
	memcpy(pText, ArgInf.m_pText + (nLen - nSubLen), nSubLen + 1);
	return pText;
}
// {大鸟原版
// 	PMDATA_INF pArgInf = &ArgInf;
// 	UINT nLen = strlen(ArgInf.m_pText);
// 	if(nLen==0 || pArgInf[1].m_int <=0)return NULL;
// 
// 	INT nOffset = nLen - pArgInf[1].m_int;
// 	if(nOffset < 0)
// 		nOffset = 0;
// 	char* pSrc = ArgInf.m_pText + nOffset;
// 	nLen = strlen(pSrc);
// 
// 	char *pText = (char*)E_MAlloc(nLen+1);
// 	strcpy(pText,pSrc);
// 	return pText;	
// }
