#include "stdafx.h"

//位运算 - 右移
/*
    调用格式： 〈整数型〉 右移 （整数型 欲移动的整数，整数型 欲移动的位数） - 系统核心支持库->位运算
    英文名称：shr
    将某整数的数据位右移指定位数，返回移动后的结果。本命令为中级命令。
    参数<1>的名称为“欲移动的整数”，类型为“整数型（int）”。
    参数<2>的名称为“欲移动的位数”，类型为“整数型（int）”。
*/
LIBAPI(int, krnln_shr)
{
	PMDATA_INF pArg = &ArgInf;
	int n = pArg->m_int >> pArg[1].m_int;

	return n;
}
