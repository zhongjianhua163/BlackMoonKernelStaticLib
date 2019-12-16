#include "stdafx.h"

//字节集操作 - 取空白字节集
/*
    调用格式： 〈字节集〉 取空白字节集 （整数型 零字节数目） - 系统核心支持库->字节集操作
    英文名称：SpaceBin
    返回具有特定数目 0 字节的字节集。本命令为初级命令。
    参数<1>的名称为“零字节数目”，类型为“整数型（int）”。
*/
LIBAPI(void*, krnln_SpaceBin)
{
	if(ArgInf.m_int <=0)return NULL;
	LPINT pData = (LPINT)E_MAlloc(ArgInf.m_int+2*sizeof(INT));
	pData[0]=1;
	pData[1]=ArgInf.m_int;
	return pData;
}
