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
	PINT pTb = (PINT)malloc(256);
	if (!pTb)
		return E_NULLARRAY();
	
	pTb[0] = 256; // TSize
	pTb[1] = 0; // Count
	pTb[2] = 0; // TLen
	
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
		recSub(&pTb, (INT)pFirst, cp - pFirst);
		cp += nSubLen;
		nSYLen -= nPos + nSubLen;
		pFirst = cp;
	}
	LPBYTE pLast = pSrc + nSLen;
	if (pLast - pFirst > 0 && nCount != 0)
		recSub(&pTb, (INT)pFirst, pLast - pFirst);
	
	// 建立数组数据。
	nCount = pTb[1];
	PINT pTbtmp = pTb;
	pTbtmp += 3;
	INT nSize = nCount * sizeof (DWORD);
	LPBYTE p = (LPBYTE)E_MAlloc_Nzero (sizeof (INT) * 2 + nSize);
	*(LPINT)p = 1;  // 数组维数。
	*(LPINT)(p + sizeof (INT)) = nCount;
	LPINT pp = (LPINT)(p + 2*sizeof(INT));
	for (int i=0; i < nCount; i++)
	{
		*pp = (INT)CloneBinData((LPBYTE)(pTbtmp[0]), pTbtmp[1]);
		pTbtmp += 2;
		pp++;
	}
	
	if (pTb)
		free(pTb);
	return p;  // 返回内容数组。
}
// {// 大鸟原版
// 	PMDATA_INF pArgInf = &ArgInf;
// 	
// 	LPBYTE szBeSplited = NULL;
// 	if(pArgInf [0].m_pBin)
// 	{
// 		szBeSplited = pArgInf [0].m_pBin+2*sizeof(INT);
// 	}
// 	// 如果某个具有 AS_DEFAULT_VALUE_IS_EMPTY 标志的参数用户程序中没有为其提供参数值，
// 	// 则其数据类型为 _SDT_NULL 。
// 	LPBYTE szMark = NULL;
// 	INT nLen2 = 0;
// 	BYTE bMark []={0,0};
// 	if(pArgInf [1].m_dtDataType == _SDT_NULL)
// 	{
// 		szMark = bMark;
// 		nLen2 = 1;
// 	}
// 	else
// 	{
// 		if(pArgInf [1].m_pBin)
// 		{
// 			szMark = pArgInf [1].m_pBin +2*sizeof(INT);
// 			nLen2 =  pArgInf [1].m_pInt[1];
// 		}
// 	}
// 	INT nCount = pArgInf [2].m_dtDataType == _SDT_NULL ? -1 : max (0, pArgInf [2].m_int);
// 	
// 	INT nLen1 = szBeSplited ? pArgInf [0].m_pInt[1]:0;
// 	 
// 	
// 	CMyDWordArray aryText;
// 	
// 	if (nLen1 > 0 && nCount != 0)
// 	{
// 		if (nLen2 == 0)
// 		{
// 			// 有关 CloneTextData 请参见
// 			LPBYTE pData = CloneBinData(szBeSplited,nLen1);
// 			aryText.Add ((DWORD)pData);
// 		}
// 		else
// 		{
// 			LPBYTE pBegin = szBeSplited;
// 			LPBYTE ps = pBegin;
// 			LPBYTE pEnd = pBegin +  nLen1;
// 			
// 			while (nLen1 >= nLen2)
// 			{
// 				if (!memcmp (ps, szMark, nLen2))
// 				{
// 					INT nLen = ps - pBegin;
// 
// 					LPBYTE pData = CloneBinData(pBegin,nLen);
// 					aryText.Add ((DWORD)pData);
// 					ps += nLen2;
// 					nLen1 -= nLen2;
// 					pBegin = ps;
// 					if (nCount != -1)
// 					{
// 						nCount--;
// 						if (nCount == 0)  break;
// 					}
// 				}
// 				else
// 				{
// 					ps++;
// 					nLen1--;
// 				}
// 			}
// 			
// 			if (pBegin < pEnd && nCount != 0)
// 			{
// 				INT nLen = pEnd - pBegin;
// 				LPBYTE pData = CloneBinData(pBegin,nLen);
// 				aryText.Add ((DWORD)pData);
// 			}
// 		}
// 	}
// 	
// 	// 建立数组数据。
// 	INT nSize = aryText.GetDWordCount () * sizeof (DWORD);
// 	LPBYTE p = (LPBYTE)E_MAlloc_Nzero (sizeof (INT) * 2 + nSize);
// 	*(LPINT)p = 1;  // 数组维数。
// 	*(LPINT)(p + sizeof (INT)) = aryText.GetDWordCount ();
// 	memcpy (p + sizeof (INT) * 2, aryText.GetPtr (), nSize);
// 	
// 	return p;  // 返回内容数组。
// }
