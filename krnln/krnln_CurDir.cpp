#include "stdafx.h"
#include "Myfunctions.h"
//磁盘操作 - 取当前目录
/*
    调用格式： 〈文本型〉 取当前目录 （） - 系统核心支持库->磁盘操作
    英文名称：CurDir
    返回一个文本，用来代表当前的目录。如果失败，返回空文本。本命令为初级命令。
*/
LIBAPI(char*, krnln_CurDir)
{
	char DirName [MAX_PATH];
	char* pText = NULL;

	if(GetCurrentDirectory(MAX_PATH,DirName))
	{
		INT nLen = mystrlen(DirName);
		pText = CloneTextData(DirName,nLen);
	}
	return pText;
}
