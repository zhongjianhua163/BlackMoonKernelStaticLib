#include "stdafx.h"

//文件读写 - 锁住文件
/*
    调用格式： 〈逻辑型〉 锁住文件 （整数型 欲加锁或解锁的文件号，整数型 欲加锁或解锁的位置，整数型 欲加锁或解锁的长度，［整数型 加锁重试时间］） - 系统核心支持库->文件读写
    英文名称：lock
    在有若干个进程访问同一个文件的环境中，使用本命令拒绝其它用户对被打开文件中的某个区域进行读写访问。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“欲加锁或解锁的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“欲加锁或解锁的位置”，类型为“整数型（int）”。位置值从 0 开始。
    参数<3>的名称为“欲加锁或解锁的长度”，类型为“整数型（int）”。
    参数<4>的名称为“加锁重试时间”，类型为“整数型（int）”，可以被省略。本参数指定加锁失败后反复进行重试的毫秒数。如果被省略，默认为 0 ，即一旦失败立即返回。如果参数值提供为 -1 ，则反复进行重试，直到加锁成功为止。

*/
LIBAPI(BOOL, krnln_lock)
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
	OVERLAPPED Overlapped;
	memset(&Overlapped,0,sizeof(OVERLAPPED));
	Overlapped.Offset = pArgInf[1].m_int;
	DWORD dwFlags = LOCKFILE_FAIL_IMMEDIATELY;
	if(pArgInf[3].m_dtDataType != _SDT_NULL)
	{
		if(pArgInf[3].m_int== -1)
			dwFlags = 0;
		else if(pArgInf[3].m_int > 0)
		{	
			DWORD dwStart = ::GetTickCount();
			BOOL bRet;
			INT nVal;
			do
			{
				bRet = LockFileEx(hFile,LOCKFILE_FAIL_IMMEDIATELY,0,pArgInf[2].m_int,0,&Overlapped);
				nVal = GetTickCount() - dwStart;
			}while(bRet == FALSE && nVal <= pArgInf[3].m_int);

			return bRet;
		}

	}

	return LockFileEx(hFile,
		dwFlags,
		0,
		pArgInf[2].m_int,
		0,
		&Overlapped);

}
