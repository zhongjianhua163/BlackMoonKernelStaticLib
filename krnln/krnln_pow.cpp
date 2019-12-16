#include "stdafx.h"
#include <math.h>
//算术运算 - 求次方
/*
    调用格式： 〈双精度小数型〉 求次方 （双精度小数型 欲求次方数值，双精度小数型 次方数） - 系统核心支持库->算术运算
    英文名称：pow
    返回指定数值的指定次方。本命令为初级命令。
    参数<1>的名称为“欲求次方数值”，类型为“双精度小数型（double）”。参数值指定欲求其某次方的数值。
    参数<2>的名称为“次方数”，类型为“双精度小数型（double）”。参数值指定对欲求次方数值的运算指数。
*/
LIBAPI(void, krnln_pow)
{
	PMDATA_INF pArg = &ArgInf;

	ArgInf.m_double = pow(ArgInf.m_double,pArg[1].m_double);

	__asm
	{
		mov eax,ArgInf.m_unit.m_dwFormID;
		mov edx,ArgInf.m_unit.m_dwUnitID;
	}
}
