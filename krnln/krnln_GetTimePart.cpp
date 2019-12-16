#include "stdafx.h"
#include <math.h>
//时间操作 - 取时间
/*
    调用格式： 〈日期时间型〉 取时间 （日期时间型 时间） - 系统核心支持库->时间操作
    英文名称：GetTimePart
    返回一个日期时间型数据的时间部分，其年、月、日被固定设置为2000年1月1日。本命令为初级命令。
    参数<1>的名称为“时间”，类型为“日期时间型（date）”。
*/
LIBAPI(void, krnln_GetTimePart) // 直接修改了Eax和edx，所以不需要指定返回值类型
{
	DATE objDate;
	DATE dt = modf(ArgInf.m_date,&objDate);
	INT nHour, nMinute, nSecond;
	GetTimePart(dt,nHour, nMinute, nSecond);
	ArgInf.m_date = GetSpecDateTime(2000,1,1,nHour, nMinute, nSecond);
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}
}
