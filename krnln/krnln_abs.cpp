#include "stdafx.h"
#include <math.h>
//算术运算 - 取绝对值
/*
    调用格式： 〈双精度小数型〉 取绝对值 （双精度小数型 欲取其绝对值的数值） - 系统核心支持库->算术运算
    英文名称：abs
    如果所提供数值为字节型，则将直接返回该数值。本命令为初级命令。
    参数<1>的名称为“欲取其绝对值的数值”，类型为“双精度小数型（double）”。
*/
LIBAPI(void, krnln_abs)
{
	ArgInf.m_double = fabs(ArgInf.m_double);
	__asm
	{
		mov eax,ArgInf.m_unit.m_dwFormID;
		mov edx,ArgInf.m_unit.m_dwUnitID;
	}
}
