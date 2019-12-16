#include "stdafx.h"
#include <math.h>
//算术运算 - 置随机数种子
/*
    调用格式： 〈无返回值〉 置随机数种子 （［整数型 欲置入的种子数值］） - 系统核心支持库->算术运算
    英文名称：randomize
    为随机数生成器初始化一个种子值，不同的种子值将导致“取随机数”命令返回不同的随机数系列。本命令为初级命令。
    参数<1>的名称为“欲置入的种子数值”，类型为“整数型（int）”，可以被省略。如果省略本参数，将默认使用当前计算机系统的时钟值。
*/
LIBAPI(void, krnln_randomize)
{
	UINT unSeed;
	if(ArgInf.m_dtDataType==_SDT_NULL)
		unSeed = ::GetTickCount();
	else
		unSeed  = ArgInf.m_dwSubCodeAdr;
	srand(unSeed);

}
