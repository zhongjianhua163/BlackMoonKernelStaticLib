#include "stdafx.h"
#include "MyMemFile.h"
#include "Myfunctions.h"
//文件读写 - 是否在文件尾
/*
    调用格式： 〈逻辑型〉 是否在文件尾 （整数型 文件号，［逻辑型 是否为判断文本已读完］） - 系统核心支持库->文件读写
    英文名称：feof
    如果指定被打开文件的读写位置已经处于该文件数据的尾部，则返回真，否则返回假。本命令为初级命令。
    参数<1>的名称为“文件号”，类型为“整数型（int）”。参数值指明欲操作的文件号，该文件号必须由“打开文件”命令所返回。
    参数<2>的名称为“是否为判断文本已读完”，类型为“逻辑型（bool）”，可以被省略。如果本参数值为真而且下一即将读入的字节为字节值 0 或 26 等文本终止标记符或者当前读写位置已处于该文件数据的尾部，命令将返回真。如果本参数被省略或为假，将不进行此检查。

*/
LIBAPI(BOOL, krnln_feof)
{
	PFILEELEMENT pFile = (PFILEELEMENT)ArgInf.m_pCompoundData;
	if(pFile==NULL)
		return TRUE;
	if(IsInFileMangerList(pFile)==FALSE)//检测句柄合法性
		return TRUE;
	PMDATA_INF pArgInf = &ArgInf;
	INT nRet = TRUE;

	if(pFile->nType ==1 || pFile->nType == 3)//磁盘文件 加密文件
	{
		HANDLE hFile = (HANDLE)pFile->FileHandle;
		DWORD dwHi;
		UINT nLen = ::GetFileSize(hFile,&dwHi);
		UINT nLoc = SetFilePointer(hFile,0,NULL,FILE_CURRENT);
		if(nLoc != HFILE_ERROR)
		{
			if(nLoc < nLen)
			{
				nRet = FALSE;
				
				if(pArgInf[1].m_dtDataType != _SDT_NULL && pArgInf[1].m_bool)
				{
					INT nData;
					LPSTR pStr = (LPSTR)&nData;
					DWORD dwByteTop;
					BOOL bRet = ReadFile(hFile, pStr, sizeof(BYTE), &dwByteTop, 0);
					SetFilePointer(hFile,nLoc,NULL,FILE_BEGIN);
					if (pFile->nType==3) //加密文件
						E_RC4_Calc(nLoc, (unsigned char*)pStr, sizeof(BYTE), pFile->strTable, pFile->nCryptStart, pFile->strMD5);

					if(bRet && (*pStr==0 || *pStr == 26))
						nRet = TRUE;
				}
			}
		}
	}else if(pFile->nType ==2)//内存文件
	{
		CMyMemFile* pMemFile = (CMyMemFile*) pFile->FileHandle;
		UINT nLen = pMemFile->GetFileSize();
		UINT nLoc = pMemFile->GetPosition();
		if(nLoc < nLen)
		{
			nRet = FALSE;
			
			if(pArgInf[1].m_dtDataType != _SDT_NULL && pArgInf[1].m_bool)
			{
				INT nData;
				LPSTR pStr = (LPSTR)&nData;
				BOOL bRet = pMemFile->Read (pStr, sizeof(BYTE));
				pMemFile->Seek(nLoc,CMyMemFile::SeekPosition::begin);
				if(bRet && (*pStr==0 || *pStr == 26))
					nRet = TRUE;
			}
		}
	}
	return nRet;
}
