#include "stdafx.h"
#include "limits.h"
#define XCHG(x, y) {x = x^y; y = x^y; x = x^y;}

//算术运算 - 取随机数
/*
    调用格式： 〈整数型〉 取随机数 （［整数型 欲取随机数的最小值］，［整数型 欲取随机数的最大值］） - 系统核心支持库->算术运算
    英文名称：rnd
    返回一个指定范围内的随机数值。在使用本命令取一系列的随机数之前，应该先使用“置随机数种子”命令为随机数生成器初始化一个种子值。本命令为初级命令。
    参数<1>的名称为“欲取随机数的最小值”，类型为“整数型（int）”，可以被省略。参数必须大于或等于零。本参数如果被省略，默认为 0 。
    参数<2>的名称为“欲取随机数的最大值”，类型为“整数型（int）”，可以被省略。参数必须大于或等于零。本参数如果被省略，默认为无限。
*/
LIBAPI(int, krnln_rnd)
{
	PMDATA_INF pArg = &ArgInf;

	register int nMin;
	register int nMax;

	// check for min value
	if (pArg[0].m_dtDataType != _SDT_NULL)
		nMin = pArg[0].m_int < 0 ? 0 : pArg[0].m_int;
	else nMin = 0;

	// check for max value
	if (pArg[1].m_dtDataType != _SDT_NULL)
		nMax = pArg[1].m_int < 0 ? 0 : pArg[1].m_int;
	else nMax = INT_MAX;

	// if min bigger than max
	// xchg them
	if(nMin > nMax)
		XCHG(nMin, nMax);
	
	return nMin + (rand() % (nMax - nMin + 1));

}
