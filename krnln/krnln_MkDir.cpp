#include "stdafx.h"

//磁盘操作 - 创建目录
/*
    调用格式： 〈逻辑型〉 创建目录 （文本型 欲创建的目录名称） - 系统核心支持库->磁盘操作
    英文名称：MkDir
    创建一个新的目录。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“欲创建的目录名称”，类型为“文本型（text）”。
*/
LIBAPI(BOOL, krnln_MkDir)
{
	SECURITY_ATTRIBUTES SecAttrib;
	SecAttrib.nLength=sizeof(SECURITY_ATTRIBUTES);
	SecAttrib.lpSecurityDescriptor = NULL;
	SecAttrib.bInheritHandle = FALSE;
	
	return CreateDirectory(ArgInf.m_pText,&SecAttrib);//创建目录
}
