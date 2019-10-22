#include "stdafx.h"

//时间操作 - 取现行时间
/*
    调用格式： 〈日期时间型〉 取现行时间 （） - 系统核心支持库->时间操作
    英文名称：now
    返回当前系统日期及时间。本命令为初级命令。
*/
LIBAPI(void, krnln_now)
{
	SYSTEMTIME now;
	MDATA_INF ArgInf2;
	GetLocalTime(&now);
	ArgInf2.m_double = GetSpecDateTime(now.wYear, now.wMonth, now.wDay, now.wHour, now.wMinute, now.wSecond);
	__asm{
		mov eax, ArgInf2.m_unit.m_dwFormID;
		mov edx, ArgInf2.m_unit.m_dwUnitID;
	}
}
