#include "stdafx.h"
#include <SHLWAPI.h>
#pragma comment(lib,"SHLWAPI.lib") 
//磁盘操作 - 取文件时间
/*
    调用格式： 〈日期时间型〉 取文件时间 （文本型 文件名） - 系统核心支持库->磁盘操作
    英文名称：FileDateTime
    返回指定文件被创建或最后修改后的日期和时间。如果该文件不存在，将返回100年1月1日。本命令为初级命令。
    参数<1>的名称为“文件名”，类型为“文本型（text）”。
	FileTimeToLocalFileTime
	FileTimeToSystemTime 

*/
LIBAPI(void, krnln_FileDateTime) //直接修改了eax和edx所以无需指定返回值类型
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = FindFirstFile(ArgInf.m_pText, &FindFileData);
	ArgInf.m_date =  -657434;//100年1月1日
	if (hFind != INVALID_HANDLE_VALUE)
	{
		FindClose(hFind);
		if(FileTimeToLocalFileTime(&FindFileData.ftLastWriteTime,&FindFileData.ftCreationTime))
		{
			SYSTEMTIME now;
			if(FileTimeToSystemTime (&FindFileData.ftCreationTime,&now))
				ArgInf.m_double = GetSpecDateTime(now.wYear, now.wMonth, now.wDay, now.wHour, now.wMinute, now.wSecond);
		}
	}
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}
}
// {//大鸟原版
// 	HANDLE hFile = CreateFile(ArgInf.m_pText,
// 		GENERIC_READ,
// 		FILE_SHARE_READ|FILE_SHARE_WRITE,
// 		NULL,
// 		OPEN_EXISTING,
// 		FILE_ATTRIBUTE_ARCHIVE,
// 		0);
// 
// 	ArgInf.m_date =  -657434;//100年1月1日
// 	if(hFile != INVALID_HANDLE_VALUE)
// 	{
// 		FILETIME CreationTime,LastWriteTime;
// 		BOOL bRet = GetFileTime(hFile,&CreationTime,NULL,&LastWriteTime);
// 		CloseHandle(hFile);
// 		if(bRet)
// 		{
// 			if(FileTimeToLocalFileTime(&LastWriteTime,&CreationTime))
// 			{
// 				SYSTEMTIME now;
// 				if(FileTimeToSystemTime (&CreationTime,&now))
// 					ArgInf.m_double = GetSpecDateTime(now.wYear, now.wMonth, now.wDay, now.wHour, now.wMinute, now.wSecond);
// 
// 			}
// 
// 
// 		}
// 
// 	}
// 		
// 
// 	__asm{
// 		mov eax, ArgInf.m_unit.m_dwFormID;
// 		mov edx, ArgInf.m_unit.m_dwUnitID;
// 	}
// }
