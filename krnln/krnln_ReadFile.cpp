#include "stdafx.h"

//磁盘操作 - 读入文件
/*
    调用格式： 〈字节集〉 读入文件 （文本型 文件名） - 系统核心支持库->磁盘操作
    英文名称：ReadFile
    返回一个字节集，其中包含指定文件的所有数据。本命令为初级命令。
    参数<1>的名称为“文件名”，类型为“文本型（text）”。
*/
LIBAPI(void*, krnln_ReadFile)
{
	HANDLE hFile = CreateFile(ArgInf.m_pText,
		GENERIC_READ,
		FILE_SHARE_READ|FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_ARCHIVE,
		0);
	LPBYTE pData = NULL;

	if(hFile != INVALID_HANDLE_VALUE)
	{

		DWORD dwNumOfByteRead;
		INT nLen = GetFileSize(hFile, &dwNumOfByteRead);
		pData =  (LPBYTE)E_MAlloc_Nzero(nLen+2*sizeof(INT));
		*(LPINT)pData = 1;
		*(LPINT)(pData + sizeof(INT)) = nLen;
		INT nRet = ReadFile(hFile, pData + 2*sizeof(INT), nLen, &dwNumOfByteRead, 0);
		CloseHandle(hFile);
	}
	return pData;
}
