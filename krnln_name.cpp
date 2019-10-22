#include "stdafx.h"

//磁盘操作 - 文件更名
/*
    调用格式： 〈逻辑型〉 文件更名 （文本型 欲更名的原文件或目录名，文本型 欲更改为的现文件或目录名） - 系统核心支持库->磁盘操作
    英文名称：name
    重新命名一个文件或目录。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“欲更名的原文件或目录名”，类型为“文本型（text）”。
    参数<2>的名称为“欲更改为的现文件或目录名”，类型为“文本型（text）”。
*/
LIBAPI(BOOL, krnln_name)
{
	PMDATA_INF pArgInf = &ArgInf;
	return MoveFile(pArgInf[0].m_pText,pArgInf[1].m_pText);
}
