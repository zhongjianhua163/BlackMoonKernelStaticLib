#include "stdafx.h"

//字节集操作 - 指针到字节集
/*
    调用格式： 〈字节集〉 指针到字节集 （整数型 内存数据指针，整数型 内存数据长度） - 系统核心支持库->字节集操作
    英文名称：pbin
    返回指定内存指针所指向地址处的一段数据，注意调用本命令前一定要确保所提供的内存地址段真实有效。本命令的最佳使用场合就是在易语言回调子程序和易语言DLL公开子程序用作获取外部数据。本命令为高级命令。
    参数<1>的名称为“内存数据指针”，类型为“整数型（int）”。本参数提供指向一个内存地址的指针值。
    参数<2>的名称为“内存数据长度”，类型为“整数型（int）”。本参数提供该内存地址处所需获取的数据长度。
*/
LIBAPI(void*, krnln_pbin)
{
	PMDATA_INF pArgInf = &ArgInf;
	if (!pArgInf[0].m_pCompoundData) return NULL;
	INT nLen = pArgInf[1].m_int;
	if(nLen<=0) return NULL; // || IsBadReadPtr(pArgInf[0].m_pCompoundData,nLen)

	LPINT pText = (LPINT)E_MAlloc_Nzero(nLen+2*sizeof(INT));
	pText[0]=1;
	pText[1]=nLen;
	memcpy(pText+2,pArgInf[0].m_pCompoundData,nLen);

	return pText;
}
