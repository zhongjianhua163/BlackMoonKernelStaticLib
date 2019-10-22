#include "stdafx.h"

//文件读写 - 关闭所有文件
/*
    调用格式： 〈无返回值〉 关闭所有文件 （） - 系统核心支持库->文件读写
    英文名称：reset
    关闭所有现行被打开的文件。本命令为初级命令。
*/
extern PFILEELEMENT pFileList;

LIBAPI(void, krnln_reset)
{
	if(pFileList)
		ResetFileIO();
}
