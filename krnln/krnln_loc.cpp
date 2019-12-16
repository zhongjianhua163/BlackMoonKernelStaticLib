#include "stdafx.h"
#include "MyMemFile.h"
//文件读写 - 取读写位置
/*
    调用格式： 〈整数型〉 取读写位置 （整数型 文件号） - 系统核心支持库->文件读写
    英文名称：loc
    返回指定被打开文件的当前读/写位置，位置值从 0 开始。如果给定文件号无效或失败，返回 -1 。本命令为初级命令。
    参数<1>的名称为“文件号”，类型为“整数型（int）”。参数值指明欲操作的文件号，该文件号必须由“打开文件”命令所返回。
*/
LIBAPI(int, krnln_loc)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return -1;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return -1;
	INT nRet = HFILE_ERROR;

	if(pFile->nType == 1 || pFile->nType == 3)//磁盘文件 加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		nRet = SetFilePointer(hFile,0,NULL,FILE_CURRENT);

	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;
		nRet = pMemFile->GetPosition();
	}
	return nRet;
}
