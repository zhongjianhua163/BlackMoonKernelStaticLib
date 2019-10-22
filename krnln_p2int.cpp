#include "stdafx.h"
/*
	调用格式： 〈整数型〉指针到整数 (整数型 内存数据指针)
	英文名称：p2int
	返回指定内存指针所指向地址处的一个整数(INT)，注意调用本命令前一定要确保所提供的内存地址段真实有效。
	参数<1>的名称为“内存数据指针”，类型为“整数型”。本参数提供指向一个内存地址的指针值
*/	
LIBAPI(int, krnln_p2int)
{
	PMDATA_INF pArgInf = &ArgInf;
	//if(!IsBadReadPtr((LPVOID)pArgInf[0].m_int,sizeof(int)))
	if(pArgInf[0].m_int!=0)
	{
		return *((int*)pArgInf [0].m_int);
	}
	return 0;
}
