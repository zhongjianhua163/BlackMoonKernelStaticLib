#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"
//文件读写 - 写出字节集
/*
    调用格式： 〈逻辑型〉 写出字节集 （整数型 欲写出数据的文件号，字节集 欲写出的字节集数据，... ） - 系统核心支持库->文件读写
    英文名称：WriteBin
    本命令用作写出一段或数段字节集数据到文件中当前读写位置处。成功返回真，失败返回假。本命令为初级命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“欲写出数据的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“欲写出的字节集数据”，类型为“字节集（bin）”。
*/
LIBAPI(BOOL, krnln_WriteBin)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return NULL;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return NULL;
	PMDATA_INF pArgInf = &ArgInf;

	BOOL bRet = FALSE;

	if(pFile->nType ==1)//磁盘文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
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
		

	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;
		bRet = TRUE;
		for(INT i=1;i < nArgCount;i++)
		{
			LPBYTE pData = pArgInf[i].m_pBin + 2*sizeof(INT);
			INT nLen = pArgInf[i].m_pInt[1];
			pMemFile->Write(pData,nLen);
		}

	}else if (pFile->nType == 3) //加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		DWORD dwNumOfByteRead;
		LPBYTE pData;
		INT nMaxLen = 0;
		INT nLen, i, nPos;
		bRet = TRUE;
		for(i=1;i < nArgCount;i++)
		{
			nLen = pArgInf[i].m_pInt[1];
			if (nLen > 0)
				nMaxLen = max(nMaxLen, nLen);
		}
		if (nMaxLen > 0)
			pData = new unsigned char[nMaxLen];
		for(i=1;i < nArgCount;i++)
		{
			nLen = pArgInf[i].m_pInt[1];
			if (nLen > 0)
			{
				memcpy(pData, pArgInf[i].m_pBin + 2*sizeof(INT), nLen);

				nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
				E_RC4_Calc(nPos, pData, nLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
				if(WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL)==FALSE)
				{
					delete []pData;
					bRet = FALSE;
					break;
				}
			}
		}
		delete []pData;
	}
	return bRet;
}
