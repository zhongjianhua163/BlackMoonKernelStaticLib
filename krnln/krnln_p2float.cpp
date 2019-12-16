#include "stdafx.h"
/*
	调用格式： 〈小数型〉指针到小数 (整数型 内存数据指针)
	英文名称：p2float
	返回指定内存指针所指向地址处的一个小数(FLOAT)，注意调用本命令前一定要确保所提供的内存地址段真实有效。
	参数<1>的名称为“内存数据指针”，类型为“整数型”。本参数提供指向一个内存地址的指针值
*/
LIBAPI(void, krnln_p2float)
{
	float fRet=0.0f;
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[0].m_int!=0)
	{
		fRet=*((float*)pArgInf [0].m_int);
	}
	_asm mov eax, fRet;
}
