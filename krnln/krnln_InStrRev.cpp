#include "stdafx.h"
#include "Myfunctions.h"
//文本操作 - 倒找文本
/*
    调用格式： 〈整数型〉 倒找文本 （文本型 被搜寻的文本，文本型 欲寻找的文本，［整数型 起始搜寻位置］，逻辑型 是否不区分大小写） - 系统核心支持库->文本操作
    英文名称：InStrRev
    返回一个整数值，指定一文本在另一文本中最后出现的位置，位置值从 1 开始。如果未找到，返回-1。本命令为初级命令。
    参数<1>的名称为“被搜寻的文本”，类型为“文本型（text）”。
    参数<2>的名称为“欲寻找的文本”，类型为“文本型（text）”。
    参数<3>的名称为“起始搜寻位置”，类型为“整数型（int）”，可以被省略。位置值从 1 开始。如果本参数被省略，默认为从被搜寻文本的尾部开始。
    参数<4>的名称为“是否不区分大小写”，类型为“逻辑型（bool）”，初始值为“假”。为真不区分大小写，为假区分。
*/
LIBAPI(int, krnln_InStrRev)
{ // 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	INT nStart;
	char *str1 = pArgInf[0].m_pText;
	char *str2 = pArgInf[1].m_pText;
	if (!str1 || !str2 || !*str1) return -1; //空文本直接返回
	if (!*str2) return 1;
	if (pArgInf[2].m_dtDataType == _SDT_NULL)
		nStart = 0x7FFFFFFF;
	else
	{
		if (pArgInf[2].m_int <= 0)
			return -1;
		nStart = pArgInf[2].m_int - 1;
	}
	
	INT nDesLen = mystrlen(str2);
	char* pStart = str1 + nStart - nDesLen;
	
	char *cp, *s1, *s2;
	
	// 计算str1长度或者限定最大起始位置
	for (cp = str1; cp < pStart && *cp; cp++);
	//	if (*cp < 0) cp++; // 汉字步进2，，有问题！！
	
	if (cp < str1) return -1;

	if (pArgInf[3].m_bool) //不区分大小写
	{
		register unsigned char* lt = lowtable;
		while (cp >= str1)
		{
			s1 = cp;
			s2 = str2;
			while ( *s1 && *s2 && (*s1==*s2 || lt[(unsigned char)(*s1)]==lt[(unsigned char)(*s2)]) )
				s1++, s2++;
			if (!*s2)
				return cp - str1 + 1;
			cp--;
		}
	}
	else  // 区分大小写
	{	
		while (cp >= str1)
		{
			s1 = cp;
			s2 = str2;
			while ( *s1 && *s2 && !(*s1-*s2) )
				s1++, s2++;
			if (!*s2)
				return cp - str1 + 1;
			cp--;
		}
	}
	return -1;
}
// {
// 	PMDATA_INF pArgInf = &ArgInf;
// 	INT nLen = strlen(ArgInf.m_pText);
// 	INT nSubLen = strlen(pArgInf[1].m_pText);
// 	if(nLen==0 || nSubLen==0 || nSubLen > nLen)return -1;
// 	
// 	INT nStart;
// 	INT nEnd = nLen - nSubLen;
// 	if(pArgInf[2].m_dtDataType ==_SDT_NULL || pArgInf[2].m_int <=0)
// 		nStart = nEnd;
// 	else{
// 		nStart = pArgInf[2].m_int - nSubLen;
// 		if(nStart <0)
// 			nStart = 0;
// 	}
// 	
// 	if(nStart > nEnd)
// 		nStart = nEnd;
// 	char* pStart = ArgInf.m_pText + nStart;
// //MessageBox(NULL,pStart,NULL,MB_OK);
// 	if(pArgInf[3].m_bool) //不区分大小写
// 	{
// 		while(pStart >= ArgInf.m_pText)
// 		{
// 			if(strnicmp(pStart,pArgInf[1].m_pText,nSubLen)==0)
// 			{
// 				nStart = pStart - ArgInf.m_pText +1;
// 				return nStart;
// 			}
// 			pStart--;
// 		}
// 
// 	}
// 	else
// 	{
// 		while(pStart >= ArgInf.m_pText)
// 		{
// 			if(strncmp(pStart,pArgInf[1].m_pText,nSubLen)==0)
// 			{
// 				nStart = pStart - ArgInf.m_pText +1;
// 				return nStart;
// 			}
// 			pStart--;
// 		}
// 	}
// 
// 
// 	return -1;	
// }
