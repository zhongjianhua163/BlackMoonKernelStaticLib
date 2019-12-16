#include "stdafx.h"
#include <math.h>

//算术运算 - 求正弦
/*
    调用格式： 〈双精度小数型〉 求正弦 （双精度小数型 欲进行计算的角） - 系统核心支持库->算术运算
    英文名称：sin
    返回指定角的正弦值。本命令为初级命令。
    参数<1>的名称为“欲进行计算的角”，类型为“双精度小数型（double）”。所使用单位为弧度。为了将角度转换成弧度，请将角度乘以 #pi / 180。为了将弧度转换成角度，请将弧度乘以 180 / #pi。如果参数值大于等于 2 的 63 次方，或者小于等于 -2 的 63 次方，将导致计算溢出。
*/
LIBAPI(void, krnln_sin)
{

	ArgInf.m_double = sin(ArgInf.m_double);
	__asm
	{
		mov eax,ArgInf.m_unit.m_dwFormID;
		mov edx,ArgInf.m_unit.m_dwUnitID;
	}

}
