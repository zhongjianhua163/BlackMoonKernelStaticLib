#include "stdafx.h"
#include <math.h>
#include "Myfunctions.h"

//数值转换 - 数值到大写 
/*
    调用格式： 〈文本型〉 数值到大写 （双精度小数型 欲转换形式的数值，逻辑型 是否转换为简体） - 系统核心支持库->数值转换
    英文名称：UNum
    将数值转换为简体或繁体的大写形式，返回转换后的文本。本命令为初级命令。
    参数<1>的名称为“欲转换形式的数值”，类型为“双精度小数型（double）”。
    参数<2>的名称为“是否转换为简体”，类型为“逻辑型（bool）”，初始值为“假”。如果参数值为假，则转换为繁体。
*/
LIBAPI(char*, krnln_UNum)
{
	PMDATA_INF pArgInf = &ArgInf;
	double dInt;
	double dFloat = modf(pArgInf[0].m_double,&dInt);
	LPSTR pInt = NULL;
	LPSTR pFloat = NULL;
	INT nLen = 3;
	if(dInt !=0)
	{
		INT nPre=1;
		pInt = IntNumToChn(dInt,pArgInf[1].m_bool,nPre);
		nLen += mystrlen(pInt);
	}

	if(dFloat !=0)
	{
		pFloat = FloatNumToChn(dFloat,pArgInf[1].m_bool);
		if(pFloat)
			nLen += mystrlen(pFloat);
	}
	LPSTR pText = (LPSTR)E_MAlloc (nLen);
//	*pText=0;MessageBox(NULL,pText,NULL,MB_OK);
	if(pInt)
	{
		strcpy(pText,pInt);
		free(pInt);
	}else
		strcpy(pText,"零");

	if(pFloat)
	{
		strcat(pText,pFloat);
		free(pFloat);
	}

	return pText;	
}
