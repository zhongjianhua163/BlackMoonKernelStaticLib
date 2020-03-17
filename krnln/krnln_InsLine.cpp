#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"

//文件读写 - 插入文本行
/*
    调用格式： 〈逻辑型〉 插入文本行 （整数型 欲写出文本的文件号，通用型 欲写出的文本，... ） - 系统核心支持库->文件读写
    英文名称：InsLine
    本命令用作插入一段或数段文本行到文件中当前读写位置处。该文件被打开时必须给予"#读写"或"#改读"权限。成功返回真，失败返回假。本命令为初级命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“欲写出文本的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“欲写出的文本”，类型为“通用型（all）”。参数值如果不为文本类型数据，将自动进行转换，如果无法转换（即数据类型为字节集、子程序指针、库或用户自定义数据类型），则不写出此数据。
*/
LIBAPI(BOOL, krnln_InsLine)
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
			LPSTR pData;
			BOOL bNeedFree = FALSE;
			if(pArgInf[i].m_dtDataType == SDT_TEXT)
				pData = pArgInf[i].m_pText;
			else
			{
				pData = SDataToStr(&pArgInf[i]);
				if(pData == NULL)
				{
					WriteFile(hFile,"\r\n",2,&dwNumOfByteRead,NULL);
//					FlushFileBuffers(hFile);
					continue;
				}
				bNeedFree = TRUE;
			}

			INT nLen = mystrlen(pData);
			if(nLen>0)
			{
				if(WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL))
				{
					WriteFile(hFile,"\r\n",2,&dwNumOfByteRead,NULL);
//					if(FlushFileBuffers(hFile)==FALSE)
//						bRet = FALSE;
				}
				else
					bRet = FALSE;
			}

			if(bNeedFree)
				free(pData);

			if(bRet == FALSE)
				break;

		}
		if(bRet && pBkData)//补上后段
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

		INT orgLoc = pMemFile->GetPosition();

		LPBYTE pBufStart, pBufMax;

		INT nBkLen = pMemFile->GetBufferPtr (CMyMemFile::bufferRead,-1,(void **)&pBufStart,(void **)&pBufMax);
		LPBYTE pBkData = NULL;
		if(nBkLen >0)
		{
			pBkData = new BYTE[nBkLen];
			memcpy(pBkData,pBufStart,nBkLen);
		}

		bRet = TRUE;
		for(INT i=1;i < nArgCount;i++)
		{
			LPSTR pData;
			BOOL bNeedFree = FALSE;
			if(pArgInf[i].m_dtDataType == SDT_TEXT)
				pData = pArgInf[i].m_pText;
			else
			{
				pData = SDataToStr(&pArgInf[i]);
				if(pData == NULL)
					continue;
				bNeedFree = TRUE;
			}

			INT nLen = mystrlen(pData);
			if(nLen>0)
				pMemFile->Write(pData,nLen);
			pMemFile->Write("\r\n",2);

			if(bNeedFree)
				free(pData);
		}
		if(pBkData)
		{
			orgLoc = pMemFile->GetPosition();
			pMemFile->Write(pBkData, nBkLen);
			delete[] pBkData;
			pMemFile->Seek (orgLoc,CMyMemFile::begin);
		}

	}else if(pFile->nType ==3)//加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		INT orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
		if(orgLoc == HFILE_ERROR)
			return FALSE;
		
		DWORD dwNumOfByteRead;
		INT nPos;
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

		unsigned char pszRN[2] = {0};
		bRet = TRUE;
		for(INT i=1;i < nArgCount;i++)
		{
			LPSTR pData;
			BOOL bNeedFree = FALSE;
			if(pArgInf[i].m_dtDataType == SDT_TEXT)
				pData = pArgInf[i].m_pText;
			else
			{
				pData = SDataToStr(&pArgInf[i]);
				if(pData == NULL)
				{
					nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
					pszRN[0] = '\r';
					pszRN[1] = '\n';
					E_RC4_Calc(nPos, pszRN, 2, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
					WriteFile(hFile, pszRN, 2, &dwNumOfByteRead,NULL);
					continue;
				}
				bNeedFree = TRUE;
			}
			
			INT nLen = mystrlen(pData);
			if(nLen>0)
			{
				if (!bNeedFree)
				{
					LPSTR pTMP = (LPSTR)malloc(nLen);
					memcpy(pTMP, pData, nLen);
					pData = pTMP;
					bNeedFree = TRUE;
				}
				nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
				E_RC4_Calc(nPos, (unsigned char*)pData, nLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
				if(WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL))
				{
					nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
					pszRN[0] = '\r';
					pszRN[1] = '\n';
					E_RC4_Calc(nPos, pszRN, 2, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
					WriteFile(hFile, pszRN, 2, &dwNumOfByteRead,NULL);
				}
				else
					bRet = FALSE;
			}
			
			if(bNeedFree)
				free(pData);
			
			if(bRet == FALSE)
				break;
		}

		if(bRet && pBkData)//补上后段
		{
			orgLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);//记下当前位置,以便恢复
			E_RC4_Calc(orgLoc, (unsigned char*)pBkData, nBkLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
			if(WriteFile(hFile,pBkData, nBkLen,&dwNumOfByteRead,NULL))
				SetFilePointer(hFile,orgLoc,NULL,FILE_BEGIN);//恢复原位置
			else
				bRet = FALSE;
		}
		if(pBkData)
			delete[] pBkData;
	}
	return bRet;
}
