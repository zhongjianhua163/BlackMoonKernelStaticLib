#include "stdafx.h"

//磁盘操作 - 复制文件
/*
    调用格式： 〈逻辑型〉 复制文件 （文本型 被复制的文件名，文本型 复制到的文件名） - 系统核心支持库->磁盘操作
    英文名称：FileCopy
    成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“被复制的文件名”，类型为“文本型（text）”。
    参数<2>的名称为“复制到的文件名”，类型为“文本型（text）”。

*/
LIBAPI(BOOL, krnln_FileCopy)
{
	PMDATA_INF pArgInf = &ArgInf;
	return CopyFile(pArgInf[0].m_pText,pArgInf[1].m_pText,FALSE);
}
