#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"
#include <vector>

using namespace std;

//文件读写 - 读入一行
/*
    调用格式： 〈文本型〉 读入一行 （整数型 欲读入文本数据的文件号） - 系统核心支持库->文件读写
    英文名称：ReadLine
    本命令用作从文件中当前读写位置读取并返回一行文本数据，行末的回车及换行符将被抛弃。如果读入失败，将返回一个空文本并且自动将当前文件读写位置移到文件尾部。本命令为初级命令。
    参数<1>的名称为“欲读入文本数据的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
*/
LIBAPI(char*, krnln_ReadLine)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return NULL;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
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
		INT nLen = GetFileSize(hFile,NULL) - orgLoc;

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
			for (INT j=0; j < dwNumOfByteRead; j++)
			{
				if (tmpMEMSP.pData[j] == 0 || tmpMEMSP.pData[j] == '\r' || tmpMEMSP.pData[j] == '\n')
				{
					dwNumOfByteRead = j;

					if (j <= dwNumOfByteRead && tmpMEMSP.pData[j] == '\r' && tmpMEMSP.pData[j+1] =='\n')
						orgLoc+=2;// 跳过这两个字节
					else
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
// 		HANDLE hFile = (HANDLE)pFile->FileHandle;
// 		INT orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
// 		if(orgLoc == HFILE_ERROR)
// 		{
// 			SetFilePointer(hFile,0,NULL,FILE_END);
// 			return NULL;
// 		}
// 
// 		DWORD dwNumOfByteRead=0;
// 		INT nPost = 0;
// 		INT nLen = 4096;
// 		DWORD dwByteTop;
// 		LPSTR pStr;
// 
// 		char* pData = (char*)malloc(nLen);
// 		do
// 		{
// 			pStr = pData + nPost;
// 			INT nRet = ReadFile(hFile, pStr, nLen, &dwByteTop, 0);
// 			if(nRet == FALSE)
// 			{
// 				SetFilePointer(hFile,0,NULL,FILE_END);
// 				free(pData);
// 				return NULL;
// 			}
// 			INT nPtr = 0;
// 			BOOL bFind = FALSE;
// 			while(nPtr < (INT)dwByteTop)
// 			{
// 				if(*pStr =='\r' || *pStr =='\n')
// 				{
// 					dwNumOfByteRead +=nPtr;
// 					bFind = TRUE;
// 					break;
// 				}
// 				nPtr++;
// 				pStr++;
// 			}
// 			if(bFind)
// 				break;
// 			dwNumOfByteRead +=dwByteTop;
// 			if((INT)dwByteTop < nLen)
// 				break;
// 			nPost = dwNumOfByteRead;
// 			pData = (char*)realloc(pData,nLen);
// 
// 		}while((INT)dwByteTop==nLen);
// 
// 		nLen = dwNumOfByteRead;
// 		pszRet = (LPSTR)E_MAlloc_Nzero(nLen+1);
// 		orgLoc += nLen;
// 		if(*pStr =='\r' || *pStr =='\n')
// 		{
// 			orgLoc++;
// 			pStr++;
// 			if(*pStr =='\n')
// 				orgLoc++;
// 		}
// 		SetFilePointer(hFile,orgLoc,NULL,FILE_BEGIN);
// 		strncpy(pszRet,pData,nLen);
// 		pszRet[nLen] = 0;
// 		
// 		free(pData);	
	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;

		INT orgLoc = pMemFile->GetPosition();

		DWORD dwNumOfByteRead;
		INT nLen = -1;
		LPSTR pBufStart, pBufMax;

		dwNumOfByteRead = pMemFile->GetBufferPtr (CMyMemFile::BufferCommand::bufferRead,nLen,(void **)&pBufStart,(void **)&pBufMax);

		LPSTR pStr = pBufStart;
		nLen = 0;
		while(nLen < (INT)dwNumOfByteRead)
		{
			if(*pStr =='\r' || *pStr =='\n')
				break;
			nLen++;
			pStr++;
		}
		pszRet = (LPSTR)E_MAlloc_Nzero(nLen+1);
		orgLoc += nLen;
		if(*pStr =='\r' || *pStr =='\n')
		{
			orgLoc++;
			pStr++;
			if(*pStr =='\n')
				orgLoc++;
		}
		pMemFile->Seek(orgLoc,CMyMemFile::SeekPosition::begin);
		strncpy(pszRet,pBufStart,nLen);
		pszRet[nLen] = 0;
	}else if(pFile->nType ==3)//加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		INT orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
		if(orgLoc == HFILE_ERROR)
		{
			SetFilePointer(hFile,0,NULL,FILE_END);
			return NULL;
		}
		
		DWORD dwNumOfByteRead;
		INT nLen = GetFileSize(hFile,NULL) - orgLoc;
		
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
			for (INT j=0; j < dwNumOfByteRead; j++)
			{
				if (tmpMEMSP.pData[j] == 0 || tmpMEMSP.pData[j] == '\r' || tmpMEMSP.pData[j] == '\n')
				{
					dwNumOfByteRead = j;

					if (j <= dwNumOfByteRead && tmpMEMSP.pData[j] == '\r' && tmpMEMSP.pData[j+1] =='\n')
						orgLoc+=2;// 跳过这两个字节
					else
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
