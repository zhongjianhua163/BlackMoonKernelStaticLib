#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"

//文件读写 - 写出数据
/*
    调用格式： 〈逻辑型〉 写出数据 （整数型 欲写出数据的文件号，通用型数组/非数组 欲写出的数据，... ） - 系统核心支持库->文件读写
    英文名称：write
    本命令应该与“读入”命令配合使用，用作写出一系列变量或数组变量的格式数据到文件中当前读写位置处。成功返回真，失败返回假。
具体各种数据类型数据的写出格式为：
  1、数值型、逻辑型、日期时间型、子程序指针型： 为其所对应的实际数据；
  2、文本型：   为文本数据 + 字节 0 ；
  3、字节集型： 为字节集数据长度（整数） + 字节集实际数据；
  4、以上各种数据类型的数组型数据： 为非数组情况下数据格式的顺序排列。本命令为中级命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“欲写出数据的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“欲写出的数据”，类型为“通用型（all）”，提供参数数据时可以同时提供数组或非数组数据。如果被写出数据的数据类型为用户自定义或库定义数据类型，命令将会失败。
*/
LIBAPI(BOOL, krnln_write)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return NULL;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return NULL;
	PMDATA_INF pArgInf = &ArgInf;

	BOOL bRet = FALSE;

	if(pFile->nType ==1 || pFile->nType == 3)//磁盘文件 加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		DWORD dwNumOfByteRead;
		bRet = TRUE;
		INT nPos;
		for(INT i=1;i < nArgCount;i++)
		{
			if(bRet == FALSE)
				break;
			if((pArgInf[i].m_dtDataType & DT_IS_ARY) == DT_IS_ARY)//是数组
			{
				pArgInf[i].m_dtDataType &=~DT_IS_ARY; //去除数组标志
				if(pArgInf[i].m_dtDataType==SDT_TEXT)
				{
					DWORD dwSize;
					LPSTR* pAryData = (LPSTR*)GetAryElementInf(pArgInf[i].m_pAryData,dwSize);
					INT nData = 0;
					for(UINT n=0;n<dwSize;n++)
					{
						INT nLen;
						void* pData;
						if(pAryData[n]==NULL)
						{
							nLen = 1;
							pData = &nData;
						}
						else
						{
							nLen = mystrlen(pAryData[n])+1;
							pData = pAryData[n];
						}
						void *pTMP = NULL;
						if (pFile->nType == 3) //加密文件
						{
							pTMP = malloc(nLen);
							memcpy(pTMP, pData, nLen);
							nPos = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
							E_RC4_Calc(nPos, (unsigned char*)pTMP, nLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
							pData = pTMP;
						}
						if(WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL))
						{
//							if(FlushFileBuffers(hFile)==FALSE)
//								bRet = FALSE;
						}
						else
							bRet = FALSE;
						
						if (pTMP)
						{
							free(pTMP);
							pTMP = NULL;
						}

						if(bRet == FALSE)
							break;
					}


				}else if(pArgInf[i].m_dtDataType==SDT_BIN)
				{
					DWORD dwSize;
					LPINT* pAryData = (LPINT*)GetAryElementInf(pArgInf[i].m_pAryData,dwSize);
					INT nData = 0;
					for(UINT n=0;n<dwSize;n++)
					{
						void* pData;
						INT nLen;
						if(pAryData[n]==NULL)
						{
							pData = &nData;
							nLen = sizeof(INT);
						}
						else
						{
							LPINT p = pAryData[n];
							nLen = p[1]+sizeof(INT);
							p++;
							pData = p;
						}
						void *pTMP = NULL;
						if (pFile->nType == 3) //加密文件
						{
							pTMP = malloc(nLen);
							memcpy(pTMP, pData, nLen);
							nPos = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
							E_RC4_Calc(nPos, (unsigned char*)pTMP, nLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
							pData = pTMP;
						}
						if(WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL))
						{
//							if(FlushFileBuffers(hFile)==FALSE)
//								bRet = FALSE;
						}
						else
							bRet = FALSE;

						if (pTMP)
						{
							free(pTMP);
							pTMP = NULL;
						}

						if(bRet == FALSE)
							break;
					}

				}else{

					INT nLen = GetSysDataTypeDataSize(pArgInf[i].m_dtDataType);
					if(nLen==0)//不支持的数据类型
						continue;
					DWORD dwSize;
					void* pData = GetAryElementInf(pArgInf[i].m_pAryData,dwSize);
					nLen *= dwSize;

					void *pTMP = NULL;
					if (pFile->nType == 3) //加密文件
					{
						pTMP = malloc(nLen);
						memcpy(pTMP, pData, nLen);
						nPos = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
						E_RC4_Calc(nPos, (unsigned char*)pTMP, nLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
						pData = pTMP;
					}
					if(WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL))
					{
//						if(FlushFileBuffers(hFile)==FALSE)
//							bRet = FALSE;
					}
					else
						bRet = FALSE;

					if (pTMP)
					{
						free(pTMP);
						pTMP = NULL;
					}

					if(bRet == FALSE)
						break;
				}
			}
			else
			{//非数组
				INT nLen;
				void* pData;
				INT nData = 0;
				if(pArgInf[i].m_dtDataType==SDT_TEXT)
				{
					if(pArgInf[i].m_pText==NULL)
					{
						nLen = 1;
						pData = &nData;

					}
					else
					{
						nLen = mystrlen(pArgInf[i].m_pText)+1;
						pData = pArgInf[i].m_pText;
					}

				}else if(pArgInf[i].m_dtDataType==SDT_BIN)
				{
					if(pArgInf[i].m_pBin==NULL)
					{
						nLen = sizeof(INT);
						pData = &nData;
					}
					else
					{
						LPINT p = (LPINT)pArgInf[i].m_pBin;
						nLen = p[1]+sizeof(INT);
						p++;
						pData = p;
					}

				}else{

					nLen = GetSysDataTypeDataSize(pArgInf[i].m_dtDataType);
					if(nLen==0)//不支持的数据类型
						continue;
					pData = &pArgInf[i].m_int;
				}
				void *pTMP = NULL;
				if (pFile->nType == 3) //加密文件
				{
					pTMP = malloc(nLen);
					memcpy(pTMP, pData, nLen);
					nPos = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
					E_RC4_Calc(nPos, (unsigned char*)pTMP, nLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
					pData = pTMP;
				}
				if(WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL))
				{
//					if(FlushFileBuffers(hFile)==FALSE)
//						bRet = FALSE;
				}
				else
					bRet = FALSE;

				if (pTMP)
				{
					free(pTMP);
					pTMP = NULL;
				}

				if(bRet == FALSE)
					break;
			}
		}
		

	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;
		bRet = TRUE;
		for(INT i=1;i < nArgCount;i++)
		{

			if((pArgInf[i].m_dtDataType & DT_IS_ARY) == DT_IS_ARY)//是数组
			{
				pArgInf[i].m_dtDataType &=~DT_IS_ARY; //去除数组标志
				if(pArgInf[i].m_dtDataType==SDT_TEXT)
				{
					DWORD dwSize;
					LPSTR* pAryData = (LPSTR*)GetAryElementInf(pArgInf[i].m_pAryData,dwSize);
					INT nData = 0;
					for(UINT n=0;n<dwSize;n++)
					{
						INT nLen;
						void* pData;
						if(pAryData[n]==NULL)
						{
							nLen = 1;
							pData = &nData;
						}
						else
						{
							nLen = mystrlen(pAryData[n])+1;
							pData = pAryData[n];
						}
						pMemFile->Write(pData,nLen);

					}


				}else if(pArgInf[i].m_dtDataType==SDT_BIN)
				{
					DWORD dwSize;
					LPINT* pAryData = (LPINT*)GetAryElementInf(pArgInf[i].m_pAryData,dwSize);
					INT nData = 0;
					for(UINT n=0;n<dwSize;n++)
					{
						void* pData;
						INT nLen;
						if(pAryData[n]==NULL)
						{
							pData = &nData;
							nLen = sizeof(INT);
						}
						else
						{
							LPINT p = pAryData[n];
							nLen = p[1]+sizeof(INT);
							p++;
							pData = p;
						}
						pMemFile->Write(pData,nLen);

					}

				}else{

					INT nLen = GetSysDataTypeDataSize(pArgInf[i].m_dtDataType);
					if(nLen==0)//不支持的数据类型
						continue;
					DWORD dwSize;
					void* pData = GetAryElementInf(pArgInf[i].m_pAryData,dwSize);
					nLen *= dwSize;
					pMemFile->Write(pData,nLen);

				}
			}
			else
			{//非数组
				INT nLen;
				void* pData;
				INT nData = 0;
				if(pArgInf[i].m_dtDataType==SDT_TEXT)
				{
					if(pArgInf[i].m_pText==NULL)
					{
						nLen = 1;
						pData = &nData;

					}
					else
					{
						nLen = mystrlen(pArgInf[i].m_pText)+1;
						pData = pArgInf[i].m_pText;
					}

				}else if(pArgInf[i].m_dtDataType==SDT_BIN)
				{
					if(pArgInf[i].m_pBin==NULL)
					{
						nLen = sizeof(INT);
						pData = &nData;
					}
					else
					{
						LPINT p = (LPINT)pArgInf[i].m_pBin;
						nLen = p[1]+sizeof(INT);
						p++;
						pData = p;
					}

				}else{

					nLen = GetSysDataTypeDataSize(pArgInf[i].m_dtDataType);
					if(nLen==0)//不支持的数据类型
						continue;
					pData = &pArgInf[i].m_int;
				}

				pMemFile->Write(pData,nLen);

			}
		}


	}
	return bRet;
}
