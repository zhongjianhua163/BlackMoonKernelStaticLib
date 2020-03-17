#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"
//文件读写 - 删除数据
/*
    调用格式： 〈逻辑型〉 删除数据 （整数型 文件号，整数型 欲删除数据的字节数） - 系统核心支持库->文件读写
    英文名称：RemoveData
    本命令用作在文件中当前读写位置处删除一段字节数据，文件后面的数据顺序前移。该文件被打开时必须给予"#读写"或"#改读"权限。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“欲删除数据的字节数”，类型为“整数型（int）”。
*/
LIBAPI(BOOL, krnln_RemoveData)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return NULL;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return NULL;
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[1].m_int<=0)
		return FALSE;

	BOOL bRet = FALSE;

	if(pFile->nType ==1)//磁盘文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		INT orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
		if(orgLoc == HFILE_ERROR)
			return FALSE;


		bRet = TRUE;
		DWORD dwNumOfByteRead;
		INT nBkLen = GetFileSize(hFile,NULL) - orgLoc - pArgInf[1].m_int;
		LPBYTE pBkData = NULL;
		if(nBkLen >0)//有残余数据
		{
			pBkData = new BYTE[nBkLen];
			INT nLen = pArgInf[1].m_int;
			SetFilePointer(hFile,nLen,NULL,FILE_CURRENT);//后移到
			if( ReadFile(hFile, pBkData, nBkLen, &dwNumOfByteRead, 0)==FALSE)
			{
				delete[] pBkData;
				return FALSE;
			}
			SetFilePointer(hFile,orgLoc,NULL,FILE_BEGIN);//恢复原位置
			if(WriteFile(hFile,pBkData,nBkLen,&dwNumOfByteRead,NULL))
			{
//				if(FlushFileBuffers(hFile)==FALSE)
//					bRet = FALSE;
			}
			else
				bRet = FALSE;
			delete[] pBkData;
		}
		if(bRet)
			SetEndOfFile(hFile);

	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;

		INT orgLoc = pMemFile->GetPosition();

		INT nBkLen = pMemFile->GetFileSize() - orgLoc - pArgInf[1].m_int;
		LPBYTE pBkData = NULL;

		bRet = TRUE;
		if(nBkLen >0)//有残余数据
		{
			pMemFile->Seek(pArgInf[1].m_int,CMyMemFile::current);
			pBkData = new BYTE[nBkLen];
			pMemFile->Read(pBkData,nBkLen);
			pMemFile->Seek(orgLoc,CMyMemFile::begin);//恢复
			pMemFile->Write(pBkData, nBkLen);
			orgLoc = pMemFile->GetPosition();
			delete[] pBkData;
		}
		pMemFile->SetLength(orgLoc);
	}else if(pFile->nType ==3)//加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		INT orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
		if(orgLoc == HFILE_ERROR)
			return FALSE;
		
		bRet = TRUE;
		DWORD dwNumOfByteRead;
		INT nBkLen = GetFileSize(hFile,NULL) - orgLoc - pArgInf[1].m_int;
		INT nPos;
		LPBYTE pBkData = NULL;
		if(nBkLen >0)//有残余数据
		{
			pBkData = new BYTE[nBkLen];
			INT nLen = pArgInf[1].m_int;
			SetFilePointer(hFile,nLen,NULL,FILE_CURRENT);//后移到
			nPos = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
			if( ReadFile(hFile, pBkData, nBkLen, &dwNumOfByteRead, 0)==FALSE)
			{
				delete[] pBkData;
				return FALSE;
			}
			nBkLen = dwNumOfByteRead;
			E_RC4_Calc(nPos, (unsigned char*)pBkData, nBkLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);

			SetFilePointer(hFile,orgLoc,NULL,FILE_BEGIN);//恢复原位置
			nPos = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
			E_RC4_Calc(nPos, (unsigned char*)pBkData, nBkLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
			if(!WriteFile(hFile,pBkData,nBkLen,&dwNumOfByteRead,NULL))
				bRet = FALSE;

			delete[] pBkData;
		}
		if(bRet)
			SetEndOfFile(hFile);
	}
	return bRet;
}
