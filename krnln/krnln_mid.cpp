#include "stdafx.h"
#include "Myfunctions.h"
//文本操作 - 取文本中间
/*
    调用格式： 〈文本型〉 取文本中间 （文本型 欲取其部分的文本，整数型 起始取出位置，整数型 欲取出字符的数目） - 系统核心支持库->文本操作
    英文名称：mid
    返回一个文本，其中包含指定文本中从指定位置算起指定数量的字符。本命令为初级命令。
    参数<1>的名称为“欲取其部分的文本”，类型为“文本型（text）”。
    参数<2>的名称为“起始取出位置”，类型为“整数型（int）”。1为首位置，2为第2个位置，如此类推。
    参数<3>的名称为“欲取出字符的数目”，类型为“整数型（int）”。
*/
LIBAPI(char*, krnln_mid)
{
	PMDATA_INF pArgInf = &ArgInf;
	if (pArgInf[1].m_int <=0 || pArgInf[2].m_int <= 0 ) return NULL;
	INT nLen = mystrlen(ArgInf.m_pText);
	if(nLen == 0) return NULL;
	//if(pArgInf[1].m_int <=0)
	//	pArgInf[1].m_int = 1;
	if(pArgInf[1].m_int > nLen)//开始位置不在文本内
		return NULL;

	INT nSubLen = pArgInf[1].m_int+pArgInf[2].m_int;
	if(nSubLen > nLen)
		nSubLen = nLen - pArgInf[1].m_int+1;
	else
		nSubLen = pArgInf[2].m_int;

	char* pSrc = ArgInf.m_pText + pArgInf[1].m_int - 1;

	char *pText = (char*)E_MAlloc_Nzero(nSubLen+1);
	memcpy(pText,pSrc,nSubLen);
	pText[nSubLen]=0;
	return pText;	

}
