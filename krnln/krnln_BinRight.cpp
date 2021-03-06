#include "stdafx.h"

//字节集操作 - 取字节集右边
/*
    调用格式： 〈字节集〉 取字节集右边 （字节集 欲取其部分的字节集，整数型 欲取出字节的数目） - 系统核心支持库->字节集操作
    英文名称：BinRight
    返回一个字节集，其中包含指定字节集中从右边算起指定数量的字节。本命令为初级命令。
    参数<1>的名称为“欲取其部分的字节集”，类型为“字节集（bin）”。
    参数<2>的名称为“欲取出字节的数目”，类型为“整数型（int）”。
*/
LIBAPI(void*, krnln_BinRight)
{
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[0].m_pBin == NULL)
		return NULL;
	INT nDataSize = pArgInf[0].m_pInt[1];
	if(nDataSize == 0 || pArgInf[1].m_int <= 0 )
		return NULL;
	INT nOffset = nDataSize - pArgInf[1].m_int;
	if(nOffset < 0)
		nOffset = 0;
	nDataSize = pArgInf[1].m_int;
	if (nDataSize > pArgInf[0].m_pInt[1]) {
		nDataSize = pArgInf[0].m_pInt[1];
	}
	return CloneBinData ((LPBYTE)(pArgInf[0].m_pBin + 2*sizeof(INT) + nOffset), nDataSize);
}
