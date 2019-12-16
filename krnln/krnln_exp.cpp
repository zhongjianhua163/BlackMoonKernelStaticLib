#include "stdafx.h"
#include <math.h>
//算术运算 - 求反对数
/*
    调用格式： 〈双精度小数型〉 求反对数 （双精度小数型 欲求其反对数的数值） - 系统核心支持库->算术运算
    英文名称：exp
    返回 e（自然对数的底）的某次方。本命令为初级命令。
    参数<1>的名称为“欲求其反对数的数值”，类型为“双精度小数型（double）”。如果参数值超过 709.782712893，将导致计算溢出。
*/
LIBAPI(void, krnln_exp) // 直接修改eax和edx的值，所以无需指定返回值类型。
{
	ArgInf.m_double = exp(ArgInf.m_double);
	__asm
	{
		mov eax,ArgInf.m_unit.m_dwFormID;
		mov edx,ArgInf.m_unit.m_dwUnitID;
	}
}
