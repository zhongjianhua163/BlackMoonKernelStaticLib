#include "stdafx.h"
#include <math.h>
//时间操作 - 取日
/*
    调用格式： 〈整数型〉 取日 （日期时间型 时间） - 系统核心支持库->时间操作
    英文名称：day
    返回一个值为 1 到 31 之间的整数，表示一个月中的某一日。本命令为初级命令。
    参数<1>的名称为“时间”，类型为“日期时间型（date）”。
*/
LIBAPI(int, krnln_day)
{
	INT nYear, nMonth, nDay;
	GetDatePart(ArgInf.m_date, nYear, nMonth, nDay);
	return nDay;
}
