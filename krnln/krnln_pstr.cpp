#include "stdafx.h"
#include "Myfunctions.h"
//文本操作 - 指针到文本
/*
    调用格式： 〈文本型〉 指针到文本 （整数型 内存文本指针） - 系统核心支持库->文本操作
    英文名称：pstr
    返回指定内存指针所指向地址处的文本，注意调用本命令前一定要确保所提供的内存指针真实有效，且指向一个以零字符结束的文本串。本命令的最佳使用场合就是在易语言回调子程序和易语言DLL公开子程序用作获取外部数据。本命令为高级命令。
    参数<1>的名称为“内存文本指针”，类型为“整数型（int）”。本参数提供指向一个以零字符结束的文本串内存指针值。
*/
LIBAPI(char*, krnln_pstr)
{
	if (!ArgInf.m_pText || !*(ArgInf.m_pText)) return NULL;
	int nLen = mystrlen(ArgInf.m_pText);
	if(nLen==0)	return NULL;

	char *pText = (char*)E_MAlloc_Nzero(nLen+1);
	
	memcpy(pText, ArgInf.m_pText, nLen);
	pText[nLen] = '\0';
	return pText;
}
