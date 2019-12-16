#include "stdafx.h"

extern "C" int inline MyMemCmp2(unsigned char* a, unsigned char* b, int len)
{
	for (int i=0; i < (len>>2); i++)
	{
		if (((int*)a)[0]!=((int*)b)[0])
			return 1;
		a+=4;b+=4;
	}
	if ((len&2) != 0)
	{
		if (((short*)a)[0]!=((short*)b)[0])
			return 1;
		a+=2;b+=2;
	}
	if ((len&1) != 0 && a[0]!=b[0])
		return 1;
	return 0;
}
//字节集操作 - 倒找字节集
/*
    调用格式： 〈整数型〉 倒找字节集 （字节集 被搜寻的字节集，字节集 欲寻找的字节集，［整数型 起始搜寻位置］） - 系统核心支持库->字节集操作
    英文名称：InBinRev
    返回一字节集在另一字节集中最后出现的位置，位置值从 1 开始。如果未找到，返回 -1。本命令为初级命令。
    参数<1>的名称为“被搜寻的字节集”，类型为“字节集（bin）”。
    参数<2>的名称为“欲寻找的字节集”，类型为“字节集（bin）”。
    参数<3>的名称为“起始搜寻位置”，类型为“整数型（int）”，可以被省略。1为首位置，2为第2个位置，如此类推，如果被省略，则“寻找字节集”命令默认从首部开始，“倒找字节集”命令默认从尾部开始。
*/
LIBAPI(int, krnln_InBinRev)
{ // 被封七号 改
 	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[0].m_pBin==NULL || pArgInf[1].m_pBin==NULL)
 		return -1;

	INT nLen = pArgInf[0].m_pInt[1];
	INT nSubLen = pArgInf[1].m_pInt[1];
	if (nLen <= 0 || nSubLen <= 0 || nSubLen > nLen) return -1;

	register unsigned char* pSrc = pArgInf[0].m_pBin + 2*sizeof(INT);
	int off;
	if (pArgInf[2].m_dtDataType == _SDT_NULL)
		off = nLen - nSubLen;
	else
	{
		off = pArgInf[2].m_int;
		if (off < 1) 
			return -1;
		if (off <= nLen)
			nLen = off;
		off = nLen - nSubLen;
	}

 	if (off < 0) return -1;

	register unsigned char* pDes = pArgInf[1].m_pBin + 2*sizeof(INT);
	int i;
	//int j;
	// 短子串直接暴力搜索
	if (nSubLen == 1)
	{
		for (i = off; i >= 0; i--)
			if (pSrc[i] == pDes[0])
				return i + 1;
			
		return -1;
	}
	else if (nSubLen == 2)
	{
		for (i = off; i >= 0; i--)
			if (((short*)(pSrc+i))[0] == ((short*)pDes)[0])
				return i + 1;
			
		return -1;
	}
	else if (nSubLen == 3)
	{
		for (i = off; i >= 0; i--)
			if (((short*)(pSrc+i))[0] == ((short*)pDes)[0])
				if (pSrc[i+2] == pDes[2])
					return i + 1;
			
		return -1;
	}
	else if (nSubLen == 4)
	{
		for (i = off; i >= 0; i--)
			if (((int*)(pSrc+i))[0] == ((int*)pDes)[0])
				return i + 1;
			
		return -1;
	}
	else if (nSubLen == 5)
	{
		for (i = off; i >= 0; i--)
			if (((int*)(pSrc+i))[0] == ((int*)pDes)[0])
				if (pSrc[i+4] == pDes[4])
					return i + 1;
			
		return -1;
	}
	else if (nSubLen == 6)
	{
		for (i = off; i >= 0; i--)
			if (((int*)(pSrc+i))[0] == ((int*)pDes)[0])
				if (((short*)(pSrc+i+4))[0] == ((short*)(pDes+4))[0])
					return i + 1;
				
		return -1;
	}
 
// 	for (i = off; i >= 0; i--)
// 		if (MyMemCmp2(pSrc+i, pDes, nSubLen)==0)
//  			return i + 1;
// 
// 	return -1;
	// 长子串使用 Sunday算法,
	register unsigned int next[256];
	for (i = 0; i < 256; i++)
		next[i] = nSubLen;
	for (i = nSubLen; i > 0; i--)
		next[pDes[i-1]] = i;

	register unsigned char* naddr = pSrc + off;
	for (; naddr >= pSrc; naddr -= next[naddr[-1]])
		if (MyMemCmp2(naddr, pDes, nSubLen)==0)
			return naddr - pSrc + 1;
		
	return -1;
}
// {// 大鸟原版
// 	PMDATA_INF pArgInf = &ArgInf;
// 	if(pArgInf[0].m_pBin==NULL || pArgInf[1].m_pBin==NULL)
// 		return -1;
// 
// 	INT nLen = pArgInf[0].m_pInt[1];
// 	INT nSubLen = pArgInf[1].m_pInt[1];
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
// 
// 	LPBYTE pSrc = pArgInf[0].m_pBin + 2*sizeof(INT);
// 	LPBYTE pStart = pSrc + nStart;
// 	LPBYTE pObj = pArgInf[1].m_pBin + 2*sizeof(INT);
// 
// 
// 	
// 	while(pStart >= pSrc)
// 	{
// 		if(memcmp(pStart,pObj,nSubLen)==0)
// 		{
// 			nStart = pStart - pSrc +1;
// 			return nStart;
// 		}
// 		pStart--;
// 	}
// 
// 
// 	return -1;	
// }
