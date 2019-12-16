#include "stdafx.h"
#include <math.h>
//算术运算 - 求自然对数
/*
    调用格式： 〈双精度小数型〉 求自然对数 （双精度小数型 欲求其自然对数的数值） - 系统核心支持库->算术运算
    英文名称：log
    返回指定参数的自然对数值。自然对数是以 e 为底的对数。常量 #e 的值大约是 2.718282。本命令为初级命令。
    参数<1>的名称为“欲求其自然对数的数值”，类型为“双精度小数型（double）”。
*/
LIBAPI(void, krnln_log)
{
	ArgInf.m_double = log(ArgInf.m_double);
	__asm
	{
		mov eax,ArgInf.m_unit.m_dwFormID;
		mov edx,ArgInf.m_unit.m_dwUnitID;
	}
}
