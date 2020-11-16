#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include "Myfunctions.h"

//时间操作 - 时间到文本
/*
    调用格式： 〈文本型〉 时间到文本 （日期时间型 欲转换到文本的时间，［整数型 转换部分］） - 系统核心支持库->时间操作
    英文名称：TimeToText
    将指定时间转换为文本并返回。本命令为初级命令。
    参数<1>的名称为“欲转换到文本的时间”，类型为“日期时间型（date）”。
    参数<2>的名称为“转换部分”，类型为“整数型（int）”，可以被省略。参数值可以为以下常量：
	1、#全部转换； 2、#日期部分； 3、#时间部分。如果省略了本参数，默认为“#全部转换”。
*/
LIBAPI(char*, krnln_TimeToText)
{
	PMDATA_INF pArgInf = &ArgInf;
	char str[128];
	if(pArgInf[1].m_int==2)
	{
		DateTimeFormat(str,ArgInf.m_date,TRUE);

	}else if(pArgInf[1].m_int==3)
	{
		INT nHour, nMinute, nSecond;
		GetTimePart(ArgInf.m_date, nHour, nMinute, nSecond);
		sprintf(str,"%d时%d分%d秒",nHour, nMinute, nSecond);

	}else{
		DateTimeFormat(str, ArgInf.m_date);
	}
	INT nLen = mystrlen(str);
	char* pText = (char*)E_MAlloc_Nzero(nLen+1);
	strcpy(pText,str);
	return pText;

}
