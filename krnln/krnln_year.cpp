#include "stdafx.h"
#include <math.h>
//时间操作 - 取年份
/*
    调用格式： 〈整数型〉 取年份 （日期时间型 时间） - 系统核心支持库->时间操作
    英文名称：year
    返回一个值为 100 到 9999 之间的整数，表示指定时间中的年份。本命令为初级命令。
    参数<1>的名称为“时间”，类型为“日期时间型（date）”。
*/
LIBAPI(int, krnln_year)
{
	DATE objDate;
	INT nYear, nMonth, nDay;
	DATE dt = modf(ArgInf.m_date,&objDate);
	GetDatePart(objDate,nYear, nMonth, nDay);
	return nYear;
}
