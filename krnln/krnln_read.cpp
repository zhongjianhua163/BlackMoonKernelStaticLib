#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"
#include <vector>

using namespace std;

//文件读写 - 读入数据
/*
	调用格式： 〈逻辑型〉 读入数据 （整数型 欲读入数据的文件号，通用型变量/变量数组 存放所读入数据的变量，... ） - 系统核心支持库->文件读写
	英文名称：read
	本命令应该与“写出”命令配合使用，用作从文件中当前读写位置读取格式数据到指定的一系列变量或数组变量中。成功返回真，失败返回假。本命令为中级命令。命令参数表中最后一个参数可以被重复添加。
	参数<1>的名称为“欲读入数据的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
	参数<2>的名称为“存放所读入数据的变量”，类型为“通用型（all）”，提供参数数据时只能提供变量及变量数组。如果变量的数据类型为用户自定义或库定义数据类型，命令将会失败。
*/
BOOL ReadFileTextData(HANDLE hFile, LPSTR& pStr, BOOL& bRet)
{
	char szBuff[4096];
	DWORD dwNumTop = 0;
	pStr = NULL;

	do
	{
		INT orgLoc = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
		if (orgLoc == HFILE_ERROR)
		{
			bRet = FALSE;
			return TRUE;
		}
		DWORD dwNumOfByteRead;
		if (ReadFile(hFile, szBuff, 4096, &dwNumOfByteRead, NULL) == FALSE)
		{
			bRet = FALSE;
			return TRUE;
		}
		INT nPos = 0;
		LPSTR pTemp = szBuff;
		BOOL bFind = FALSE;
		while (nPos < (INT)dwNumOfByteRead)
		{
			if (*pTemp == 0)
			{
				nPos++;
				bFind = TRUE;
				break;
			}
			pTemp++;
			nPos++;
		}
		INT nLoc = dwNumTop;
		dwNumTop += nPos;
		if (pStr)
			pStr = (LPSTR)E_MRealloc(pStr, dwNumTop + 1);
		else
			pStr = (LPSTR)E_MAlloc(dwNumTop + 1);
		pTemp = pStr + nLoc;
		strncpy(pTemp, szBuff, nPos);
		pTemp[nPos] = 0;

		if (bFind)//到尾
		{
			orgLoc += nPos;
			SetFilePointer(hFile, orgLoc, NULL, FILE_BEGIN);
			bRet = TRUE;
			return FALSE;
		}

		if (dwNumOfByteRead < 4096)
		{
			bRet = TRUE;
			break;
		}

	} while (1);

	return TRUE;

}

BOOL ReadFileBinData(HANDLE hFile, LPBYTE& pByte, BOOL& bRet)
{
	pByte = NULL;
	DWORD dwSize;
	DWORD dwNumOfByteRead;
	if (ReadFile(hFile, &dwSize, sizeof(INT), &dwNumOfByteRead, NULL))
	{
		if (dwNumOfByteRead < sizeof(INT))return TRUE;
		pByte = (LPBYTE)E_MAlloc(dwSize + 2 * sizeof(INT));

		if (ReadFile(hFile, pByte + 2 * sizeof(INT), dwSize, &dwNumOfByteRead, NULL))
		{
			LPINT p = (LPINT)pByte;
			p[0] = 1;
			p[1] = dwNumOfByteRead;
			if (dwNumOfByteRead == dwSize)
				return FALSE;
		}
		else
		{
			E_MFree(pByte);
			pByte = NULL;
		}
	}
	return TRUE;
}

BOOL ReadMemFileTextData(CMyMemFile* pMemFile, LPSTR& pStr)
{
	INT orgLoc = pMemFile->GetPosition();

	DWORD dwNumOfByteRead;
	INT nLen = -1;
	LPSTR pBufStart, pBufMax;

	dwNumOfByteRead = pMemFile->GetBufferPtr(CMyMemFile::bufferRead, nLen, (void**)&pBufStart, (void**)&pBufMax);

	pStr = pBufStart;
	nLen = 0;
	while (nLen < (INT)dwNumOfByteRead)
	{
		if (*pStr == 0)
		{
			orgLoc++;
			break;
		}
		nLen++;
		pStr++;
	}
	pStr = (LPSTR)E_MAlloc(nLen + 1);
	orgLoc += nLen;
	pMemFile->Seek(orgLoc, CMyMemFile::begin);
	strncpy(pStr, pBufStart, nLen);
	pStr[nLen] = 0;
	if (nLen == (INT)dwNumOfByteRead)
		return TRUE;
	return FALSE;
}

BOOL ReadMemFileBinData(CMyMemFile* pMemFile, LPBYTE& pByte)
{

	pByte = NULL;
	DWORD dwSize;
	DWORD dwNumOfByteRead = pMemFile->Read(&dwSize, sizeof(INT));
	if (dwNumOfByteRead < sizeof(INT))
		return TRUE;
	pByte = (LPBYTE)E_MAlloc(dwSize + 2 * sizeof(INT));
	dwNumOfByteRead = pMemFile->Read(pByte + 2 * sizeof(INT), dwSize);
	if (dwNumOfByteRead == 0)
	{
		E_MFree(pByte);
		pByte = NULL;
	}
	else
	{
		LPINT p = (LPINT)pByte;
		p[0] = 1;
		p[1] = dwNumOfByteRead;
		if (dwNumOfByteRead == dwSize)
			return FALSE;
	}

	return TRUE;

}
BOOL ReadFileTextData_Crypt(PFILEELEMENT pFile, LPSTR& pStr, BOOL& bRet)
{
	pStr = NULL;
	void* hFile = pFile->FileHandle;
	INT orgLoc = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
	if (orgLoc == HFILE_ERROR)
	{
		bRet = FALSE;
		return TRUE;
	}
	DWORD dwNumOfByteRead;
	INT nLen = GetFileSize(hFile, NULL) - orgLoc;
	vector<MEMSP> vecMEMSP;
	INT nTLen = 0;
	for (INT i = 0; i < nLen; i += 4096)
	{
		MEMSP tmpMEMSP;
		tmpMEMSP.pData = (char*)malloc(4096);
		INT nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
		INT nRet = ReadFile(hFile, tmpMEMSP.pData, min(nLen - i, 4096), &dwNumOfByteRead, 0);
		if (nRet == FALSE)
		{
			SetFilePointer(hFile, 0, NULL, FILE_END);
			free(tmpMEMSP.pData);
			bRet = FALSE;
			break;
		}
		BOOL bFind = FALSE;
		E_RC4_Calc(nPos, (unsigned char*)tmpMEMSP.pData, dwNumOfByteRead, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
		for (DWORD j = 0; j < dwNumOfByteRead; j++)
		{
			if (tmpMEMSP.pData[j] == 0)
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
		bRet = TRUE;
		pStr = (LPSTR)E_MAlloc_Nzero(nTLen + 1);
		orgLoc += nTLen;
		SetFilePointer(hFile, orgLoc, NULL, FILE_BEGIN);

		LPSTR pszRetold = pStr;
		vector<MEMSP>::iterator iterMEMSP;
		for (iterMEMSP = vecMEMSP.begin(); iterMEMSP != vecMEMSP.end(); iterMEMSP++)
		{
			memcpy(pszRetold, iterMEMSP->pData, iterMEMSP->nLen);
			pszRetold += iterMEMSP->nLen;
			free(iterMEMSP->pData);
		}
		pStr[nTLen] = 0;
	}
	else
		bRet = FALSE;

	vecMEMSP.clear();
	return !bRet;
}

BOOL ReadFileBinData_Crypt(PFILEELEMENT pFile, LPBYTE& pByte, BOOL& bRet)
{
	pByte = NULL;
	DWORD dwSize;
	DWORD dwNumOfByteRead;
	void* hFile = pFile->FileHandle;
	INT nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
	if (ReadFile(hFile, &dwSize, sizeof(INT), &dwNumOfByteRead, NULL))
	{
		E_RC4_Calc(nPos, (unsigned char*)&dwSize, sizeof(INT), pFile->strTable, pFile->nCryptStart, pFile->strMD5);
		if (dwNumOfByteRead < sizeof(INT))
			return TRUE;

		pByte = (LPBYTE)E_MAlloc(dwSize + 2 * sizeof(INT));
		nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);

		if (ReadFile(hFile, pByte + 2 * sizeof(INT), dwSize, &dwNumOfByteRead, NULL))
		{
			LPINT p = (LPINT)pByte;
			p[0] = 1;
			p[1] = dwNumOfByteRead;
			E_RC4_Calc(nPos, (unsigned char*)(pByte + 2 * sizeof(INT)), dwNumOfByteRead, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
			if (dwNumOfByteRead == dwSize)
				return FALSE;
		}
		else
		{
			E_MFree(pByte);
			pByte = NULL;
		}
	}
	return TRUE;
}

LIBAPI(BOOL, krnln_read)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if (pFile == NULL)
		return NULL;
	if (IsInFileMangerList(pFile) == FALSE)//检测句柄合法性
		return NULL;
	PMDATA_INF pArgInf = &ArgInf;

	BOOL bRet = FALSE;
	BOOL bEof = FALSE;

	if (pFile->nType == 1 || pFile->nType == 3)//磁盘文件 加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		DWORD dwNumOfByteRead;
		bRet = TRUE;
		INT nPos;
		for (INT i = 1; i < nArgCount; i++)
		{
			if (bRet == FALSE)
				break;
			if ((pArgInf[i].m_dtDataType & DT_IS_ARY) == DT_IS_ARY)//是数组
			{
				pArgInf[i].m_dtDataType &= ~DT_IS_ARY; //去除数组标志

				if (pArgInf[i].m_ppAryData == NULL)//空数组
					continue;

				if (pArgInf[i].m_dtDataType == SDT_TEXT)
				{
					DWORD dwSize;
					LPSTR* pAryData = (LPSTR*)GetAryElementInf(*pArgInf[i].m_ppAryData, dwSize);

					for (UINT n = 0; n < dwSize; n++)
					{
						if (pAryData[n])
							E_MFree(pAryData[n]);

						LPSTR pStr = NULL;
						if (bEof == FALSE)
						{
							if (pFile->nType == 3) //加密文件
								bEof = ReadFileTextData_Crypt(pFile, pStr, bRet);
							else
								bEof = ReadFileTextData(hFile, pStr, bRet);
						}
						pAryData[n] = pStr;
						if (bRet == FALSE)
							break;
					}
				}
				else if (pArgInf[i].m_dtDataType == SDT_BIN)
				{
					DWORD dwSize;
					LPBYTE* pAryData = (LPBYTE*)GetAryElementInf(*pArgInf[i].m_ppAryData, dwSize);
					INT nData = 0;
					for (UINT n = 0; n < dwSize; n++)
					{
						if (pAryData[n])
							E_MFree(pAryData[n]);
						LPBYTE pByte = NULL;
						if (bEof == FALSE)
						{
							if (pFile->nType == 3) //加密文件
								bEof = ReadFileBinData_Crypt(pFile, pByte, bRet);
							else
								bEof = ReadFileBinData(hFile, pByte, bRet);
						}
						pAryData[n] = pByte;

						if (bRet == FALSE)
							break;
					}
				}
				else {
					INT nLen = GetSysDataTypeDataSize(pArgInf[i].m_dtDataType);
					if (nLen == 0)//不支持的数据类型
						continue;
					DWORD dwSize;
					void* pData = GetAryElementInf(*pArgInf[i].m_ppAryData, dwSize);
					nLen *= dwSize;
					memset(pData, 0, nLen);

					if (bEof == FALSE)
					{
						nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
						if (ReadFile(hFile, pData, nLen, &dwNumOfByteRead, NULL))
						{
							if (pFile->nType == 3) //加密文件
								E_RC4_Calc(nPos, (unsigned char*)pData, dwNumOfByteRead, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
							if ((INT)dwNumOfByteRead < nLen)//到尾
								bEof = TRUE;
						}
						else
						{
							bRet = FALSE;
							break;
						}
					}
				}
			}
			else
			{//非数组
				INT nLen;
				void* pData;
				INT nData = 0;
				if (pArgInf[i].m_dtDataType == SDT_TEXT)
				{
					if (pArgInf[i].m_ppText)
						E_MFree(*pArgInf[i].m_ppText);
					LPSTR pStr = NULL;
					if (bEof == FALSE)
					{
						if (pFile->nType == 3) // 加密文件
							bEof = ReadFileTextData_Crypt(pFile, pStr, bRet);
						else
							bEof = ReadFileTextData(hFile, pStr, bRet);
					}
					*pArgInf[i].m_ppText = pStr;

				}
				else if (pArgInf[i].m_dtDataType == SDT_BIN)
				{
					if (pArgInf[i].m_ppBin)
						E_MFree(*pArgInf[i].m_ppBin);
					LPBYTE pByte = NULL;
					if (bEof == FALSE)
					{
						if (pFile->nType == 3) // 加密文件
							bEof = ReadFileBinData_Crypt(pFile, pByte, bRet);
						else
							bEof = ReadFileBinData(hFile, pByte, bRet);
					}
					*pArgInf[i].m_ppBin = pByte;

				}
				else {
					nLen = GetSysDataTypeDataSize(pArgInf[i].m_dtDataType);
					if (nLen == 0)//不支持的数据类型
						continue;
					pData = pArgInf[i].m_pCompoundData;
					memset(pData, 0, nLen);
					if (bEof == FALSE)
					{
						DWORD dwByteTop;
						nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
						if (ReadFile(hFile, pData, nLen, &dwByteTop, NULL))
						{
							if (pFile->nType == 3) //加密文件
								E_RC4_Calc(nPos, (unsigned char*)pData, dwByteTop, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
							if (nLen > (INT)dwByteTop)//已经到尾了
								bEof = TRUE;
						}
						else
						{
							bRet = FALSE;
							break;
						}
					}
				}
			}
		}
	}
	else if (pFile->nType == 2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*)pFile->FileHandle;
		bRet = TRUE;
		for (INT i = 1; i < nArgCount; i++)
		{

			if ((pArgInf[i].m_dtDataType & DT_IS_ARY) == DT_IS_ARY)//是数组
			{
				pArgInf[i].m_dtDataType &= ~DT_IS_ARY; //去除数组标志

				if (pArgInf[i].m_ppAryData == NULL)//空数组
					continue;

				if (pArgInf[i].m_dtDataType == SDT_TEXT)
				{
					DWORD dwSize;
					LPSTR* pAryData = (LPSTR*)GetAryElementInf(*pArgInf[i].m_ppAryData, dwSize);

					for (UINT n = 0; n < dwSize; n++)
					{
						if (pAryData[n])
							E_MFree(pAryData[n]);

						LPSTR pStr = NULL;
						if (bEof == FALSE)
							bEof = ReadMemFileTextData(pMemFile, pStr);
						pAryData[n] = pStr;
					}
				}
				else if (pArgInf[i].m_dtDataType == SDT_BIN)
				{
					DWORD dwSize;
					LPBYTE* pAryData = (LPBYTE*)GetAryElementInf(*pArgInf[i].m_ppAryData, dwSize);
					INT nData = 0;
					for (UINT n = 0; n < dwSize; n++)
					{
						if (pAryData[n])
							E_MFree(pAryData[n]);
						LPBYTE pByte = NULL;
						if (bEof == FALSE)
							bEof = ReadMemFileBinData(pMemFile, pByte);
						pAryData[n] = pByte;
					}
				}
				else {
					INT nLen = GetSysDataTypeDataSize(pArgInf[i].m_dtDataType);
					if (nLen == 0)//不支持的数据类型
						continue;
					DWORD dwSize;
					void* pData = GetAryElementInf(*pArgInf[i].m_ppAryData, dwSize);
					nLen *= dwSize;
					memset(pData, 0, nLen);

					if (bEof == FALSE)
					{
						DWORD dwByteTop = pMemFile->Read(pData, nLen);
						if (nLen > (INT)dwByteTop)//已经到尾了
							bEof = TRUE;
					}
				}
			}
			else
			{//非数组
				INT nLen;
				void* pData;
				INT nData = 0;
				if (pArgInf[i].m_dtDataType == SDT_TEXT)
				{
					if (pArgInf[i].m_ppText)
						E_MFree(*pArgInf[i].m_ppText);
					LPSTR pStr = NULL;
					if (bEof == FALSE)
						bEof = ReadMemFileTextData(pMemFile, pStr);
					*pArgInf[i].m_ppText = pStr;

				}
				else if (pArgInf[i].m_dtDataType == SDT_BIN)
				{
					if (pArgInf[i].m_ppBin)
						E_MFree(*pArgInf[i].m_ppBin);
					LPBYTE pByte = NULL;
					if (bEof == FALSE)
						bEof = ReadMemFileBinData(pMemFile, pByte);
					*pArgInf[i].m_ppBin = pByte;

				}
				else {

					nLen = GetSysDataTypeDataSize(pArgInf[i].m_dtDataType);
					if (nLen == 0)//不支持的数据类型
						continue;
					pData = pArgInf[i].m_pCompoundData;
					memset(pData, 0, nLen);
					if (bEof == FALSE)
					{
						DWORD dwByteTop = pMemFile->Read(pData, nLen);
						if (nLen > (INT)dwByteTop)//已经到尾了
							bEof = TRUE;
					}
				}
			}
		}
	}
	else if (pFile->nType == 3) //加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		DWORD dwNumOfByteRead;
		bRet = TRUE;
		for (INT i = 1; i < nArgCount; i++)
		{
			if (bRet == FALSE)
				break;
			if ((pArgInf[i].m_dtDataType & DT_IS_ARY) == DT_IS_ARY)//是数组
			{
				pArgInf[i].m_dtDataType &= ~DT_IS_ARY; //去除数组标志

				if (pArgInf[i].m_ppAryData == NULL)//空数组
					continue;

				if (pArgInf[i].m_dtDataType == SDT_TEXT)
				{
					DWORD dwSize;
					LPSTR* pAryData = (LPSTR*)GetAryElementInf(*pArgInf[i].m_ppAryData, dwSize);

					for (UINT n = 0; n < dwSize; n++)
					{
						if (pAryData[n])
							E_MFree(pAryData[n]);

						LPSTR pStr = NULL;
						if (bEof == FALSE)
							bEof = ReadFileTextData(hFile, pStr, bRet);
						pAryData[n] = pStr;
						if (bRet == FALSE)
							break;
					}
				}
				else if (pArgInf[i].m_dtDataType == SDT_BIN)
				{
					DWORD dwSize;
					LPBYTE* pAryData = (LPBYTE*)GetAryElementInf(pArgInf[i].m_pAryData, dwSize);
					INT nData = 0;
					for (UINT n = 0; n < dwSize; n++)
					{
						if (pAryData[n])
							E_MFree(pAryData[n]);
						LPBYTE pByte = NULL;
						if (bEof == FALSE)
							bEof = ReadFileBinData(hFile, pByte, bRet);
						pAryData[n] = pByte;

						if (bRet == FALSE)
							break;
					}
				}
				else {
					INT nLen = GetSysDataTypeDataSize(pArgInf[i].m_dtDataType);
					if (nLen == 0)//不支持的数据类型
						continue;
					DWORD dwSize;
					void* pData = GetAryElementInf(*pArgInf[i].m_ppAryData, dwSize);
					nLen *= dwSize;
					memset(pData, 0, nLen);

					if (bEof == FALSE)
					{
						if (ReadFile(hFile, pData, nLen, &dwNumOfByteRead, NULL))
						{
							if ((INT)dwNumOfByteRead < nLen)//到尾
								bEof = TRUE;
						}
						else
						{
							bRet = FALSE;
							break;
						}
					}
				}
			}
			else
			{//非数组
				INT nLen;
				void* pData;
				INT nData = 0;
				if (pArgInf[i].m_dtDataType == SDT_TEXT)
				{
					if (pArgInf[i].m_ppText)
						E_MFree(*pArgInf[i].m_ppText);
					LPSTR pStr = NULL;
					if (bEof == FALSE)
						bEof = ReadFileTextData(hFile, pStr, bRet);
					*pArgInf[i].m_ppText = pStr;

				}
				else if (pArgInf[i].m_dtDataType == SDT_BIN)
				{
					if (pArgInf[i].m_ppBin)
						E_MFree(*pArgInf[i].m_ppBin);
					LPBYTE pByte = NULL;
					if (bEof == FALSE)
						bEof = ReadFileBinData(hFile, pByte, bRet);
					*pArgInf[i].m_ppBin = pByte;

				}
				else {
					nLen = GetSysDataTypeDataSize(pArgInf[i].m_dtDataType);
					if (nLen == 0)//不支持的数据类型
						continue;
					pData = pArgInf[i].m_pCompoundData;
					memset(pData, 0, nLen);
					if (bEof == FALSE)
					{
						DWORD dwByteTop;
						if (ReadFile(hFile, pData, nLen, &dwByteTop, NULL))
						{
							if (nLen > (INT)dwByteTop)//已经到尾了
								bEof = TRUE;
						}
						else
						{
							bRet = FALSE;
							break;
						}
					}
				}
			}
		}
	}
	return bRet;
}
