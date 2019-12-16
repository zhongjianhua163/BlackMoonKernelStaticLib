#include "stdafx.h"

//字节集操作 - 取字节集中间
/*
    调用格式： 〈字节集〉 取字节集中间 （字节集 欲取其部分的字节集，整数型 起始取出位置，整数型 欲取出字节的数目） - 系统核心支持库->字节集操作
    英文名称：BinMid
    返回一个字节集，其中包含指定字节集中从指定位置算起指定数量的字节。本命令为初级命令。
    参数<1>的名称为“欲取其部分的字节集”，类型为“字节集（bin）”。
    参数<2>的名称为“起始取出位置”，类型为“整数型（int）”。1为首位置，2为第2个位置，如此类推。
    参数<3>的名称为“欲取出字节的数目”，类型为“整数型（int）”。
*/
LIBAPI(void*, krnln_BinMid)
{
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[0].m_pBin == NULL)
		return NULL;
	INT nDataSize = pArgInf[0].m_pInt[1];
	INT nObjLen = pArgInf[2].m_int;
	if(nDataSize == 0 ||  nObjLen<= 0 )
		return NULL;
	INT nStart = pArgInf[1].m_int;
	if(nStart-1 > nDataSize)
		return NULL;
	if(nStart<=0)
		nStart = 1;
	if(nStart-1 + nObjLen >= nDataSize)
		nObjLen = nDataSize - nStart+1;
	nDataSize = nObjLen;


	return CloneBinData ((LPBYTE)(pArgInf[0].m_pBin + 2*sizeof(INT)+ nStart-1),nDataSize);
}
