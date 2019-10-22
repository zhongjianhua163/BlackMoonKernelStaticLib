#include "stdafx.h"
#include "Myfunctions.h"

//磁盘操作 - 取磁盘剩余空间
/*
    调用格式： 〈整数型〉 取磁盘剩余空间 （［文本型 磁盘驱动器字符］） - 系统核心支持库->磁盘操作
    英文名称：GetDiskFreeSpace
    返回以 1024 字节（KB）为单位的指定磁盘现行剩余空间。如果失败，返回-1。本命令为初级命令。
    参数<1>的名称为“磁盘驱动器字符”，类型为“文本型（text）”，可以被省略。类似“A”、“B”、“C”等，只取用给定文本的第一个字符。如果本参数被省略，默认使用当前驱动器。

*/
LIBAPI(int, krnln_GetDiskFreeSpace)
{
	char DirName [MAX_PATH];
	if(ArgInf.m_dtDataType == _SDT_NULL)
	{
		if(GetCurrentDirectory(MAX_PATH,DirName)==0)
			return -1;
		DirName[2]=0;

	}
	else
	{
		if(mystrlen(ArgInf.m_pText)==0)
			return -1;

		DirName[0]=*ArgInf.m_pText;
		DirName[1]=':';
		DirName[2]=0;

	}
	ULARGE_INTEGER FreeBytesAvailableToCaller, TotalNumberOfBytes, TotalNumberOfFreeBytes;

	if(GetDiskFreeSpaceEx(DirName,&FreeBytesAvailableToCaller,&TotalNumberOfBytes,&TotalNumberOfFreeBytes))
	{
		INT nRet = INT(FreeBytesAvailableToCaller.QuadPart/1024);
		return nRet;
	}
	return -1;
}
