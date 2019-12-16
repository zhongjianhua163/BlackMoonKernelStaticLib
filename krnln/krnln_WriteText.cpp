#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"

//文件读写 - 写出文本
/*
    调用格式： 〈逻辑型〉 写出文本 （整数型 欲写出文本的文件号，通用型 欲写出的文本，... ） - 系统核心支持库->文件读写
    英文名称：WriteText
    本命令用作写出一段或数段文本数据到文件中当前读写位置处。成功返回真，失败返回假。本命令为初级命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“欲写出文本的文件号”，类型为“整数型（int）”。该文件号由“打开文件”命令所返回。
    参数<2>的名称为“欲写出的文本”，类型为“通用型（all）”。参数值如果不为文本类型数据，将自动进行转换，如果无法转换（即数据类型为字节集、子程序指针、库或用户自定义数据类型），则不写出此数据。
*/

LIBAPI(BOOL, krnln_WriteText)
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
			{
				if(WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL))
				{
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
	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;
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

			if(bNeedFree)
				free(pData);
			
		}

	}else if(pFile->nType == 3)//加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		DWORD dwNumOfByteRead;
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
			{
				INT nPos = SetFilePointer(hFile, 0, NULL, FILE_CURRENT);
				E_RC4_Calc(nPos, (unsigned char*)pData, nLen, pFile->strTable, pFile->nCryptStart, pFile->strMD5);
				if(!WriteFile(hFile,pData,nLen,&dwNumOfByteRead,NULL))
					bRet = FALSE;
			}
			
			if(bNeedFree)
				free(pData);
			
			if(bRet == FALSE)
				break;
		}
	}
	return bRet;
}
