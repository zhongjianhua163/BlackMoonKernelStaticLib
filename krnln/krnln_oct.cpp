#include "stdafx.h"
#include <stdio.h>
//数值转换 - 取八进制文本
/*
    调用格式： 〈文本型〉 取八进制文本 （整数型 欲取进制文本的数值） - 系统核心支持库->数值转换
    英文名称：oct
    返回一个文本，代表指定数值的八进制形式。本命令为初级命令。
    参数<1>的名称为“欲取进制文本的数值”，类型为“整数型（int）”。
*/
LIBAPI(char*, krnln_oct)
{
	char *pText = (char*)E_MAlloc_Nzero(256);
	sprintf(pText,"%o",ArgInf.m_int);
	return pText;
}
