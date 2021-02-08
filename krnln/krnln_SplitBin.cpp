#include "stdafx.h"
#include "mem.h"
#include "Myfunctions.h"
//字节集操作 - 分割字节集
/*
    调用格式： 〈字节集数组〉 分割字节集 （字节集 待分割字节集，［字节集 用作分割的字节集］，［整数型 要返回的子字节集数目］） - 系统核心支持库->字节集操作
    英文名称：SplitBin
    将指定字节集进行分割，返回分割后的一维字节集数组。本命令为初级命令。
    参数<1>的名称为“待分割字节集”，类型为“字节集（bin）”。如果参数值是一个长度为零的字节集，则返回一个空数组，即没有任何成员的数组。
    参数<2>的名称为“用作分割的字节集”，类型为“字节集（bin）”，可以被省略。用于标识子字节集边界。本参数如果被省略，则默认使用字节 0 作为分隔符。
    参数<3>的名称为“要返回的子字节集数目”，类型为“整数型（int）”，可以被省略。如果被省略，则默认返回所有的子字节集。
*/
LIBAPI(void*, krnln_SplitBin)
{// 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	INT nCount = pArgInf [2].m_dtDataType == _SDT_NULL ? 0x7FFFFFFF : pArgInf [2].m_int;
	if (nCount <= 0) 
		return E_NULLARRAY();
	
	LPBYTE pSrc = pArgInf[0].m_pBin ;
	if (!pSrc)
		return E_NULLARRAY();
	INT nSLen = pArgInf[0].m_pInt[1];
	if (nSLen <= 0)
		return E_NULLARRAY();
	pSrc += 2*sizeof(INT);

	LPBYTE pSub = NULL;
	INT nSubLen = 0;
	BYTE bMark [] = {0,0};
	if(pArgInf [1].m_dtDataType == _SDT_NULL)
	{
		pSub = bMark;
		nSubLen = 1;
	}
	else
	{
		if (pArgInf [1].m_pBin)
		{
			pSub = pArgInf [1].m_pBin + 2*sizeof(INT);
			nSubLen =  pArgInf [1].m_pInt[1];
		}
	}

	if (nSubLen == 0)
		nCount = -1;//返回一个成员

	// 开始计算
	PTB pTb = initSubTb();
	if (!pTb)
		return E_NULLARRAY();
	
	INT nPos;
	INT nSYLen = nSLen;
	LPBYTE pFirst = pSrc;
	LPBYTE cp = pSrc;
	for (; nCount > 0; nCount--)
	{
		nPos = myinstring(cp, nSYLen, pSub, nSubLen);
		if (nPos == -1)
			break;
		cp += nPos;
		recSub(&pTb, pFirst, cp - pFirst);
		cp += nSubLen;
		nSYLen -= nPos + nSubLen;
		pFirst = cp;
	}
	LPBYTE pLast = pSrc + nSLen;
	if (pLast - pFirst > 0 && nCount != 0)
		recSub(&pTb, pFirst, pLast - pFirst);
	
	// 建立数组数据。
	nCount = pTb->count;
	PTBRECORD pRec = &pTb->rec[0];
	INT nSize = nCount * sizeof (DWORD);
	LPBYTE p = (LPBYTE)E_MAlloc_Nzero (sizeof (INT) * 2 + nSize);
	*(LPINT)p = 1;  // 数组维数。
	*(LPINT)(p + sizeof (INT)) = nCount;
	LPINT pp = (LPINT)(p + 2*sizeof(INT));
	for (int i=0; i < nCount; i++)
	{
		*pp = (INT)CloneBinData((LPBYTE)(pRec[i].addr), pRec[i].len);
		pp++;
	}
	
	if (pTb)
		free(pTb);
	return p;  // 返回内容数组。
}
