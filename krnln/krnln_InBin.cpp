#include "stdafx.h"
#include "Myfunctions.h"

//字节集操作 - 寻找字节集
/*
    调用格式： 〈整数型〉 寻找字节集 （字节集 被搜寻的字节集，字节集 欲寻找的字节集，［整数型 起始搜寻位置］） - 系统核心支持库->字节集操作
    英文名称：InBin
    返回一字节集在另一字节集中最先出现的位置，位置值从 1 开始。如果未找到，返回 -1。本命令为初级命令。
    参数<1>的名称为“被搜寻的字节集”，类型为“字节集（bin）”。
    参数<2>的名称为“欲寻找的字节集”，类型为“字节集（bin）”。
    参数<3>的名称为“起始搜寻位置”，类型为“整数型（int）”，可以被省略。1为首位置，2为第2个位置，如此类推，如果被省略，则“寻找字节集”命令默认从首部开始，“倒找字节集”命令默认从尾部开始。

*/
LIBAPI(int, krnln_InBin)
{ // 被封七号 改
 	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[0].m_pBin==NULL || pArgInf[1].m_pBin==NULL)
 		return -1;

	INT nLen = pArgInf[0].m_pInt[1];
	INT nSubLen = pArgInf[1].m_pInt[1];

	register unsigned char* pSrc;
	int off;
	if(pArgInf[2].m_dtDataType == _SDT_NULL || pArgInf[2].m_int <= 1)
	{
		off = 1;
		pSrc = pArgInf[0].m_pBin + 2*sizeof(INT);
	}
	else
	{
		off = pArgInf[2].m_int;
		pSrc = pArgInf[0].m_pBin + 2*sizeof(INT) + off - 1;
		nLen -= off - 1;
	}

 	if(nLen<=0 || nSubLen<=0 || nSubLen > nLen)
		return -1;

	register unsigned char* pDes = pArgInf[1].m_pBin + 2*sizeof(INT);
	int i;

	// 短子串直接暴力搜索
	switch (nSubLen)
	{
	case 1:
		i = mymemchr(pSrc, nLen, pDes[0]);
		if (i >= 0)
			return i + off;
		else
			return -1;
	case 2:
		for (i=0; i < nLen - 1; i++)
			if (((short*)(pSrc+i))[0] == ((short*)pDes)[0])
				return i + off;
		return -1;
	case 3:
		for (i=0; i < nLen - 2; i++)
			if (((short*)(pSrc+i))[0] == ((short*)pDes)[0])
				if (pSrc[i+2] == pDes[2])
					return i + off;	
		return -1;
	case 4:
		for (i=0; i < nLen - 3; i++)
			if (((int*)(pSrc+i))[0] == ((int*)pDes)[0])
				return i + off;
		return -1;
	case 5:
		for (i=0; i < nLen - 4; i++)
			if (((int*)(pSrc+i))[0] == ((int*)pDes)[0])
				if (pSrc[i+4] == pDes[4])
					return i + off;		
		return -1;
	case 6:
		for (i=0; i < nLen - 5; i++)
			if (((int*)(pSrc+i))[0] == ((int*)pDes)[0])
				if (((short*)(pSrc+i+4))[0] == ((short*)(pDes+4))[0])
					return i + off;
		return -1;
	default:  // 长子串使用BM算法,
		int naddr = BoyerMoore(pSrc, nLen, pDes, nSubLen);
		if (naddr >= 0)
			return naddr + off;
	}

// 长子串使用 Sunday算法,
// 	unsigned int next[256];
// 	for (i=0; i < 256; i++)
// 		next[i] = nSubLen;
// 	for (i = 0; i < nSubLen; i++)
// 		next[pDes[i]] = nSubLen - i;
// 
// 	register unsigned char* naddr;
// 	for (naddr = pSrc; naddr <= pSrc + nLen - nSubLen; naddr += next[naddr[nSubLen]])
// 		if (MyMemCmp(naddr, pDes, nSubLen)==0)
// 			return naddr - pSrc + off;
		
	return -1;
}
// { // 大鸟原版
// 	PMDATA_INF pArgInf = &ArgInf;
// 	if(pArgInf[0].m_pBin==NULL || pArgInf[1].m_pBin==NULL)
// 		return -1;
// 
// 	INT nLen = pArgInf[0].m_pInt[1];
// 	INT nSubLen = pArgInf[1].m_pInt[1];
// 	if(nLen==0 || nSubLen==0 || nSubLen > nLen)return -1;
// 	
// 	INT nStart;
// 	if(pArgInf[2].m_dtDataType ==_SDT_NULL || pArgInf[2].m_int <=0)
// 		nStart = 1;
// 	else
// 		nStart = pArgInf[2].m_int;
// 
// 	INT nEnd = nLen - nSubLen;
// 	if(nStart > (nEnd+1))return -1;
// 	LPBYTE pSrc = pArgInf[0].m_pBin + 2*sizeof(INT);
// 	LPBYTE pStart = pSrc + nStart -1;
// 	LPBYTE pEnd = pSrc + nEnd;
// 	LPBYTE pObj = pArgInf[1].m_pBin + 2*sizeof(INT);
// 
// 	while(pStart <= pEnd)
// 	{
// 		if(memcmp(pStart,pObj,nSubLen)==0)
// 		{
// 			nStart = pStart - pSrc +1;
// 			return nStart;
// 		}
// 		pStart++;
// 	}
// 
// 
// 	return -1;	
// }
