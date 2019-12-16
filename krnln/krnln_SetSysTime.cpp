#include "stdafx.h"
#include <math.h>
//时间操作 - 置现行时间
/*
    调用格式： 〈逻辑型〉 置现行时间 （日期时间型 欲设置的时间） - 系统核心支持库->时间操作
    英文名称：SetSysTime
    设置当前系统日期及时间。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“欲设置的时间”，类型为“日期时间型（date）”。
*/
LIBAPI(BOOL, krnln_SetSysTime)
{
	SYSTEMTIME now;
	memset(&now,0,sizeof(SYSTEMTIME));
	DATE objDate;
	INT nYear, nMonth, nDay;
	INT nHour, nMinute, nSecond;
	DATE dt = modf(ArgInf.m_date,&objDate);
	GetDatePart(objDate,nYear, nMonth, nDay);
	GetTimePart(dt,nHour, nMinute, nSecond);
	now.wYear = nYear;
	now.wMonth = nMonth;
	now.wDay = nDay;
	now.wHour = nHour;
	now.wMinute = nMinute;
	now.wSecond = nSecond;
	return SetLocalTime(&now);
}
