#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include "Myfunctions.h"

char bigChn []= "零\0壹\0贰\0叁\0肆\0伍\0陆\0柒\0捌\0玖\0";//48-57
char smlChn []= "零\0一\0二\0三\0四\0五\0六\0七\0八\0九\0";
char strNumLeven1 []= "万\0仟\0佰\0拾\0\0";
char strNumLeven2 []= "万\0千\0百\0十\0\0";

BOOL ReadChnNum(LPSTR pText,LPSTR pStrSrc,LPSTR pNumStr,LPSTR pNumLeven,INT nNum,INT& nPre)
{

	pNumLeven += ((5-nNum)*3);
	BOOL bAllZero = TRUE;

	for(INT i=0;i<nNum;i++)
	{
		INT nOffset = pStrSrc[i]-48;
		LPSTR pStr = pNumStr + nOffset*3;

		if(nOffset !=0)
		{
			if(nPre ==0)
				strcat(pText,"零");
			strcat(pText,pStr);
			pStr = pNumLeven + i*3;
			strcat(pText,pStr);
			bAllZero = FALSE;
		}
		nPre = nOffset;

	}
	return bAllZero;

}
LPSTR IntNumToChn (double dNum,BOOL bSml,INT& nPre)
{
	char str [MAX_PATH];
	LPSTR pText = NULL;
	sprintf(str,"%.0lf",dNum);
	INT nLen = mystrlen(str);
	if(nLen>13)
	{
		pText = (LPSTR)malloc (3);
		strcpy(pText,"溢出");
		return pText;
	}
	pText = (LPSTR)malloc (nLen*4+4);
	*pText=0;
	LPSTR pNum;
	LPSTR pNumLeven;
	if(bSml)
	{
		pNum = smlChn;
		pNumLeven = strNumLeven2;
	}
	else
	{
		pNum = bigChn;
		pNumLeven = strNumLeven1;
	}

	LPSTR pSrc = str;
	if(*pSrc==45)
	{
		pSrc++;
		strcat(pText,"负");
	}
	//万仟佰拾亿-仟佰拾万-仟佰拾个
	nPre = -1;
	if(nLen > 8)
	{
		INT nNum = nLen - 8;
		ReadChnNum(pText,pSrc,pNum,pNumLeven,nNum,nPre);
		strcat(pText,"亿");
		pSrc+=nNum;
		BOOL nAll0 = ReadChnNum(pText,pSrc,pNum,pNumLeven,4,nPre);
		if(!nAll0)
			//strcat(pText,"零");
		//else
			strcat(pText,"万");
		pSrc+=4;
		ReadChnNum(pText,pSrc,pNum,pNumLeven,4,nPre);


	}else if(nLen > 4)
	{
		INT nNum = nLen - 4;
		ReadChnNum(pText,pSrc,pNum,pNumLeven,nNum,nPre);
		strcat(pText,"万");
		pSrc+=nNum;
		ReadChnNum(pText,pSrc,pNum,pNumLeven,4,nPre);
	}
	else 
	{
		ReadChnNum(pText,pSrc,pNum,pNumLeven,nLen,nPre);
	}


	
	return pText;
	

}
LPSTR FloatNumToChn (double dNum,BOOL bSml)//这里不能代入0值
{
	char str [MAX_PATH];
	dNum = fabs(dNum);

	sprintf(str,"%.2lf",dNum);
	LPSTR pSrc = str;
	while(*pSrc !=0 && *pSrc != '.')
		pSrc++;
	if(*pSrc ==0)
		return NULL;
	pSrc++;

	LPSTR pNum;

	if(bSml)
		pNum = smlChn;
	else
		pNum = bigChn;

	LPSTR pText = (LPSTR)malloc (64);
	strcpy(pText,"点");

	INT nOffset = pSrc[0]-48;
	LPSTR pStr = pNum + nOffset*3;
	strcat(pText,pStr);
	nOffset = pSrc[1]-48;
	if(nOffset)
	{
		pStr = pNum + nOffset*3;
		strcat(pText,pStr);
	}

	return pText;
}

LPSTR FloatNumToRMB (double dNum,BOOL bSml)//这里不能代入0值
{
	char str [MAX_PATH];
	dNum = fabs(dNum);

	sprintf(str,"%.2lf",dNum);
	LPSTR pSrc = str;
	while(*pSrc !=0 && *pSrc != '.')
		pSrc++;
	if(*pSrc ==0)
		return NULL;
	pSrc++;

	LPSTR pNum;

	if(bSml)
		pNum = smlChn;
	else
		pNum = bigChn;

	LPSTR pText = (LPSTR)malloc (64);
	*pText=0;


	INT nOffset = pSrc[0]-48;
	if(nOffset)
	{
		LPSTR pStr = pNum + nOffset*3;
		strcat(pText,pStr);
		strcat(pText,"角");
	}
	nOffset = pSrc[1]-48;
	if(nOffset)
	{
		LPSTR pStr = pNum + nOffset*3;
		strcat(pText,pStr);
		strcat(pText,"分");
	}

	return pText;
}