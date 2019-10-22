#include "stdafx.h"
#include "Myfunctions.h"

//文本操作 - 删首空
/*
    调用格式： 〈文本型〉 删首空 （文本型 欲删除空格的文本） - 系统核心支持库->文本操作
    英文名称：LTrim
    返回一个文本，其中包含被删除了首部全角或半角空格的指定文本。本命令为初级命令。
    参数<1>的名称为“欲删除空格的文本”，类型为“文本型（text）”。

*/
LIBAPI(char*, krnln_LTrim)
{// 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	register unsigned char *str1 = (unsigned char*)pArgInf[0].m_pText;

	while ( *str1 )
	{
		if (*str1 == ' ')
			str1++;
		else if (*((unsigned short*)str1) == 0xA1A1)
			str1+=2;
		else
			break;
	}

	if (!*str1) return NULL; //空文本直接返回
	INT nLen = mystrlen((char*)str1);
	char *pText = (char*)E_MAlloc_Nzero(nLen+1);
	memcpy(pText, str1, nLen+1);
	
	return pText;
}
// {// 大鸟原版
// 	INT nLen = strlen(ArgInf.m_pText);
// 	if(nLen==0)return NULL;
// 	INT i = 0;
// 	char* pSrc = ArgInf.m_pText;
// 	while(i < nLen)
// 	{
// 		if(*pSrc == ' ' || strncmp(pSrc,"　",2)==0)
// 		{
// 			if(*pSrc< 0)
// 			{
// 				i+=2;
// 				pSrc+=2;
// 			}
// 			else
// 			{
// 				pSrc++;
// 				i++;
// 			}
// 		}
// 		else
// 			break;
// 
// 	}
// 	nLen = strlen(pSrc);
// 	if(nLen==0)return NULL;
// 
// 	char *pText = (char*)E_MAlloc(nLen+1);
// 	strcpy(pText,pSrc);
// 
// 	return pText;
// 
// }
