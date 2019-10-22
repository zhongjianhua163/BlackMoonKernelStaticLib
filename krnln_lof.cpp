#include "stdafx.h"
#include "MyMemFile.h"
//文件读写 - 取文件长度
/*
    调用格式： 〈整数型〉 取文件长度 （整数型 文件号） - 系统核心支持库->文件读写
    英文名称：lof
    返回指定被打开文件的尺寸，该尺寸以字节为单位。如果给定文件号无效或失败，返回 -1 。本命令为初级命令。
    参数<1>的名称为“文件号”，类型为“整数型（int）”。参数值指明欲操作的文件号，该文件号必须由“打开文件”命令所返回。
*/
LIBAPI(int, krnln_lof)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return -1;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return -1;
	INT nRet = -1;

	if(pFile->nType ==1 || pFile->nType == 3)//磁盘文件 加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		DWORD dwHi;
		nRet = ::GetFileSize(hFile,&dwHi);


	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;
		nRet = pMemFile->GetFileSize();
	}
	return nRet;
}
