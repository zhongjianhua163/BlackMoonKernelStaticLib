#include "stdafx.h"

//逻辑比较 - 近似等于
/*
    调用格式： 〈逻辑型〉 近似等于 （文本型 被比较文本，文本型 比较文本） - 系统核心支持库->逻辑比较
    英文名称：like
    当比较文本在被比较文本的首部被包容时返回真，否则返回假，运算符号为“?=”或“≈”。本命令为初级命令。
    参数<1>的名称为“被比较文本”，类型为“文本型（text）”。
    参数<2>的名称为“比较文本”，类型为“文本型（text）”。
*/
LIBAPI(BOOL, krnln_like)
{// 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	register char *str1 = pArgInf[0].m_pText;
	register char *str2 = pArgInf[1].m_pText;
	if (!str1 || !str2 || !*str1 || !*str2) return FALSE; //空文本直接返回

	while ( *str1 && *str2 && *str1==*str2 )
		str1++, str2++;

	return *str2==0;
}
// {// 大鸟原版
// /*	PMDATA_INF pArgInf =&ArgInf;
// 	INT nLen = strlen(pArgInf[1].m_pText);
// 	if(strlen(pArgInf[0].m_pText) < nLen)
// 		return FALSE;
// 	if(memcmp(pArgInf[0].m_pText,pArgInf[1].m_pText,nLen)==0)
// 		return TRUE;
// 	return FALSE;*/
//   BOOL result; // eax@1
//   char *v4; // edx@1
//   size_t v5; // ebx@1
//   char *v6; // esi@1
//   char *v7; // edi@1
//   PMDATA_INF pArgInf =&ArgInf;
// 
//   v4 = pArgInf->m_pText;
//   v6 = pArgInf[1].m_pText;
//   v7 = pArgInf[1].m_pText;
//   result = FALSE;
//   v5 = strlen(v7);
//   if ( v5 <= strlen(v4) )
//   {
//     result = strncmp(v6, v4, v5) == 0;
//   }
//   return result;
// }
