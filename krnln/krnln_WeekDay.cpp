#include "stdafx.h"

//时间操作 - 取星期几
/*
    调用格式： 〈整数型〉 取星期几 （日期时间型 时间） - 系统核心支持库->时间操作
    英文名称：WeekDay
    返回一个值为 1 到 7 之间的整数，表示一个星期中的某一日。星期日为 1，星期一为 2，依此类推。本命令为初级命令。
    参数<1>的名称为“时间”，类型为“日期时间型（date）”。
*/
LIBAPI(int, krnln_WeekDay)
{
	return GetWeekDay(ArgInf.m_date);
}
