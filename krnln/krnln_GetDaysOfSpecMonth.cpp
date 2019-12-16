#include "stdafx.h"

//时间操作 - 取某月天数
/*
    调用格式： 〈整数型〉 取某月天数 （整数型 年份，整数型 月份） - 系统核心支持库->时间操作
    英文名称：GetDaysOfSpecMonth
    返回指定月份所包含的天数。如果给定的月份无效，返回0。本命令为初级命令。
    参数<1>的名称为“年份”，类型为“整数型（int）”。参数值从 100 到 9999。
    参数<2>的名称为“月份”，类型为“整数型（int）”。参数值从 1 到 12。
*/
LIBAPI(int, krnln_GetDaysOfSpecMonth)
{
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[1].m_int <=0 || pArgInf[1].m_int >12 || pArgInf[0].m_int <100 || pArgInf[1].m_int>9999)
		return 0;
	return GetDaysOfSpecMonth(pArgInf[0].m_int,pArgInf[1].m_int);

}
