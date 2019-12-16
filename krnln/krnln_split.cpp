#include "stdafx.h"
#include "mem.h"
#include "Myfunctions.h"


//文本操作 - 分割文本
/*
    调用格式： 〈文本型数组〉 分割文本 （文本型 待分割文本，［文本型 用作分割的文本］，［整数型 要返回的子文本数目］） - 系统核心支持库->文本操作
    英文名称：split
    将指定文本进行分割，返回分割后的一维文本数组。本命令为初级命令。
    参数<1>的名称为“待分割文本”，类型为“文本型（text）”。如果参数值是一个长度为零的文本，则返回一个空数组，即没有任何成员的数组。
    参数<2>的名称为“用作分割的文本”，类型为“文本型（text）”，可以被省略。参数值用于标识子文本边界。如果被省略，则默认使用半角逗号字符作为分隔符。如果是一个长度为零的文本，则返回的数组仅包含一个成员，即完整的“待分割文本”。
    参数<3>的名称为“要返回的子文本数目”，类型为“整数型（int）”，可以被省略。如果被省略，则默认返回所有的子文本。

*/
#define IS_CC(p) p<0

LIBAPI(void*, krnln_split)
{// 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	INT nCount = pArgInf [2].m_dtDataType == _SDT_NULL ? 0x7FFFFFFF : pArgInf [2].m_int;
	LPBYTE p;
	if (nCount <= 0) 
		return E_NULLARRAY();

	char* pSub = pArgInf [1].m_dtDataType == _SDT_NULL ? "," : pArgInf [1].m_pText;
	INT nSubLen = mystrlen(pSub);

	char* pSrc = pArgInf[0].m_pText;
	if (!pSrc || !*pSrc)
		return E_NULLARRAY();

	if (nSubLen==0)
		nCount = -1;//返回一个成员

	// 开始计算
	PINT pTb = (PINT)malloc(256);
	if (!pTb)
		return E_NULLARRAY();

	pTb[0] = 256; // TSize
	pTb[1] = 0; // Count
	pTb[2] = 0; // TLen

	INT nPos;
	char* pFirst = pSrc;
	char* cp = pSrc;
	for (; nCount > 0; nCount--)
	{
		nPos = mystrstr((char*)cp, (char*)pSub);
		if (nPos == -1)
			break;
		cp += nPos;
		recSub(&pTb, (INT)pFirst, cp - pFirst);
		cp += nSubLen;
		pFirst = cp;
	}
	
	INT nSlen = mystrlen(cp) + cp - pSrc;
	char* pLast = pSrc + nSlen;
	if (pLast - pFirst > 0 && nCount != 0)
		recSub(&pTb, (INT)pFirst, pLast - pFirst);

	// 建立数组数据。
	nCount = pTb[1];
	PINT pTbtmp = pTb;
	pTbtmp += 3;
	INT nSize = nCount * sizeof (DWORD);
	p = (LPBYTE)E_MAlloc_Nzero (sizeof (INT) * 2 + nSize);
	*(LPINT)p = 1;  // 数组维数。
	*(LPINT)(p + sizeof (INT)) = nCount;
	LPINT pp = (LPINT)(p + 2*sizeof(INT));
	for (int i=0; i < nCount; i++)
	{
		*pp = (INT)CloneTextData((char*)(pTbtmp[0]), pTbtmp[1]);
		pTbtmp += 2;
		pp++;
	}

	if (pTb)
		free(pTb);
	return p;  // 返回内容数组。
}
// {// 大鸟原版
// 	PMDATA_INF pArgInf = &ArgInf;
// 	LPTSTR szBeSplited = pArgInf [0].m_pText;
// 	// 如果某个具有 AS_DEFAULT_VALUE_IS_EMPTY 标志的参数用户程序中没有为其提供参数值，
// 	// 则其数据类型为 _SDT_NULL 。
// 	LPTSTR szMark = pArgInf [1].m_dtDataType == _SDT_NULL ? "," : pArgInf [1].m_pText;
// 	INT nCount = pArgInf [2].m_dtDataType == _SDT_NULL ? -1 : max (0, pArgInf [2].m_int);
// 	
// 	INT nLen1 = strlen (szBeSplited);
// 	INT nLen2 = strlen (szMark);
// 	
// 	CMyDWordArray aryText;
// 	
// 	if (nLen1 > 0 && nCount != 0)
// 	{
// 		if (nLen2 == 0)
// 		{
// 			// 有关 CloneTextData 请参见
// 			/*INT nLen = strlen(szBeSplited);
// 			char *pText = (char*)E_MAlloc(nLen+1);
// 			strcpy(pText,szBeSplited);*/
// 			char *pText = CloneTextData(szBeSplited);
// 			aryText.Add ((DWORD)pText);
// 		}
// 		else
// 		{
// 			LPTSTR pBegin = szBeSplited;
// 			LPTSTR ps = pBegin;
// 			
// 			while (nLen1 >= nLen2)
// 			{
// 				if (!memcmp (ps, szMark, nLen2))
// 				{
// 					INT nLen = ps - pBegin;
// 					/*char *pText = (char*)E_MAlloc(nLen+1);
// 					strncpy(pText,pBegin,nLen);
// 					pText[nLen]=0;*/
// 					char *pText = CloneTextData(pBegin,nLen);
// 					aryText.Add ((DWORD)pText);
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
// 					if (IS_CC (*ps))
// 					{
// 						if (ps [1] == 0)  break;
// 						ps++;
// 						nLen1--;
// 					}
// 					ps++;
// 					nLen1--;
// 				}
// 			}
// 			
// 			if (*pBegin != '\0' && nCount != 0)
// 			{
// 				/*INT nLen = strlen(pBegin);
// 				char *pText = (char*)E_MAlloc(nLen+1);
// 				strcpy(pText,pBegin);*/
// 				char *pText = CloneTextData(pBegin);
// 				aryText.Add ((DWORD)pText);
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
// 	//MessageBox(NULL,"ok2",NULL,MB_OK);
// 	//Sleep(100);
// 	return p;  // 返回内容数组。
// }
