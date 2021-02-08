#include "stdafx.h"
#include "mem.h"
#include "Myfunctions.h"
//文本操作 - 子文本替换
/*
    调用格式： 〈文本型〉 子文本替换 （文本型 欲被替换的文本，文本型 欲被替换的子文本，［文本型 用作替换的子文本］，［整数型 进行替换的起始位置］，［整数型 替换进行的次数］，逻辑型 是否区分大小写） - 系统核心支持库->文本操作
    英文名称：RpSubText
    返回一个文本，该文本中指定的子文本已被替换成另一子文本，并且替换发生的次数也是被指定的。本命令为初级命令。
    参数<1>的名称为“欲被替换的文本”，类型为“文本型（text）”。
    参数<2>的名称为“欲被替换的子文本”，类型为“文本型（text）”。
    参数<3>的名称为“用作替换的子文本”，类型为“文本型（text）”，可以被省略。如果本参数被省略，默认为空文本。
    参数<4>的名称为“进行替换的起始位置”，类型为“整数型（int）”，可以被省略。参数值指定被替换子文本的起始搜索位置。如果省略，默认从 1 开始。
    参数<5>的名称为“替换进行的次数”，类型为“整数型（int）”，可以被省略。参数值指定对子文本进行替换的次数。如果省略，默认进行所有可能的替换。
    参数<6>的名称为“是否区分大小写”，类型为“逻辑型（bool）”，初始值为“真”。为真区分大小写，为假不区分。


char* StrCpyForE(char* pSrc)
{
	INT nLen = strlen(pSrc);
	char *pText = (char*)E_MAlloc(nLen+1);
	strcpy(pText,pSrc);
	return pText;
}*/
LIBAPI(char*, krnln_RpSubText)
{// 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	char* pSrc = pArgInf[0].m_pText;
	if (!pSrc || !*pSrc) return NULL;
	//开始替换位置
	INT nStart;
	if (pArgInf[3].m_dtDataType == _SDT_NULL || pArgInf[3].m_int <= 1)
		nStart = 0;
	else
		nStart = pArgInf[3].m_int - 1;
	//判断开始位置
	char* cp = pSrc;
	char* pStart = pSrc + nStart;
	for (; *cp && cp < pStart; cp++)
		if (*cp < 0) cp++; // 汉字
	//MessageBox(NULL,"1","432",MB_OK);
	if (!*cp)
		return CloneTextData(pSrc, cp - pSrc);

	INT nSLen = (cp + mystrlen(cp)) - pSrc;
	//MessageBox(NULL,"2","432",MB_OK);
	//待搜索文本
	char* pDes = pArgInf[1].m_pText;
	INT nDLen = 0;
	if (pDes)
		nDLen = mystrlen(pDes);
	//替换次数
	//MessageBox(NULL,"3","432",MB_OK);
	INT nCount = pArgInf[4].m_int;
	if (pArgInf[4].m_dtDataType == _SDT_NULL)
		nCount = 0x7FFFFFFF;// 最大替换次数21亿
	//MessageBox(NULL,"4","432",MB_OK);
	if (nDLen <=0 || nCount<=0) // 关键参数不合法，直接返回原文本
		return CloneTextData(pSrc, nSLen);
	//MessageBox(NULL,"5","432",MB_OK);
	char* pSub = NULL;
	INT nSubLen = 0;
	if (pArgInf[2].m_dtDataType != _SDT_NULL)
	{
		pSub = pArgInf[2].m_pText;
		if (pSub)
			nSubLen = mystrlen(pSub);
	}
	//MessageBox(NULL,"6","432",MB_OK);
	// 开始计算
	PTB pTb = initSubTb();
	if (!pTb)
		return CloneTextData(pSrc, nSLen);
	//MessageBox(NULL,"123","432",MB_OK);

	INT nPos;
	char* pFirst = pSrc;
	char* pLast = pSrc + nSLen;
	//char* pMsg = (char*)malloc(256);
	//sprintf(pMsg,"addr:%x",pTb);
	//MessageBox(NULL,pMsg,"432",MB_OK);
	if (pArgInf[5].m_bool) // 区分大小写
	{
		for (; nCount > 0; nCount--)
		{
			nPos = mystrstr((char*)cp, (char*)pDes);
			if (nPos == -1)
				break;
			if (cp + nPos - pFirst > 0)
				recSub(&pTb, pFirst, cp + nPos - pFirst);
		
			if (nSubLen > 0)
				recSub(&pTb, pSub, nSubLen);
		
			cp += nPos + nDLen;
			pFirst = cp;
		}
	}
	else
	{
		for (; nCount > 0; nCount--)
		{
			nPos = mystristr((char*)cp, (char*)pDes);
			if (nPos == -1)
				break;
			if (cp + nPos - pFirst > 0)
				recSub(&pTb, pFirst, cp + nPos - pFirst);
			
			if (nSubLen > 0)
				recSub(&pTb, pSub, nSubLen);
			
			cp += nPos + nDLen;
			pFirst = cp;
		}
	}
	//MessageBox(NULL,"8","432",MB_OK);
	if (pLast - pFirst > 0)
		recSub(&pTb, pFirst, pLast - pFirst);
	
	//MessageBox(NULL,"9","432",MB_OK);
	// 复制计算结果
	char* pRetn = SubTbtoString(pTb);
	if (pTb)
		free(pTb);
	//MessageBox(NULL,"12","432",MB_OK);
	return pRetn;
}

