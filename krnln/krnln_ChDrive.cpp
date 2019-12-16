#include "stdafx.h"

//磁盘操作 - 改变驱动器
/*
    调用格式： 〈逻辑型〉 改变驱动器 （文本型 欲改变到的驱动器） - 系统核心支持库->磁盘操作
    英文名称：ChDrive
    改变当前的缺省驱动器。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“欲改变到的驱动器”，类型为“文本型（text）”。参数值指明一个存在的驱动器。类似“A”、“B”、“C”等，只取用给定文本的第一个字符。如果使用零长度的文本，则当前的驱动器不会改变。
*/
LIBAPI(BOOL, krnln_ChDrive)
{
	char DirName [MAX_PATH];

	if(!*(ArgInf.m_pText))
		return FALSE;

	DirName[0]=*ArgInf.m_pText;
	DirName[1]=':';
	DirName[2]='\\';
	DirName[3]=0;

	return SetCurrentDirectory(DirName);
}
