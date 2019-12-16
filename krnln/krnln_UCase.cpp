#include "stdafx.h"
#include "Myfunctions.h"

//文本操作 - 到大写
/*
    调用格式： 〈文本型〉 到大写 （文本型 欲变换的文本） - 系统核心支持库->文本操作
    英文名称：UCase
    将文本中的小写英文字母变换为大写，返回变换后的结果文本。本命令为初级命令。
    参数<1>的名称为“欲变换的文本”，类型为“文本型（text）”。
*/
LIBAPI(char*, krnln_UCase)
{// 被封七号改
	register char* pSrc = ArgInf.m_pText;
	UINT nLen = mystrlen(pSrc);
	if (nLen==0) return NULL;
	char *pText = (char*)E_MAlloc_Nzero(nLen+1);
	register char* pDes = pText;
	register unsigned char* ut = uptable;
	for (UINT i=0; i<nLen; i++)
	{
		if (pSrc[i]<0)
		{
			*((short*)(pDes+i)) = *((short*)(pSrc+i));
			i++;
		}
		else
		{
			pDes[i] = ut[(unsigned char)(pSrc[i])];
		}
	}
	pText[nLen] = '\0';
	return pText;
}
// {// 大鸟原版
// 	UINT nLen = strlen(ArgInf.m_pText);
// 	if(nLen==0)return NULL;
// 	char *pText = (char*)E_MAlloc(nLen+1);
// 	strcpy(pText,ArgInf.m_pText);
// 	UINT i=0;
// 	while(i < nLen)
// 	{
// 		if(pText[i]<0)
// 			i+=2;//汉字
// 		else
// 		{
// 			pText[i] = toupper(pText[i]);
// 			i++;
// 		}
// 
// 	}
// 	return pText;	
// }
