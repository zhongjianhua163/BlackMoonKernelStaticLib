#include "stdafx.h"

//文件读写 - 解锁文件
/*
    调用格式： 〈逻辑型〉 解锁文件 （整数型 欲加锁或解锁的文件号，整数型 欲加锁或解锁的位置，整数型 欲加锁或解锁的长度） - 系统核心支持库->文件读写
    英文名称：Unlock
    解除由“锁住文件”命令对文件所进行的锁定。成功返回真，失败返回假。注意：本命令调用时所提供的参数值必须与调用“锁住文件”命令时所提供的参数值完全一致。本命令为初级命令。
    参数<1>的名称为“欲加锁或解锁的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“欲加锁或解锁的位置”，类型为“整数型（int）”。位置值从 0 开始。
    参数<3>的名称为“欲加锁或解锁的长度”，类型为“整数型（int）”。
*/
LIBAPI(BOOL, krnln_Unlock)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return FALSE;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return FALSE;
	if(pFile->nType !=1)//内存文件
		return TRUE;
	HANDLE hFile = (HANDLE)pFile->FileHandle;
	PMDATA_INF pArgInf = &ArgInf;

	return UnlockFile(hFile,
		pArgInf[1].m_int,
		0,
		pArgInf[2].m_int,
		0);
}
