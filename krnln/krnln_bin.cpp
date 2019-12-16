#include "stdafx.h"

//字节集操作 - 取重复字节集
/*
    调用格式： 〈字节集〉 取重复字节集 （整数型 重复次数，字节集 待重复的字节集） - 系统核心支持库->字节集操作
    英文名称：bin
    返回一个字节集，其中包含指定次数的字节集重复结果。本命令为初级命令。
    参数<1>的名称为“重复次数”，类型为“整数型（int）”。
    参数<2>的名称为“待重复的字节集”，类型为“字节集（bin）”。该字节集将用于建立返回的字节集。如果为空，将返回一个空字节集。
*/
LIBAPI(void*, krnln_bin)
{
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[0].m_int <=0 || pArgInf[1].m_pBin==NULL)
		return NULL;
	INT nLen = pArgInf[1].m_pInt[1];
	if(nLen==0)return NULL;

	LPBYTE pSrc = pArgInf[1].m_pBin + 2*sizeof(INT);
	INT nBuf = nLen * pArgInf[0].m_int;
	LPBYTE pData = (LPBYTE)E_MAlloc_Nzero(nBuf+2*sizeof(INT));
	LPBYTE pDest = pData;
	*(LPINT)pDest=1;
	pDest+=sizeof(INT);
	*(LPINT)pDest=nBuf;
	pDest+=sizeof(INT);
	for(INT i=0;i<pArgInf[0].m_int;i++)
	{
		memcpy(pDest,pSrc,nLen);
		pDest+=nLen;
	}
	return pData;
}
