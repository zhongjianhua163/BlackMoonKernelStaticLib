#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"
#include <vector>

using namespace std;
//文件读写 - 读入文本
/*
    调用格式： 〈文本型〉 读入文本 （整数型 欲读入文本数据的文件号，［整数型 欲读入文本数据的长度］） - 系统核心支持库->文件读写
    英文名称：ReadText
    本命令用作从文件中当前读写位置读取并返回一段文本数据，实际读入长度（即返回文本的尺寸）可能会小于欲读入长度。如果该数据中存在字节 0 或 26（文本结束标志），将仅返回该字节之前的数据。如果读入失败，将返回一个空文本并且自动将当前文件读写位置移到文件尾部。本命令为初级命令。
    参数<1>的名称为“欲读入文本数据的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“欲读入文本数据的长度”，类型为“整数型（int）”，可以被省略。如果本参数被省略，默认读入文件中的所有文本数据。
*/
LIBAPI(char*, krnln_ReadText)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return NULL;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return NULL;
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[1].m_dtDataType != _SDT_NULL && pArgInf[1].m_int <=0)
		return NULL;

	char* pszRet = NULL;

	if(pFile->nType ==1)//磁盘文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		INT orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
		if(orgLoc == HFILE_ERROR)
		{
			SetFilePointer(hFile,0,NULL,FILE_END);
			return NULL;
		}

		DWORD dwNumOfByteRead;
		INT nLen;
		if(pArgInf[1].m_dtDataType == _SDT_NULL)
			nLen = GetFileSize(hFile,NULL) - orgLoc;
		else
			nLen = pArgInf[1].m_int;
		//后改代码
		vector<MEMSP> vecMEMSP;
		INT nTLen = 0;
		for (INT i=0; i<nLen; i+=4096)
		{
			MEMSP tmpMEMSP;
			tmpMEMSP.pData = (char*)malloc(4096);
			INT nRet = ReadFile(hFile, tmpMEMSP.pData, min(nLen-i,4096), &dwNumOfByteRead, 0);
			if(nRet == FALSE)
			{
				SetFilePointer(hFile, 0, NULL, FILE_END);
				free(tmpMEMSP.pData);
				break;
			}
			BOOL bFind = FALSE;
			for (DWORD j=0; j < dwNumOfByteRead; j++)
			{
				if (tmpMEMSP.pData[j] == 0 || tmpMEMSP.pData[j] == 26)
				{
					dwNumOfByteRead = j;
					orgLoc++;// 跳过这个字节
					bFind = TRUE;
					break;
				}
			}
			tmpMEMSP.nLen = dwNumOfByteRead;
			nTLen += dwNumOfByteRead;
			vecMEMSP.push_back(tmpMEMSP);
			if (bFind || dwNumOfByteRead != 4096)
				break;
		}
		if (nTLen > 0)
		{
			pszRet = (LPSTR)E_MAlloc_Nzero(nTLen + 1);
			orgLoc += nTLen;
			SetFilePointer(hFile, orgLoc, NULL, FILE_BEGIN);
			
			LPSTR pszRetold = pszRet;
			vector<MEMSP>::iterator iterMEMSP;
			for (iterMEMSP = vecMEMSP.begin(); iterMEMSP != vecMEMSP.end(); iterMEMSP++)
			{
				memcpy(pszRetold, iterMEMSP->pData, iterMEMSP->nLen);
				pszRetold += iterMEMSP->nLen;
				free(iterMEMSP->pData);
			}
			pszRet[nTLen] = 0;
		}
		vecMEMSP.clear();
		return pszRet;
		// 大鸟原本的代码
// 		char* pData = new char[nLen];
// 		INT nRet = ReadFile(hFile, pData, nLen, &dwNumOfByteRead, 0);
// 		if(nRet == FALSE)
// 		{
// 			SetFilePointer(hFile,0,NULL,FILE_END);
// 			delete[] pData;
// 			return NULL;
// 		}
// 		nLen = 0;
// 		LPSTR pStr = pData;
// 		while(nLen < (INT)dwNumOfByteRead)
// 		{
// 			if(*pStr ==0 || *pStr ==26)
// 				break;
// 			nLen++;
// 			pStr++;
// 		}
// 		pszRet = (LPSTR)E_MAlloc_Nzero(nLen+1);
// 		orgLoc += nLen;
// 		SetFilePointer(hFile,orgLoc,NULL,FILE_BEGIN);
// 		strncpy(pszRet,pData,nLen);
// 		pszRet[nLen] = 0;
// 		
// 		delete[] pData;		

	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;

		INT orgLoc = pMemFile->GetPosition();

		DWORD dwNumOfByteRead;
		INT nLen;
		LPSTR pBufStart, pBufMax;
		if(pArgInf[1].m_dtDataType == _SDT_NULL)
			nLen = -1;
		else
			nLen = pArgInf[1].m_int;

		dwNumOfByteRead = pMemFile->GetBufferPtr (CMyMemFile::bufferRead,nLen,(void **)&pBufStart,(void **)&pBufMax);

		LPSTR pStr = pBufStart;
		nLen = 0;
		while(nLen < (INT)dwNumOfByteRead)
		{
			if(*pStr ==0 || *pStr ==26)
				break;
			nLen++;
			pStr++;
		}
		pszRet = (LPSTR)E_MAlloc_Nzero(nLen+1);
		orgLoc += nLen;
		pMemFile->Seek(orgLoc,CMyMemFile::begin);
		strncpy(pszRet,pBufStart,nLen);
		pszRet[nLen] = 0;
	}if(pFile->nType ==3)//加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		INT orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
		if(orgLoc == HFILE_ERROR)
		{
			SetFilePointer(hFile,0,NULL,FILE_END);
			return NULL;
		}
		
		DWORD dwNumOfByteRead;
		INT nLen;
		if(pArgInf[1].m_dtDataType == _SDT_NULL)
			nLen = GetFileSize(hFile,NULL) - orgLoc;
		else
			nLen = pArgInf[1].m_int;
		//后改代码
		vector<MEMSP> vecMEMSP;
		INT nTLen = 0;
		for (INT i=0; i<nLen; i+=4096)
		{
			MEMSP tmpMEMSP;
			tmpMEMSP.pData = (char*)malloc(4096);
			INT nPos = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
			INT nRet = ReadFile(hFile, tmpMEMSP.pData, min(nLen-i,4096), &dwNumOfByteRead, 0);
			if(nRet == FALSE)
			{
				SetFilePointer(hFile, 0, NULL, FILE_END);
				free(tmpMEMSP.pData);
				break;
			}
			BOOL bFind = FALSE;
			E_RC4_Calc(nPos, (unsigned char*)tmpMEMSP.pData, dwNumOfByteRead, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
			for (DWORD j=0; j < dwNumOfByteRead; j++)
			{
				if (tmpMEMSP.pData[j] == 0 || tmpMEMSP.pData[j] == 26)
				{
					dwNumOfByteRead = j;
					orgLoc++;// 跳过这个字节
					bFind = TRUE;
					break;
				}
			}
			tmpMEMSP.nLen = dwNumOfByteRead;
			nTLen += dwNumOfByteRead;
			vecMEMSP.push_back(tmpMEMSP);
			if (bFind || dwNumOfByteRead != 4096)
				break;
		}
		if (nTLen > 0)
		{
			pszRet = (LPSTR)E_MAlloc_Nzero(nTLen + 1);
			orgLoc += nTLen;
			SetFilePointer(hFile, orgLoc, NULL, FILE_BEGIN);
			
			LPSTR pszRetold = pszRet;
			vector<MEMSP>::iterator iterMEMSP;
			for (iterMEMSP = vecMEMSP.begin(); iterMEMSP != vecMEMSP.end(); iterMEMSP++)
			{
				memcpy(pszRetold, iterMEMSP->pData, iterMEMSP->nLen);
				pszRetold += iterMEMSP->nLen;
				free(iterMEMSP->pData);
			}
			pszRet[nTLen] = 0;
		}
		vecMEMSP.clear();
		return pszRet;	
	}
	return pszRet;
}
