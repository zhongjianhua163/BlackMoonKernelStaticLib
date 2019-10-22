#include "stdafx.h"
#include <math.h>
//算术运算 - 求反正切
/*
    调用格式： 〈双精度小数型〉 求反正切 （双精度小数型 欲求其反正切值的数值） - 系统核心支持库->算术运算
    英文名称：atn
    返回指定数的反正切值。本命令为初级命令。
    参数<1>的名称为“欲求其反正切值的数值”，类型为“双精度小数型（double）”。
*/
LIBAPI(void, krnln_atn)
{
	ArgInf.m_double = atan(ArgInf.m_double);
	__asm
	{
		mov eax,ArgInf.m_unit.m_dwFormID;
		mov edx,ArgInf.m_unit.m_dwUnitID;
	}
}
