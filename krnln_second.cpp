#include "stdafx.h"
#include <math.h>
//时间操作 - 取秒
/*
    调用格式： 〈整数型〉 取秒 （日期时间型 时间） - 系统核心支持库->时间操作
    英文名称：second
    返回一个值为 0 到 59 之间的整数，表示一分钟中的某一秒。本命令为初级命令。
    参数<1>的名称为“时间”，类型为“日期时间型（date）”。
*/
LIBAPI(int, krnln_second)
{
	DATE objDate;
	DATE dt = modf(ArgInf.m_date,&objDate);
	INT nHour, nMinute, nSecond;
	GetTimePart(dt,nHour, nMinute, nSecond);
	return nSecond;
}
