#include "stdafx.h"

//系统处理 - 延时
/*
    调用格式： 〈无返回值〉 延时 （整数型 欲等待的时间） - 系统核心支持库->系统处理
    英文名称：sleep
    本命令暂停当前程序的运行并等待指定的时间。本命令为初级命令。
    参数<1>的名称为“欲等待的时间”，类型为“整数型（int）”。本参数指定欲暂停程序执行的时间，单位为毫秒。
*/
LIBAPI(void, krnln_sleep)
{
	if (ArgInf.m_int <= 0)
		return;
	
	Sleep(ArgInf.m_int);
}
