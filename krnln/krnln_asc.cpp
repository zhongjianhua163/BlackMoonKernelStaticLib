#include "stdafx.h"

//文本操作 - 取代码
/*
    调用格式： 〈整数型〉 取代码 （文本型 欲取字符代码的文本，［整数型 欲取其代码的字符位置］） - 系统核心支持库->文本操作
    英文名称：asc
    返回文本中指定位置处字符的代码。如果指定位置超出文本长度，返回0。本命令为初级命令。
    参数<1>的名称为“欲取字符代码的文本”，类型为“文本型（text）”。
    参数<2>的名称为“欲取其代码的字符位置”，类型为“整数型（int）”，可以被省略。1为首位置，2为第2个位置，如此类推。如果本参数被省略，默认为首位置。
*/
LIBAPI(int, krnln_asc)
{// 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	INT nIdx;
	if(pArgInf[1].m_dtDataType == _SDT_NULL)
		nIdx = 0;
	else
		nIdx = pArgInf[1].m_int - 1;

	if (nIdx < 0) return 0;

	char* cp = pArgInf[0].m_pText;
	if (!cp) return 0;

	char* pStart = pArgInf[0].m_pText + nIdx;

	//检查给定的索引是否越界，并且不用遍历整块内存。
	while (*cp && cp < pStart)
		cp++;

	return (int)*cp;
}
// { // 大鸟原版
// 	PMDATA_INF pArgInf = &ArgInf;
// 	INT nLen = strlen(ArgInf.m_pText);
// 	if(nLen==0)return 0;
// 	INT nIdx;
// 	if(pArgInf[1].m_dtDataType == _SDT_NULL)
// 		nIdx = 1;
// 	else
// 		nIdx = pArgInf[1].m_int;
// 	if(nIdx <= 0 || nIdx > nLen)return 0;
// 
// 	return ArgInf.m_pText[nIdx-1];	
// }
