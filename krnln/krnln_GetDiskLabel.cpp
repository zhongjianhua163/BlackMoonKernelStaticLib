#include "stdafx.h"
#include "Myfunctions.h"

//磁盘操作 - 取磁盘卷标
/*
    调用格式： 〈文本型〉 取磁盘卷标 （［文本型 磁盘驱动器字符］） - 系统核心支持库->磁盘操作
    英文名称：GetDiskLabel
    返回指定磁盘的卷标文本。本命令为初级命令。
    参数<1>的名称为“磁盘驱动器字符”，类型为“文本型（text）”，可以被省略。类似“A”、“B”、“C”等，只取用给定文本的第一个字符。如果本参数被省略，默认使用当前驱动器。

*/
LIBAPI(char*, krnln_GetDiskLabel)
{
	char DirName [MAX_PATH];
	if(ArgInf.m_dtDataType == _SDT_NULL)
	{
		if(GetCurrentDirectory(MAX_PATH,DirName)==0)
			return NULL;
		DirName[3]=0;

	}
	else
	{
		if(mystrlen(ArgInf.m_pText)==0)
			return NULL;

		DirName[0]=*ArgInf.m_pText;
		DirName[1]=':';
		DirName[2]='\\';
		DirName[3]=0;

	}

	char* pText = NULL;
	char strVolume [MAX_PATH];
	char FileSystemNameBuffer [64];
	DWORD VolumeSerialNumber;

	if(GetVolumeInformation(DirName,strVolume,MAX_PATH,
		&VolumeSerialNumber,
		NULL,
		NULL,
		FileSystemNameBuffer,
		64))
	{
		INT nLen = mystrlen(strVolume);
		pText = CloneTextData(strVolume,nLen);

	}
	return pText;
}
