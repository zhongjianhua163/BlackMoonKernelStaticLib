#include "stdafx.h"
#include "MyMemFile.h"
//文件读写 - 移动读写位置
/*
    调用格式： 〈逻辑型〉 移动读写位置 （整数型 欲进行操作的文件号，［整数型 起始移动位置］，整数型 移动距离） - 系统核心支持库->文件读写
    英文名称：FSeek
    在被打开的文件中，设置下一个读或写操作的位置。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“欲进行操作的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“起始移动位置”，类型为“整数型（int）”，可以被省略。参数值指定从文件中开始移动的位置。可以为以下常量之一：
	1、#文件首； 2、#文件尾； 3、#现行位置。如果本参数被省略，默认值为“#文件首”。
    参数<3>的名称为“移动距离”，类型为“整数型（int）”。参数值指定相对于起始移动位置的移动长度。
*/
LIBAPI(BOOL, krnln_FSeek)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return FALSE;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return FALSE;
	PMDATA_INF pArgInf = &ArgInf;
	BOOL bRet = FALSE;

	if(pFile->nType == 1 || pFile->nType == 3)//磁盘文件 加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		DWORD dwMoveMethod;
		switch(pArgInf[1].m_int)
		{
		case 2://#文件尾
			dwMoveMethod = FILE_END;
			break;
		case 3://#现行位置
			dwMoveMethod = FILE_CURRENT;
			break;
		default://#文件首
			dwMoveMethod = FILE_BEGIN;
		}
		bRet = SetFilePointer(hFile,pArgInf[2].m_int,NULL,dwMoveMethod);

	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;
		DWORD dwMoveMethod;
		switch(pArgInf[1].m_int)
		{
		case 2://#文件尾
			dwMoveMethod = CMyMemFile::end;
			break;
		case 3://#现行位置
			dwMoveMethod = CMyMemFile::current;
			break;
		default://#文件首
			dwMoveMethod = CMyMemFile::begin;
		}
		
		bRet = (pMemFile->Seek(pArgInf[2].m_int,dwMoveMethod) != -1);

	}
	return bRet;

}
