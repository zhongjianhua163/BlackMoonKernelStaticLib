#include "stdafx.h"

//文本操作 - 取空白文本
/*
    调用格式： 〈文本型〉 取空白文本 （整数型 重复次数） - 系统核心支持库->文本操作
    英文名称：space
    返回具有指定数目半角空格的文本。本命令为初级命令。
    参数<1>的名称为“重复次数”，类型为“整数型（int）”。
*/
LIBAPI(char*, krnln_space)
{
	if(ArgInf.m_int<= 0) return NULL;
	char *pText = (char*)E_MAlloc_Nzero(ArgInf.m_int+1);
	memset(pText,32,ArgInf.m_int);
	pText[ArgInf.m_int]=0;
	return pText;	
}
