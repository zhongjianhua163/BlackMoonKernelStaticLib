#include "stdafx.h"

//磁盘操作 - 取文件尺寸
/*
    调用格式： 〈整数型〉 取文件尺寸 （文本型 文件名） - 系统核心支持库->磁盘操作
    英文名称：FileLen
    返回一个文件的长度，单位是字节。如果该文件不存在，将返回 -1。本命令为初级命令。
    参数<1>的名称为“文件名”，类型为“文本型（text）”。
*/
LIBAPI(int, krnln_FileLen)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = FindFirstFile(ArgInf.m_pText, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		FindClose(hFind);
		if (FindFileData.nFileSizeHigh == 0xFFFFFFFF)
			return -1;
		return FindFileData.nFileSizeLow;
	}
	return -1;
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
// 	if(hFile == INVALID_HANDLE_VALUE)
// 		return -1;
// 	DWORD FileSizeLow,FileSizeHigh;
// 	FileSizeLow = GetFileSize(hFile,&FileSizeHigh);
// 	CloseHandle(hFile);
// 	if(0xFFFFFFFF == FileSizeHigh)
// 		return -1;
// 	return FileSizeLow;
// }
