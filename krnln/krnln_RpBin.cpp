#include "stdafx.h"

//字节集操作 - 字节集替换
/*
    调用格式： 〈字节集〉 字节集替换 （字节集 欲替换其部分的字节集，整数型 起始替换位置，整数型 替换长度，［字节集 用作替换的字节集］） - 系统核心支持库->字节集操作
    英文名称：RpBin
    将指定字节集的某一部分用其它的字节集替换，然后返回替换后的结果。本命令为初级命令。
    参数<1>的名称为“欲替换其部分的字节集”，类型为“字节集（bin）”。
    参数<2>的名称为“起始替换位置”，类型为“整数型（int）”。替换的起始位置，1为首位置，2为第2个位置，如此类推。
    参数<3>的名称为“替换长度”，类型为“整数型（int）”。
    参数<4>的名称为“用作替换的字节集”，类型为“字节集（bin）”，可以被省略。如果本参数被省略，则删除字节集中的指定部分。
*/
LIBAPI(void*, krnln_RpBin)
{// 被封七号改
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[0].m_pBin==NULL)
		return NULL;
	LPBYTE pBin = pArgInf[0].m_pBin + 2*sizeof(INT);
	LPBYTE pSubBin = pArgInf[3].m_pBin + 2*sizeof(INT);
	INT nSubLen;
	INT nLen = pArgInf[0].m_pInt[1];
	if (pArgInf[3].m_dtDataType==_SDT_NULL)
		nSubLen = 0;
	else
		nSubLen = pArgInf[3].m_pInt[1];
	
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
	
	LPBYTE pRetn;
	LPBYTE pTemp;
	if (nStart == 0) // 往前拼接
	{
		if (nSubLen == 0) // 子串为空
			return CloneBinData(pBin + nRpLen, nNewLen);
		
		pRetn = (LPBYTE)E_MAlloc_Nzero ((DWORD)(nNewLen + 2*sizeof(INT)));
		pTemp = pRetn;
		*(LPINT)pTemp = 1; //一维数组
		pTemp+=sizeof(INT);
		*(LPINT)pTemp = nNewLen;
		pTemp+=sizeof(INT);
		memcpy(pTemp, pSubBin, nSubLen);
		memcpy(pTemp + nSubLen, pBin + nRpLen, nLen - nRpLen);
		return pRetn;
	}
	else if (nStart >= nLen) // 往后拼接
	{
		if (nSubLen == 0) // 子串为空
			return CloneBinData(pBin, nNewLen);
		
		pRetn = (LPBYTE)E_MAlloc_Nzero ((DWORD)(nNewLen + 2*sizeof(INT)));
		pTemp = pRetn;
		*(LPINT)pTemp = 1; //一维数组
		pTemp+=sizeof(INT);
		*(LPINT)pTemp = nNewLen;
		pTemp+=sizeof(INT);
		memcpy(pTemp, pBin, nLen);
		memcpy(pTemp + nLen, pSubBin, nSubLen);
		return pRetn;
	}
	
	// 中间拼接
	pRetn = (LPBYTE)E_MAlloc_Nzero ((DWORD)(nNewLen + 2*sizeof(INT)));
	pTemp = pRetn;

	*(LPINT)pTemp = 1; //一维数组
	pTemp+=sizeof(INT);
	*(LPINT)pTemp = nNewLen;
	pTemp+=sizeof(INT);

	memcpy(pTemp, pBin, nStart);
	pTemp+=nStart;
	if (nSubLen > 0)
	{
		memcpy(pTemp, pSubBin, nSubLen);
		pTemp+=nSubLen;
	}
	if (nStart + nSubLen < nNewLen)
		memcpy(pTemp, pBin + nStart + nRpLen, nLen - nStart - nRpLen);
	
	return pRetn;
}
// { 大鸟原版
// 	PMDATA_INF pArgInf = &ArgInf;
// 	if(pArgInf[0].m_pBin==NULL)
// 		return NULL;
// 	UINT nLen = pArgInf[0].m_pInt[1];
// 	
// 	if(nLen==0 )
// 	{
// 		if(pArgInf[3].m_pBin == _SDT_NULL)
// 			return NULL;
// 		nLen = pArgInf[3].m_pInt[1];
// 		if(nLen==0)
// 			return NULL;
// 		
// 		return CloneBinData(pArgInf[3].m_pBin + 2*sizeof(INT),nLen);
// 	}
// 	LPBYTE pSrc = pArgInf[0].m_pBin + 2 *sizeof(INT);
// 	if(pArgInf[1].m_int > nLen || pArgInf[2].m_int <= 0)
// 		return CloneBinData (pSrc, nLen);
// 
// 	INT nSubStr = 0;
// 	LPBYTE pSubStr = NULL;
// 	
// 	if(pArgInf[3].m_dtDataType != _SDT_NULL && pArgInf[3].m_pBin)
// 	{
// 		pSubStr = pArgInf[3].m_pBin + 2 *sizeof(INT);
// 		nSubStr = pArgInf[3].m_pInt[1];
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
// 	LPBYTE pText = (LPBYTE)E_MAlloc(nCount+2 *sizeof(INT));
// 	LPBYTE pDest = (LPBYTE)pText;
// 	*(LPINT)pDest=1;
// 	pDest+=sizeof(INT);
// 	*(LPINT)pDest=nCount;
// 	pDest+=sizeof(INT);
// 
// 	if(bStrcat)
// 	{
// 		memcpy(pDest,pSrc,nForce);
// 		if(pSubStr)
// 		{
// 			pDest+=nForce;
// 			memcpy(pDest,pSubStr,nSubStr);
// 		}
// 	}
// 	else
// 	{
// 		memcpy(pDest,pSrc,nForce);
// 		pDest+=nForce;
// 		if(pSubStr)
// 		{
// 			memcpy(pDest,pSubStr,nSubStr);
// 			pDest+=nSubStr;
// 		}
// 		nBack = nBack-pArgInf[2].m_int;
// 		pSubStr = pSrc + nForce + pArgInf[2].m_int;
// 		memcpy(pDest,pSubStr,nBack);
// 	}
// 	return pText;
// }
