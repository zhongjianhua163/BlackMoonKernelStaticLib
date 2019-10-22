#include "stdafx.h"
#include <math.h>
//时间操作 - 取日期
/*
    调用格式： 〈日期时间型〉 取日期 （日期时间型 时间） - 系统核心支持库->时间操作
    英文名称：GetDatePart
    返回一个日期时间型数据的日期部分，其小时、分钟、秒被固定设置为0时0分0秒。本命令为初级命令。
    参数<1>的名称为“时间”，类型为“日期时间型（date）”。
*/
LIBAPI(void, krnln_GetDatePart) // 直接修改eax和edx,所以不需要指定返回值类型
{
	DATE objDate;
	DATE dt = modf(ArgInf.m_date,&objDate);
	ArgInf.m_date = objDate;
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}
}
