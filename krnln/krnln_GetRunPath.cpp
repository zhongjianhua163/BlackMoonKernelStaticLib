#include "stdafx.h"
#include "Myfunctions.h"

//环境存取 - 取运行目录
/*
    调用格式： 〈文本型〉 取运行目录 （） - 系统核心支持库->环境存取
    英文名称：GetRunPath
    取当前被执行的易程序文件所处的目录。本命令为初级命令。
*/
LIBAPI(char*, krnln_GetRunPath)
{
	char strFile[MAX_PATH];
	int nLen;

	if(::GetModuleFileName(NULL,strFile,MAX_PATH))
	{
		nLen = mystrlen(strFile);
		char* pFind = strFile+nLen;
		do{
			pFind --;
			if(*pFind == '\\')
			{
				*pFind = 0;
				break;
			}

		}while(pFind > strFile);
	}

	nLen = mystrlen(strFile);
	char *pText = (char*)E_MAlloc_Nzero(nLen+1);
	strcpy(pText,strFile);
	return pText;

}
