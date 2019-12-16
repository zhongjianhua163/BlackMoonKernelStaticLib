#include "stdafx.h"

//文本操作 - 字符
/*
    调用格式： 〈文本型〉 字符 （字节型 欲取其字符的字符代码） - 系统核心支持库->文本操作
    英文名称：chr
    返回一个文本，其中包含有与指定字符代码相关的字符。本命令为初级命令。
    参数<1>的名称为“欲取其字符的字符代码”，类型为“字节型（byte）”。
*/
LIBAPI(char*, krnln_chr)
{
	if(ArgInf.m_byte==0)return NULL;

	char *pText = (char*)E_MAlloc_Nzero(2);
	pText[0]=ArgInf.m_byte;
	pText[1]=0;
	return pText;	
}
