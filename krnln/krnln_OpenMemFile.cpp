#include "stdafx.h"
#include "MyMemFile.h"
//文件读写 - 打开内存文件
/*
    调用格式： 〈整数型〉 打开内存文件 （） - 系统核心支持库->文件读写
    英文名称：OpenMemFile
    建立一个内存文件，以计算机内存为存储介质对数据进行文件式的快速输入或输出。成功返回被打开文件的文件号，失败返回 0。本命令为初级命令。
*/
LIBAPI(void*, krnln_OpenMemFile)
{
	CMyMemFile* pMemFile = new CMyMemFile();
	if(pMemFile)
	{
		PFILEELEMENT pFile = new FILEELEMENT;
		pFile->nType = 2;
		pFile->FileHandle = pMemFile;
		AddFileMangerList(pFile);
		return pFile;
	}
	return NULL;
}
