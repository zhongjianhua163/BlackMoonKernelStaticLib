#include "stdafx.h"
#include "Myfunctions.h"

//文本操作 - 寻找文本
/*
    调用格式： 〈整数型〉 寻找文本 （文本型 被搜寻的文本，文本型 欲寻找的文本，［整数型 起始搜寻位置］，逻辑型 是否不区分大小写） - 系统核心支持库->文本操作
    英文名称：InStr
    返回一个整数值，指定一文本在另一文本中最先出现的位置，位置值从 1 开始。如果未找到，返回-1。本命令为初级命令。
    参数<1>的名称为“被搜寻的文本”，类型为“文本型（text）”。
    参数<2>的名称为“欲寻找的文本”，类型为“文本型（text）”。
    参数<3>的名称为“起始搜寻位置”，类型为“整数型（int）”，可以被省略。位置值从 1 开始。如果本参数被省略，默认为 1 。
    参数<4>的名称为“是否不区分大小写”，类型为“逻辑型（bool）”，初始值为“假”。为真不区分大小写，为假区分。
*/
LIBAPI(int, krnln_InStr)
{ // 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	INT nStart;
	char *str1 = pArgInf[0].m_pText;
	char *str2 = pArgInf[1].m_pText;
	if (!str1 || !str2 || !*str1) return -1; //空文本直接返回
	if (!*str2) return 1;
	if (pArgInf[2].m_dtDataType == _SDT_NULL || pArgInf[2].m_int <= 1)
		nStart = 0;
	else
		nStart = pArgInf[2].m_int - 1;

	char* pStart = str1 + nStart;

	char *cp = str1;
	char *s1, *s2;
	
	for (; *cp && cp < pStart; cp++)
			if (*cp < 0) cp++;

	if (pArgInf[3].m_bool) //不区分大小写
	{
		register unsigned char* lt = lowtable;
		while (*cp)
		{
			s1 = cp;
			s2 = str2;
			while ( *s1 && *s2 && (*s1==*s2 || lt[(unsigned char)(*s1)]==lt[(unsigned char)(*s2)]) )
				s1++, s2++;
			if (!*s2)
				return cp - str1 + 1;
				
			if (*cp < 0)
			{
				cp++;
				if (!*cp)
					return -1;
			}
			cp++;
		}
	}
	else  // 区分大小写
	{	
		while (*cp)
		{
			s1 = cp;
			s2 = str2;
			while ( *s1 && *s2 && !(*s1-*s2) )
				s1++, s2++;
			if (!*s2)
				return cp - str1 + 1;
			
			if (*cp < 0)
			{
				cp++;
				if (!*cp)
					return -1;
			}
			cp++;
		}
	}
	return -1;
}
// 
// { // 大鸟原版
// 	PMDATA_INF pArgInf = &ArgInf;
// 	INT nLen = strlen(ArgInf.m_pText);
// 	INT nSubLen = strlen(pArgInf[1].m_pText);
// 	if(nLen==0 || nSubLen==0 || nSubLen > nLen)return -1;
// 	
// 	INT nStart;
// 	if(pArgInf[2].m_dtDataType ==_SDT_NULL || pArgInf[2].m_int <=0)
// 		nStart = 1;
// 	else
// 		nStart = pArgInf[2].m_int;
// 	INT nEnd = nLen - nSubLen;
// 	if(nStart > (nEnd+1))return -1;
// 	char* pStart = ArgInf.m_pText + nStart -1;
// 	char* pEnd = ArgInf.m_pText + nEnd;
// 	if(pArgInf[3].m_bool) //不区分大小写
// 	{
// 		while(pStart <= pEnd)
// 		{
// 			if(strnicmp(pStart,pArgInf[1].m_pText,nSubLen)==0)
// 			{
// 				nStart = pStart - ArgInf.m_pText +1;
// 				return nStart;
// 			}
// 			if(*pStart<0)
// 				pStart+=2;
// 			else
// 				pStart++;
// 		}
// 
// 	}
// 	else
// 	{
// 		while(pStart <= pEnd)
// 		{
// 			if(strncmp(pStart,pArgInf[1].m_pText,nSubLen)==0)
// 			{
// 				nStart = pStart - ArgInf.m_pText +1;
// 				return nStart;
// 			}
// 			if(*pStart<0)
// 				pStart+=2;
// 			else
// 				pStart++;
// 		}
// 	}
// 
// 
// 	return -1;	
// }
