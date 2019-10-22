#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"
//文件读写 - 读入字节集
/*
    调用格式： 〈字节集〉 读入字节集 （整数型 欲读入数据的文件号，整数型 欲读入数据的长度） - 系统核心支持库->文件读写
    英文名称：ReadBin
    本命令用作从文件中当前读写位置读取并返回一段字节集数据，实际读入长度（即返回的字节集的尺寸）可能会小于欲读入长度。如果读入失败，将返回一个空字节集并且自动将当前文件读写位置移到文件尾部。本命令为初级命令。
    参数<1>的名称为“欲读入数据的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“欲读入数据的长度”，类型为“整数型（int）”。
*/
LIBAPI(void*, krnln_ReadBin)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return NULL;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return NULL;
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[1].m_int <=0)
		return NULL;

	LPBYTE pbRet = NULL;

	if(pFile->nType == 1)//磁盘文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		DWORD dwNumOfByteRead;
		INT nLen = pArgInf[1].m_int;
		LPBYTE pData = new BYTE[nLen];
		INT nRet = ReadFile(hFile, pData, nLen, &dwNumOfByteRead, 0);
		if(nRet == FALSE)
		{
			delete[] pData;
			return NULL;
		}
		nLen = dwNumOfByteRead;
		pbRet = CloneBinData(pData,nLen);
		delete[] pData;
		

	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;
		INT nLen = pArgInf[1].m_int;
		LPBYTE pData =  (LPBYTE)E_MAlloc_Nzero(nLen+2*sizeof(INT));
		*(LPINT)pData = 1;
		*(LPINT)(pData + sizeof(INT)) = nLen;
		DWORD dwNumOfByteRead = pMemFile->Read (pData + 2*sizeof(INT),nLen);
		if(dwNumOfByteRead == 0)
		{
			E_MFree(pData);
			return NULL;
		}
		*(LPINT)(pData + sizeof(INT)) = dwNumOfByteRead;
		pbRet = pData;

	}else if (pFile->nType == 3) //加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		DWORD dwNumOfByteRead;
		INT nLen = pArgInf[1].m_int;
		LPBYTE pData = new BYTE[nLen];
		INT nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
		INT nRet = ReadFile(hFile, pData, nLen, &dwNumOfByteRead, 0);
		if(nRet == FALSE)
		{
			delete[] pData;
			return NULL;
		}
		nLen = dwNumOfByteRead;
		E_RC4_Calc(nPos, pData, nLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
		pbRet = CloneBinData(pData,nLen);
		delete[] pData;
	}
	return pbRet;
}
