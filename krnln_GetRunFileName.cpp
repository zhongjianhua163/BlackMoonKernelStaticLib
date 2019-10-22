#include "stdafx.h"
#include "Myfunctions.h"

//环境存取 - 取执行文件名
/*
    调用格式： 〈文本型〉 取执行文件名 （） - 系统核心支持库->环境存取
    英文名称：GetRunFileName
    取当前被执行的易程序文件的名称。本命令为初级命令。
*/
LIBAPI(char*, krnln_GetRunFileName)
{
	char strFile[MAX_PATH];
	int nLen;
	char* pSrc = strFile;

	if(::GetModuleFileName(NULL,strFile,MAX_PATH))
	{
		nLen = mystrlen(strFile);
		char* pFind = strFile+nLen;
		do{
			pFind --;
			if(*pFind == '\\')
			{
				pSrc = pFind +1;
				break;
			}

		}while(pFind > strFile);
	}

	nLen = mystrlen(pSrc);
	char *pText = (char*)E_MAlloc_Nzero(nLen+1);
	strcpy(pText,pSrc);
	return pText;
}
