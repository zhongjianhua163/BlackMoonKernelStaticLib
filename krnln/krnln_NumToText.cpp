#include "stdafx.h"
#include <stdio.h>
#include "LTrimZeroChr.h"
#include "Myfunctions.h"

//数值转换 - 数值到格式文本 
/*
    调用格式： 〈文本型〉 数值到格式文本 （双精度小数型 欲转换为文本的数值，［整数型 小数保留位数］，逻辑型 是否进行千分位分隔） - 系统核心支持库->数值转换
    英文名称：NumToText
    返回一个文本，代表指定数值被格式转换后的结果。本命令为初级命令。
    参数<1>的名称为“欲转换为文本的数值”，类型为“双精度小数型（double）”。
    参数<2>的名称为“小数保留位数”，类型为“整数型（int）”，可以被省略。如果大于0，表示小数点右边应四舍五入保留的位数；如果等于0，表示舍入到整数；如果小于0，表示小数点左边舍入到的位置。例如：数值到格式文本 (1056.65, 1, 假) 返回 “1056.7”； 数值到格式文本 (1056.65, 0, 假) 返回 “1057”； 数值到格式文本 (1056.65, -1, 假) 返回 “1060”。如果省略本参数，则默认为保留所有实际存在的小数位。
    参数<3>的名称为“是否进行千分位分隔”，类型为“逻辑型（bool）”，初始值为“假”。如果参数值为真，数值文本的每个千分位上都将被自动插入一个逗号进行分隔。
*/
LIBAPI(char*, krnln_NumToText)
{
	PMDATA_INF pArgInf = &ArgInf;
	char str [MAX_PATH];
	char strFomar [MAX_PATH];
	if(pArgInf[1].m_dtDataType == _SDT_NULL)
	{
		strcpy(strFomar,"%lf");
		
	}
	else
	{
		INT nNum = pArgInf[1].m_int;
		if(nNum <0)
			nNum = 0;
		if(nNum>8)
			nNum = 8;
		sprintf(&strFomar[1],".%dlf",nNum);
		strFomar[0]='%';
	}

	sprintf(str,strFomar,ArgInf.m_double);
	if(pArgInf[1].m_dtDataType == _SDT_NULL)
		LTrimZeroChr(str);

	if(pArgInf[2].m_bool)
	{
		strcpy(strFomar,str);
		LPSTR pStr = strFomar;
		while(*pStr!=0 && *pStr !='.')
			pStr++;
		INT nNum = pStr - strFomar;
		pStr = strFomar;
		if(strFomar[0]=='-')
		{
			nNum--;
			pStr++;
		}
		if(nNum>3)
		{
			INT nMax = nNum/3;
			INT nMod = nNum % 3;
			if(nMod)
				nMax++;
			INT i = 0;
			LPSTR pSrc = strFomar;
			LPSTR pDest = str;
			
			while(i<nMax)
			{
				if(i==0 && nMod)
					pStr+=nMod;
				else
					pStr+=3;
				nNum = pStr - pSrc;
				
				if(i == nMax-1)
				{
					strcat(pDest,pSrc);
					break;
				}
				strncpy(pDest,pSrc,nNum);
				pDest+=nNum;
				*pDest=',';
				pDest++;
				*pDest=0;
				
				pSrc+=nNum;
				pStr=pSrc;
				i++;
				
			}
		}



	}
	INT nLen = mystrlen(str);
	char *pText = (char*)E_MAlloc(nLen+1);
	strcpy(pText,str);
	return pText;
}