#include "stdafx.h"
#include <SHLWAPI.h>
#pragma comment(lib,"SHLWAPI.lib") 
//磁盘操作 - 文件是否存在
/*
    调用格式： 〈逻辑型〉 文件是否存在 （文本型 欲测试的文件名称） - 系统核心支持库->磁盘操作
    英文名称：IsFileExist
    判断指定的磁盘文件是否真实存在。如存在返回真，否则返回假。本命令为初级命令。
    参数<1>的名称为“欲测试的文件名称”，类型为“文本型（text）”。
*/
LIBAPI(BOOL, krnln_IsFileExist)
{
	return PathFileExists(ArgInf.m_pText);
}
