#include "stdafx.h"
#include "Myfunctions.h"

//磁盘操作 - 置磁盘卷标
/*
    调用格式： 〈逻辑型〉 置磁盘卷标 （［文本型 磁盘驱动器字符］，文本型 欲置入的卷标文本） - 系统核心支持库->磁盘操作
    英文名称：SetDiskLabel
    设置指定磁盘的卷标文本。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“磁盘驱动器字符”，类型为“文本型（text）”，可以被省略。类似“A”、“B”、“C”等，只取用给定文本的第一个字符。如果本参数被省略，默认使用当前驱动器。
    参数<2>的名称为“欲置入的卷标文本”，类型为“文本型（text）”。
*/
LIBAPI(BOOL, krnln_SetDiskLabel)
{
	char DirName [MAX_PATH];
	if(ArgInf.m_dtDataType == _SDT_NULL)
	{
		if(GetCurrentDirectory(MAX_PATH,DirName)==0)
			return FALSE;
		DirName[3]=0;

	}
	else
	{
		if(mystrlen(ArgInf.m_pText)==0)
			return FALSE;

		DirName[0]=*ArgInf.m_pText;
		DirName[1]=':';
		DirName[2]='\\';
		DirName[3]=0;

	}

	PMDATA_INF pArgInf = &ArgInf;

	return SetVolumeLabel (DirName,pArgInf[1].m_pText);
}
