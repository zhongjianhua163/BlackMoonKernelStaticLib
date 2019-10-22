#include "stdafx.h"
#include "Myfunctions.h"
//文本操作 - 删尾空
/*
    调用格式： 〈文本型〉 删尾空 （文本型 欲删除空格的文本） - 系统核心支持库->文本操作
    英文名称：RTrim
    返回一个文本，其中包含被删除了尾部全角或半角空格的指定文本。本命令为初级命令。
    参数<1>的名称为“欲删除空格的文本”，类型为“文本型（text）”。
*/
LIBAPI(char*, krnln_RTrim)
{// 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	char* pSrc = pArgInf[0].m_pText;
	register char *str1 = pSrc;
	
	register char* pLastNS = NULL;
	while ( *str1 )
	{
		if (*((unsigned short*)str1) == 0xA1A1)
			str1++;
		else
		{
			if (*str1 != ' ')
			{
				
				if (*str1 < 0)
				{
					pLastNS = str1 + 1;
					str1++;
				}else{
					pLastNS = str1;
				}
			}
		}
		str1++;
	}
	
	if (!pLastNS) return NULL; //空文本直接返回
	INT nLen = pLastNS - pSrc + 1;
	char *pText = (char*)E_MAlloc_Nzero(nLen+1);
	memcpy(pText, pSrc, nLen);
	pText[nLen] = '\0';
	
	return pText;
}
// {//大鸟原版
// 	INT nLen = mystrlen(ArgInf.m_pText);
// 	if(nLen==0)return NULL;
// 	char *pText = (char*)E_MAlloc_Nzero(nLen+1);
// 	strcpy(pText,ArgInf.m_pText);
// 
// 	char* pSrc = pText + nLen - 1;
// 	while(pSrc >= pText)
// 	{
// 		if(*pSrc == ' ' || (*pSrc == -95 && *(pSrc-1) == -95))
// 		{
// 			if(*pSrc< 0)
// 			{
// 				pSrc-=2;
// 			}
// 			else
// 			{
// 				pSrc--;
// 			}
// 		}
// 		else
// 		{
// 			pSrc++;
// 			*pSrc = 0;
// 
// 			break;
// 		}
// 
// 	}
// 	nLen = mystrlen(pText);
// 	if(nLen == 0)
// 	{
// 		E_MFree(pText);
// 		pText = NULL;
// 	}
// 	return pText;
// 
// }
