#include "stdafx.h"
#include <stdio.h>
//数值转换 - 取十六进制文本
/*
    调用格式： 〈文本型〉 取十六进制文本 （整数型 欲取进制文本的数值） - 系统核心支持库->数值转换
    英文名称：hex
    返回一个文本，代表指定数值的十六进制形式。本命令为初级命令。
    参数<1>的名称为“欲取进制文本的数值”，类型为“整数型（int）”。
*/
LIBAPI(char*, krnln_hex)
{
	char *pText = (char*)E_MAlloc_Nzero(16);
	sprintf(pText,"%X",ArgInf.m_int);
	return pText;
}
