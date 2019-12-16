#include "stdafx.h"
#include "Myfunctions.h"

//文本操作 - 到全角
/*
    调用格式： 〈文本型〉 到全角 （文本型 欲变换的文本） - 系统核心支持库->文本操作
    英文名称：QJCase
    将文本中的半角字母、空格或数字变换为全角，返回变换后的结果文本。本命令为初级命令。
    参数<1>的名称为“欲变换的文本”，类型为“文本型（text）”。

' 数字范围163开头，176--185
' 大写字母，163开头，193--218
' 小写字母，163开头，225--250
' ///////////以上为全角的，下面是半角的
' 数字范围，48--57
' 大写字母，65--90
' 小写字母，97-122
到字节集 (“．－”)  ' 163,174,163,173
*/
/*
extern "C" char* _cdecl krnln_QJCase (INT nArgCount,MDATA_INF ArgInf,...)
{
	PMDATA_INF pArgInf = &ArgInf;
	INT nLen = strlen(ArgInf.m_pText);
	if(nLen==0)return NULL;
	INT i = 0;
	INT nBufLen = 0;
	while(i < nLen)
	{
		char* pSrc = ArgInf.m_pText + i;
		if(* pSrc < 0)//汉字
		{
			i+=2;
			nBufLen+=2;
		}
		else
		{
			nBufLen++;
			if((48<= *pSrc && *pSrc <= 57) || (65<= *pSrc && *pSrc <= 90) || (97<= *pSrc && *pSrc <= 122) || *pSrc == '-' || *pSrc == '.')
				nBufLen++;
			i++;
		}
	}

	char *pQJText = (char*)E_MAlloc(nBufLen+1);
	if(nBufLen==nLen)//没有字母数字
	{
		strcpy(pQJText,ArgInf.m_pText);
		return pQJText;
	}
	char *pText = pQJText;
	i = 0;
	unsigned char strQj [3]={0,0,0};
	while(i < nLen)
	{
		char* pSrc = ArgInf.m_pText + i;
			//char t[20];
	//itoa(nBufLen,t,10);

		if(* pSrc < 0)//汉字
		{
			memcpy(pText,pSrc,2);
			pText+=2;
			i+=2;
		}
		else
		{
			INT nWord = 1;
			if(48<= *pSrc && *pSrc <= 57)//数字
			{
				strQj[0] = 163;
				strQj[1] = 176 + *pSrc - 48;
				nWord = 2;

			}else if (65<= *pSrc && *pSrc <= 90)//大写字母
			{
				strQj[0] = 163;
				strQj[1] = 193 + *pSrc - 65;
				nWord = 2;				
			}else if (97<= *pSrc && *pSrc <= 122)
			{
				strQj[0] = 163;
				strQj[1] = 225 + *pSrc - 97;
				nWord = 2;		
			}else if (*pSrc =='-')
			{
				strQj[0] = 163;
				strQj[1] = 173;
				nWord = 2;		
			}else if (*pSrc =='.')
			{
				strQj[0] = 163;
				strQj[1] = 174;
				nWord = 2;		
			}
			else
			{
				strQj[0] = *pSrc;
				strQj[1] = 0;
			}
			
			strcpy(pText,(const char *)strQj);
			pText+=nWord;
			i++;
		}
	}
	
	pQJText[nBufLen] = 0;
	return pQJText;	
}*/

LIBAPI(char*, krnln_QJCase)
{
	PMDATA_INF pArgInf = &ArgInf;
	INT nLen = mystrlen(ArgInf.m_pText);
	if(nLen==0)return NULL;
	LPSTR pszSrc = ArgInf.m_pText;
	BOOL bRet = replaceText(pszSrc,"/","／",FALSE);
	BOOL bFree =FALSE;
	bFree|=bRet;	
	bRet = replaceText(pszSrc,"\\","＼",bFree);
	bFree|=bRet;
	
	nLen = mystrlen(pszSrc);
	INT nBufLen = (nLen+1)*2;
	char *pQJText = (char*)malloc(nBufLen);
	memset(pQJText,0,nBufLen);
	//pQJText[0]=0;
	LCMapString (2052, LCMAP_FULLWIDTH, pszSrc,nLen, pQJText, nBufLen);
	if(bFree)
		free(pszSrc);
	nLen = mystrlen(pQJText);
	char *pText = CloneTextData(pQJText,nLen);
	free(pQJText);
	return pText;
}