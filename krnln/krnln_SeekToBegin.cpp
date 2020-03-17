#include "stdafx.h"
#include "MyMemFile.h"
//文件读写 - 移到文件首
/*
    调用格式： 〈逻辑型〉 移到文件首 （整数型 欲进行操作的文件号） - 系统核心支持库->文件读写
    英文名称：SeekToBegin
    在被打开的文件中，设置下一个读或写操作的位置到文件首。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“欲进行操作的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
*/
LIBAPI(BOOL, krnln_SeekToBegin)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return FALSE;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return FALSE;

	BOOL bRet = FALSE;

	if(pFile->nType ==1 || pFile->nType == 3)//磁盘文件 加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		bRet = SetFilePointer(hFile,0,NULL,FILE_BEGIN)!= HFILE_ERROR;

	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;
		bRet = (pMemFile->Seek(0,CMyMemFile::begin) != -1);

	}
	return bRet;
}
