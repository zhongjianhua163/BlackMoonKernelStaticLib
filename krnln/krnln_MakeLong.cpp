#include "stdafx.h"

//位运算 - 合并整数
/*
    调用格式： 〈整数型〉 合并整数 （整数型 用作合并的整数1，整数型 用作合并的整数2） - 系统核心支持库->位运算
    英文名称：MakeLong
    将第一个整数的低16位放置到结果整数的低16位，将第二个整数的低16位放置到结果整数的高16位，以此合并成一个整数，并返回合并后的结果。本命令为中级命令。
    参数<1>的名称为“用作合并的整数1”，类型为“整数型（int）”。
    参数<2>的名称为“用作合并的整数2”，类型为“整数型（int）”。
*/
LIBAPI(int, krnln_MakeLong)
{
	PMDATA_INF pArg = &ArgInf;
	int n = MAKELONG (pArg[0].m_int, pArg[1].m_int);
	return n;
}
