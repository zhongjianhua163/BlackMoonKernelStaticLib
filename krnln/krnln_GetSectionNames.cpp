#include "stdafx.h"
#include "mem.h"
#include "Myfunctions.h"
//系统处理 - 取配置节名
/*
    调用格式： 〈文本型数组〉 取配置节名 （文本型 配置文件名） - 系统核心支持库->系统处理
    英文名称：GetSectionNames
    返回指定配置文件中所有已有节名的文本数组。本命令为初级命令。
    参数<1>的名称为“配置文件名”，类型为“文本型（text）”。指定配置文件的名称，通常以.ini作为文件名后缀。

*/
LIBAPI(void*, krnln_GetSectionNames)
{
	CMyDWordArray aryText;
#define   MAX_ALLSECTIONS   0x32000 
//	LPSTR pBuff = NULL;
	INT nLen = MAX_ALLSECTIONS;
//	do
//	{
//		pBuff = new char[nLen+1];
		char pBuff [MAX_ALLSECTIONS];
		INT nRet = GetPrivateProfileSectionNames(pBuff, MAX_ALLSECTIONS, ArgInf.m_pText);
				
//		if(nRet < nLen)
//		{
			if(nRet >0)
			{
				LPSTR pText = pBuff;
				LPSTR pEnd = pText + nRet;
				while(*pText !=0 && pText < pEnd)
				{
					nLen = mystrlen(pText);
					aryText.Add ((DWORD)CloneTextData (pText, nLen));
					pText+=(nLen+1);
				}

			}
			//delete[] pBuff;
			//break;
//		}
		//nLen = nRet;
//		delete[] pBuff;
//	}while(1);

	

	
	// 建立新变量数组数据。
	INT nSize = aryText.GetDWordCount () * sizeof (DWORD);
	LPSTR p = (LPSTR)E_MAlloc_Nzero (sizeof (INT) * 2 + nSize);
	*(LPINT)p = 1;  // 数组维数。
	*(LPINT)(p + sizeof (INT)) = aryText.GetDWordCount ();
	memcpy (p + sizeof (INT) * 2, aryText.GetPtr (), nSize);
	return  p;  // 将新内容写回该数组变量。
}
