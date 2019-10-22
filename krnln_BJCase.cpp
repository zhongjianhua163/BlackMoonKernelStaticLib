#include "stdafx.h"
#include "Myfunctions.h"


//文本操作 - 到半角
/*
    调用格式： 〈文本型〉 到半角 （文本型 欲变换的文本） - 系统核心支持库->文本操作
    英文名称：BJCase
    将文本中的全角字母、空格或数字变换为半角，返回变换后的结果文本。本命令为初级命令。
    参数<1>的名称为“欲变换的文本”，类型为“文本型（text）”。

' 数字范围163开头，176--185
' 大写字母，163开头，193--218
' 小写字母，163开头，225--250
' ///////////以上为全角的，下面是半角的
' 数字范围，48--57
' 大写字母，65--90
' 小写字母，97-122
到字节集 (“．－”)  ' 163,174,163,173


extern "C" char* _cdecl krnln_BJCase (INT nArgCount,MDATA_INF ArgInf,...)
{
	PMDATA_INF pArgInf = &ArgInf;
	INT nLen = strlen(ArgInf.m_pText);
	if(nLen==0)return NULL;
	INT i = 0;
	INT nBufLen = 0;
	while(i < nLen)
	{
		LPBYTE pSrc = (LPBYTE)ArgInf.m_pText + i;
		if(* pSrc > 127)//汉字
		{
			i+=2;
			if(pSrc[0] ==163)
			{
				if((176 <= pSrc[1] && pSrc[1] <=185) || (193 <= pSrc[1] && pSrc[1] <=218) || (225 <= pSrc[1] && pSrc[1] <=250) || pSrc[1]==173 || pSrc[1]==174)
					nBufLen++;
				else
					nBufLen+=2;
			}
			else
				nBufLen+=2;

		}
		else
		{
			nBufLen++;
			i++;
		}
	}

	char *pBJText = (char*)E_MAlloc(nBufLen+1);
	if(nBufLen==nLen)
	{
		strcpy(pBJText,ArgInf.m_pText);
		return pBJText;
	}
	LPBYTE pText = (LPBYTE)pBJText;
	i = 0;

	while(i < nLen)
	{
		LPBYTE pSrc = (LPBYTE)ArgInf.m_pText + i;

		if(* pSrc > 127)//汉字
		{
			if(pSrc[0] ==163)
			{

				if (176 <= pSrc[1] && pSrc[1] <=185)//数字
				{
					*pText = 48 + pSrc[1] - 176;
					pText++;
					
				}else if (193 <= pSrc[1] && pSrc[1] <=218)//大写字母
				{
					*pText = 65 + pSrc[1] - 193;
					pText++;		
				}else if (225 <= pSrc[1] && pSrc[1] <=250)
				{
					*pText = 97 + pSrc[1] - 225;
					pText++;	
				}else if(pSrc[1]==173)//负号
				{
					*pText = '-';
					pText++;

				}
				else if(pSrc[1]==174)//句号
				{
					*pText = '.';
					pText++;
				}
				else
				{
					memcpy(pText,pSrc,2);
					pText+=2;
				}
			}
			else
			{
				memcpy(pText,pSrc,2);
				pText+=2;
			}

			i+=2;
		}
		else
		{
			*pText = * pSrc;
			pText++;
			i++;
		}
	}
	
	pBJText[nBufLen] = 0;
	return pBJText;	
}
*/
LIBAPI(char*, krnln_BJCase)
{
	PMDATA_INF pArgInf = &ArgInf;
	INT nLen = mystrlen(ArgInf.m_pText);
	if(nLen==0)return NULL;
	LPSTR pszSrc = ArgInf.m_pText;
	BOOL bRet = replaceText(pszSrc,"／","/",FALSE);
	BOOL bFree =FALSE;
	bFree |=bRet;
		
	bRet = replaceText(pszSrc,"＼","\\",bFree);

	bFree |=bRet;
	
	nLen = mystrlen(pszSrc);
	INT nBufLen = nLen+1;
	char *pBJText = (char*)malloc(nBufLen);
	memset(pBJText,0,nBufLen);
	//pBJText[0]=0;
	LCMapString (2052, LCMAP_HALFWIDTH, pszSrc, nLen, pBJText, nBufLen);
	if(bFree)
		free(pszSrc);
	nLen = mystrlen(pBJText);
	char *pText = CloneTextData(pBJText,nLen);
	free(pBJText);
	return pText;
}