#include "stdafx.h"
#include <math.h>
//算术运算 - 绝对取整
/*
    调用格式： 〈整数型〉 绝对取整 （双精度小数型 欲取整的小数） - 系统核心支持库->算术运算
    英文名称：fix
    返回一个小数的整数部分。本命令与“取整”命令不相同之处为：
如果给定小数为负数，则本命令返回大于或等于该小数的第一个负整数，而“取整”命令则会返回小于或等于该小数的第一个负整数。例如，本命令将 -7.8 转换成 -7，而“取整”命令将 -7.8 转换成 -8。本命令为初级命令。
    参数<1>的名称为“欲取整的小数”，类型为“双精度小数型（double）”。
*/
double __cdecl ProcessDouble2(double a1)
{
  double v1; // st7@1
  double result; // st7@6
  double v3; // [sp+0h] [bp-8h]@1
  signed int v4; // [sp+Ch] [bp+4h]@4

  v1 = modf(a1, &v3);
  if ( v1 < 0.0 )
    v1 = -v1;
  if ( v1 <= 0.999999999999 )
  {
    result = a1;
  }
  else
  {
    v4 = -1;
    if ( v3 >= 0.0 )
      v4 = 1;
    result = (double)v4 + v3;
  }
  return result;
}

LIBAPI(int, krnln_fix)
{
	INT nRet;
/*	if(0<ArgInf.m_double)
		nRet = floor(ArgInf.m_double);
	else
		nRet = ceil(ArgInf.m_double);*/
	double v5;
	modf(ProcessDouble2(ArgInf.m_double), &v5);
	nRet = (INT)v5;
	return nRet;
}
