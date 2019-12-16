#include "stdafx.h"
#include "Myfunctions.h"
//文本操作 - 取文本左边
/*
    调用格式： 〈文本型〉 取文本左边 （文本型 欲取其部分的文本，整数型 欲取出字符的数目） - 系统核心支持库->文本操作
    英文名称：left
    返回一个文本，其中包含指定文本中从左边算起指定数量的字符。本命令为初级命令。
    参数<1>的名称为“欲取其部分的文本”，类型为“文本型（text）”。
    参数<2>的名称为“欲取出字符的数目”，类型为“整数型（int）”。
*/
LIBAPI(char*, krnln_left)
{
	PMDATA_INF pArgInf = &ArgInf;
	INT nLen = mystrlen(ArgInf.m_pText);
	if(nLen==0 || pArgInf[1].m_int <=0)return NULL;

	if(pArgInf[1].m_int < nLen)
		nLen = pArgInf[1].m_int;

	char *pText = (char*)E_MAlloc_Nzero(nLen+1);
	memcpy(pText,ArgInf.m_pText,nLen);
	pText[nLen]=0;
	return pText;	

}
