#include "stdafx.h"
#include "Myfunctions.h"
//文本操作 - 文本替换
/*
    调用格式： 〈文本型〉 文本替换 （文本型 欲被替换的文本，整数型 起始替换位置，整数型 替换长度，［文本型 用作替换的文本］） - 系统核心支持库->文本操作
    英文名称：ReplaceText
    将指定文本的某一部分用其它的文本替换。本命令为初级命令。
    参数<1>的名称为“欲被替换的文本”，类型为“文本型（text）”。
    参数<2>的名称为“起始替换位置”，类型为“整数型（int）”。替换的起始位置，1为首位置，2为第2个位置，如此类推。
    参数<3>的名称为“替换长度”，类型为“整数型（int）”。
    参数<4>的名称为“用作替换的文本”，类型为“文本型（text）”，可以被省略。如果本参数被省略，则删除文本中的指定部分。
*/
LIBAPI(char*, krnln_ReplaceText)
{// 被封七号改
	PMDATA_INF pArgInf = &ArgInf;
	char* pStr = pArgInf[0].m_pText;
	char* pSubstr = pArgInf[3].m_pText;
	INT nSubLen;
	INT nLen = mystrlen(pStr);
	if (pArgInf[3].m_dtDataType==_SDT_NULL)
		nSubLen = 0;
	else
		nSubLen = mystrlen(pSubstr);
	
	INT nRpLen = pArgInf[2].m_int;
	if (nRpLen < 0) nRpLen = 0;

	INT nStart = pArgInf[1].m_int - 1;
	if (nStart < 0) 
		nStart = 0;
	else if (nStart > nLen)
		nStart = nLen - 1;

	// 新长度 = 源长度 - 替换长度 + 子串长度
	// 起始点 + 替换长度 <= 源长度
	if (nStart + nRpLen > nLen) nRpLen = nLen - nStart;
	INT nNewLen = nLen - nRpLen + nSubLen;
	if (nNewLen <= 0) return NULL;

	char* pText;
	if (nStart == 0) // 往前拼接
	{
		if (nSubLen == 0) // 子串为空
			return CloneTextData(pStr + nRpLen, nNewLen);

		pText = (char*)E_MAlloc_Nzero ((DWORD)(nNewLen + 1));
		memcpy(pText, pSubstr, nSubLen);
		memcpy(pText + nSubLen, pStr + nRpLen, nLen - nRpLen + 1);//+1是把\0也复制进去
		return pText;
	}
	else if (nStart >= nLen) // 往后拼接
	{
		if (nSubLen == 0) // 子串为空
			return CloneTextData(pStr, nNewLen);

		pText = (char*)E_MAlloc_Nzero ((DWORD)(nNewLen + 1));
		memcpy(pText, pStr, nLen);
		memcpy(pText + nLen, pSubstr, nSubLen + 1);//+1是把\0也复制进去
		return pText;
	}

	// 中间拼接
	pText = (char*)E_MAlloc_Nzero ((DWORD)(nNewLen + 1));
	char* pTemp = pText;
	memcpy(pTemp, pStr, nStart);
	pTemp+=nStart;
	if (nSubLen > 0)
	{
		memcpy(pTemp, pSubstr, nSubLen);
		pTemp+=nSubLen;
	}
	if (nStart + nSubLen < nNewLen)
		memcpy(pTemp, pStr + nStart + nRpLen, nLen - nStart - nRpLen);

	pText[nNewLen] = '\0';
	return pText;
}
// {//大鸟原版
// 	PMDATA_INF pArgInf = &ArgInf;
// 	UINT nLen = mystrlen(ArgInf.m_pText);
// 	if(nLen==0)
// 	{
// 		if(pArgInf[3].m_dtDataType == _SDT_NULL)
// 			return NULL;
// 		nLen = mystrlen(pArgInf[3].m_pText);
// 		if(nLen==0)
// 			return NULL;
// 		return CloneTextData(pArgInf[3].m_pText,nLen);
// 
// 	}
// 	if(pArgInf[1].m_int > nLen || pArgInf[2].m_int <= 0)
// 		return CloneTextData(ArgInf.m_pText,nLen);
// 	INT nSubStr = 0;
// 	char* pSubStr = NULL;
// 	if(pArgInf[3].m_dtDataType != _SDT_NULL)
// 	{
// 		pSubStr = pArgInf[3].m_pText;
// 		nSubStr = mystrlen(pSubStr);
// 	}
// 	if(pArgInf[1].m_int <=0 )
// 		pArgInf[1].m_int = 1;
// 	INT nForce = pArgInf[1].m_int - 1;
// 	INT nBack = nLen - nForce;
// 	BOOL bStrcat;
// 	INT nCount ;
// 	if(nBack < pArgInf[2].m_int)
// 	{
// 		nCount = nForce + nSubStr;
// 		bStrcat = TRUE;
// 	}else{
// 
// 		nCount = nLen - pArgInf[2].m_int + nSubStr;
// 		bStrcat = FALSE;
// 	}
// 
// 	char *pText = (char*)E_MAlloc(nCount+1);
// 	if(bStrcat)
// 	{
// 		strncpy(pText,ArgInf.m_pText,nForce);
// 		pText[nForce]=0;
// 		if(pSubStr)
// 			strcat(pText,pSubStr);
// 	}
// 	else
// 	{
// 		strncpy(pText,ArgInf.m_pText,nForce);
// 		pText[nForce]=0;
// 		if(pSubStr)
// 			strcat(pText,pSubStr);
// 		pSubStr = ArgInf.m_pText + nForce + pArgInf[2].m_int;
// 		strcat(pText,pSubStr);
// 	}
// 	return pText;
// 
// }