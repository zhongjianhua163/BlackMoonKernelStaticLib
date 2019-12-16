#include "stdafx.h"

//磁盘操作 - 写到文件
/*
    调用格式： 〈逻辑型〉 写到文件 （文本型 文件名，字节集 欲写入文件的数据，... ） - 系统核心支持库->磁盘操作
    英文名称：WriteFile
    本命令用作将一个或数个字节集顺序写到指定文件中，文件原有内容被覆盖。成功返回真，失败返回假。本命令为初级命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“文件名”，类型为“文本型（text）”。
    参数<2>的名称为“欲写入文件的数据”，类型为“字节集（bin）”。
*/
LIBAPI(BOOL, krnln_WriteFile)
{
	PMDATA_INF pArgInf = &ArgInf;
	HANDLE hFile = CreateFile(ArgInf.m_pText,
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_ARCHIVE,
		0);
	
	BOOL bRet = FALSE;
	if(hFile != INVALID_HANDLE_VALUE)
	{

		DWORD dwNumOfByteRead;
		bRet = TRUE;
		for(INT i=1;i < nArgCount;i++)
		{
			LPBYTE pData = pArgInf[i].m_pBin + 2*sizeof(INT);
			INT nLen = pArgInf[i].m_pInt[1];

			if(WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL)==FALSE)
			{
				bRet = FALSE;
				break;
			}
/*			if(FlushFileBuffers(hFile)==FALSE)
			{
				bRet = FALSE;
				break;
			}*/
		}
		CloseHandle(hFile);
	}
	return bRet;
}
