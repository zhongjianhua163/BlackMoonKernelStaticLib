#include "stdafx.h"

//文件读写 - 关闭文件
/*
    调用格式： 〈无返回值〉 关闭文件 （整数型 欲关闭的文件号） - 系统核心支持库->文件读写
    英文名称：close
    关闭被打开的各种类型文件。本命令为初级命令。
    参数<1>的名称为“欲关闭的文件号”，类型为“整数型（int）”。参数值指明欲关闭的文件号，该文件号由“打开文件”命令所返回。
*/
LIBAPI(void, krnln_close)
{
	if(ArgInf.m_pCompoundData)
		CloseEfile((PFILEELEMENT)ArgInf.m_pCompoundData);
}
