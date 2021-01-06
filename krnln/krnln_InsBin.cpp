#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"
//文件读写 - 插入字节集
/*
    调用格式： 〈逻辑型〉 插入字节集 （整数型 欲写出数据的文件号，字节集 欲写出的字节集数据，... ） - 系统核心支持库->文件读写
    英文名称：InsBin
    本命令用作插入一段或数段字节集数据到文件中当前读写位置处。该文件被打开时必须给予"#读写"或"#改读"权限。成功返回真，失败返回假。本命令为初级命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“欲写出数据的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“欲写出的字节集数据”，类型为“字节集（bin）”。
*/
LIBAPI(BOOL, krnln_InsBin)
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
		INT orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
		if(orgLoc == HFILE_ERROR)
			return FALSE;

		DWORD dwNumOfByteRead;
		INT nBkLen = GetFileSize(hFile,NULL) - orgLoc;
		LPBYTE pBkData = NULL;
		if(nBkLen >0)
		{
			pBkData = new BYTE[nBkLen];
			if(!ReadFile(hFile, pBkData, nBkLen, &dwNumOfByteRead, 0))
			{
				delete[] pBkData;
				return FALSE;
			}
			SetFilePointer(hFile,orgLoc,NULL,FILE_BEGIN);//恢复原位置
		}

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
		if(bRet && pBkData)
		{
			orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);//记下当前位置,以便恢复
			if(WriteFile(hFile,pBkData, nBkLen,&dwNumOfByteRead,NULL))
			{
				SetFilePointer(hFile,orgLoc,NULL,FILE_BEGIN);//恢复原位置
//				if(FlushFileBuffers(hFile)==FALSE)
//					bRet = FALSE;
			}
			else
				bRet = FALSE;
		}
		if(pBkData)
			delete[] pBkData;

	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;
		LPBYTE pBufStart, pBufMax;

		INT orgLoc = pMemFile->GetPosition();

		INT nBkLen = pMemFile->GetBufferPtr (CMyMemFile::bufferRead,-1,(void **)&pBufStart,(void **)&pBufMax);
		LPBYTE pBkData = NULL;
		if(nBkLen >0)
		{
			pBkData = new BYTE[nBkLen];
			memcpy(pBkData,pBufStart,nBkLen);
		}

		pMemFile->Seek (orgLoc,CMyMemFile::begin);

		bRet = TRUE;
		for(INT i=1;i < nArgCount;i++)
		{
			LPBYTE pData = pArgInf[i].m_pBin + 2*sizeof(INT);
			INT nLen = pArgInf[i].m_pInt[1];
			pMemFile->Write(pData,nLen);
		}
		if(pBkData)
		{
			orgLoc = pMemFile->GetPosition();
			pMemFile->Write(pBkData, nBkLen);
			delete[] pBkData;
			pMemFile->Seek (orgLoc,CMyMemFile::begin);
		}

	}else if(pFile->nType == 3)//加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		INT orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
		if(orgLoc == HFILE_ERROR)
			return FALSE;

		DWORD dwNumOfByteRead;
		INT nBkLen = GetFileSize(hFile,NULL) - orgLoc;
		LPBYTE pBkData = NULL;
		if(nBkLen >0)
		{
			pBkData = new BYTE[nBkLen];
			if(!ReadFile(hFile, pBkData, nBkLen, &dwNumOfByteRead, 0))
			{
				delete[] pBkData;
				return FALSE;
			}
			nBkLen = dwNumOfByteRead;
			E_RC4_Calc(orgLoc, (unsigned char*)pBkData, nBkLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
			SetFilePointer(hFile,orgLoc,NULL,FILE_BEGIN);//恢复原位置
		}

		bRet = TRUE;
		for(INT i=1;i < nArgCount;i++)
		{
			LPBYTE pData = pArgInf[i].m_pBin + 2*sizeof(INT);
			INT nLen = pArgInf[i].m_pInt[1];
			INT nPos = SetFilePointer(hFile,0,NULL,FILE_CURRENT);

			LPBYTE pTMP = (LPBYTE)malloc(nLen);
			memcpy(pTMP, pData, nLen);
			pData = pTMP;

			E_RC4_Calc(orgLoc, (unsigned char*)pData, nLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
			if(WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL)==FALSE)
			{
				free(pData);
				bRet = FALSE;
				break;
			}
			free(pData);
		}
		if(bRet && pBkData)
		{
			orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);//记下当前位置,以便恢复
			E_RC4_Calc(orgLoc, (unsigned char*)pBkData, nBkLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
			if(WriteFile(hFile,pBkData, nBkLen,&dwNumOfByteRead,NULL))
			{
				SetFilePointer(hFile,orgLoc,NULL,FILE_BEGIN);//恢复原位置
			}
			else
				bRet = FALSE;
		}
		if(pBkData)
			delete[] pBkData;
	}
	return bRet;
}
