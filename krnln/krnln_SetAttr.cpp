#include "stdafx.h"

//磁盘操作 - 置文件属性
/*
    调用格式： 〈逻辑型〉 置文件属性 （文本型 欲设置其属性的文件名称，整数型 欲设置为的属性值） - 系统核心支持库->磁盘操作
    英文名称：SetAttr
    为一个文件设置属性信息。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“欲设置其属性的文件名称”，类型为“文本型（text）”。
    参数<2>的名称为“欲设置为的属性值”，类型为“整数型（int）”。参数值可以为以下常量值或其和： 1、#只读文件； 2、#隐藏文件； 4、#系统文件； 32、#存档文件 。通过将这些常量值加起来可以一次设置多个文件属性。
*/
LIBAPI(BOOL, krnln_SetAttr)
{
	PMDATA_INF pArgInf = &ArgInf;
	return SetFileAttributes (pArgInf[0].m_pText,pArgInf[1].m_int);
}
