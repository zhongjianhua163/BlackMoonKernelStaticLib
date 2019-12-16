#include "stdafx.h"
#include <stdio.h>
#include "LTrimZeroChr.h"
#include "Myfunctions.h"

//#pragma comment(lib,"oleaut32.lib") 

//文本操作 - 到文本
/*
    调用格式： 〈文本型〉 到文本 （通用型数组/非数组 待转换的数据） - 系统核心支持库->文本操作
    英文名称：str
    返回一个文本，代表指定数值、逻辑值或日期时间被转换后的结果。如果为文本数据，将被直接返回。本命令为初级命令。
    参数<1>的名称为“待转换的数据”，类型为“通用型（all）”，提供参数数据时可以同时提供数组或非数组数据。参数值只能为数值、逻辑值、字节集、日期时间或数值型数组。
*/
char * ArryToString(void* pArry,DWORD szData)
{
	DWORD dwSize;
	char* pText = (char*)GetAryElementInf(pArry,dwSize);
	if(dwSize==0)
		return NULL;
	INT nMax = dwSize * szData;
	for(INT i=0;i<nMax;i++)
	{
		if(pText[i]==0)
			break;
	}
	UINT nLen = i;

	if(nLen==0)return NULL;
	char* pNewText = (char*)E_MAlloc_Nzero(nLen+1);
	memcpy(pNewText,pText,nLen);
	pNewText[nLen] = 0;
	return pNewText;

}

LIBAPI(char*, krnln_str)
{

	char * pText = NULL;
	if((ArgInf.m_dtDataType & DT_IS_ARY) == DT_IS_ARY)//是数组
	{
		ArgInf.m_dtDataType &=~DT_IS_ARY; //去除数组标志
		DWORD szData = 0;
		switch(ArgInf.m_dtDataType)
		{
		case SDT_BYTE:
			szData = sizeof(BYTE);
			break;
		case SDT_SHORT:
			szData = sizeof(SHORT);
			break;
		case SDT_INT64:
			szData = sizeof(INT64);
			break;
		case SDT_INT:
		case SDT_SUB_PTR:
			szData = sizeof(DWORD);
			break;
		}
		if(szData)
			pText = ArryToString(ArgInf.m_pAryData,szData);
	}
	else
	{
		char str [MAX_PATH];
		int nLen = 0;
		char* pSrc = NULL;

		switch(ArgInf.m_dtDataType)
		{
		case SDT_TEXT:
			nLen = mystrlen(ArgInf.m_pText);
			if(nLen)
				pSrc = ArgInf.m_pText;
			break;
		case SDT_BYTE:
			{
				INT nVal = ArgInf.m_byte;
				sprintf(str,"%d",nVal);
				nLen = mystrlen(str);
				pSrc = str;
			}
			break;
		case SDT_SHORT:
			{
				INT nVal = ArgInf.m_short;
				sprintf(str,"%d",nVal);
				nLen = mystrlen(str);
				pSrc = str;
			}
			break;
		case SDT_INT:
		case SDT_SUB_PTR:
			sprintf(str,"%d",ArgInf.m_int);
			nLen = mystrlen(str);
			pSrc = str;
			break;
		case SDT_INT64:
			sprintf(str,"%I64d",ArgInf.m_int64);
			nLen = mystrlen(str);
			pSrc = str;
			break;
		case SDT_FLOAT:
			sprintf(str,"%f",ArgInf.m_float);
			LTrimZeroChr(str);
			nLen = mystrlen(str);
			pSrc = str;
			break;
		case SDT_DOUBLE:
			sprintf(str,"%lf",ArgInf.m_double);
			LTrimZeroChr(str);
			nLen = mystrlen(str);
			pSrc = str;
			break;
		case SDT_BOOL:
			if(ArgInf.m_bool)
				strcpy(str,"真");
			else
				strcpy(str,"假");
			nLen = mystrlen(str);
			pSrc = str;
			break;
		case SDT_BIN:
			pText = ArryToString(ArgInf.m_pBin,sizeof(BYTE));
			break;
		case SDT_DATE_TIME:
			DateTimeFormat(str,ArgInf.m_double);
			nLen = mystrlen(str);
			if(nLen)
				pSrc = str;
			break;
		}
		if(pSrc && nLen)
		{
			pText = (char*)E_MAlloc_Nzero(nLen+1);
			strcpy(pText,pSrc);
		}

	}
	return pText;
}
