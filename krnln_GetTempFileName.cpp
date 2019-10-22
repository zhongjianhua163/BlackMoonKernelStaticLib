#include "stdafx.h"
#include <SHLWAPI.h>
#include "Myfunctions.h"
#pragma comment(lib,"SHLWAPI.lib") 
//磁盘操作 - 取临时文件名
/*
    调用格式： 〈文本型〉 取临时文件名 （［文本型 目录名］） - 系统核心支持库->磁盘操作
    英文名称：GetTempFileName
    返回一个在指定目录中确定不存在的 .TMP 全路径文件名称。本命令为初级命令。
    参数<1>的名称为“目录名”，类型为“文本型（text）”，可以被省略。如果省略本参数，默认将使用系统的标准临时目录。
*/
LIBAPI(char*, krnln_GetTempFileName)
{
	char DirName [MAX_PATH];
	if(ArgInf.m_dtDataType == _SDT_NULL)
	{
		if(GetTempPath(MAX_PATH,DirName)==FALSE)
			DirName[0]=0;
	}
	else
		strcpy(DirName,ArgInf.m_pText);

	char* pText = NULL;
	char TempFileName [MAX_PATH];
	INT nLen = mystrlen(DirName);
	if(DirName[nLen-1]!='\\')
		DirName[nLen]='\\';
	do{
		wsprintf(TempFileName, "%s%x.tmp", DirName,GetTickCount());
	}while(PathFileExists(TempFileName));


//	if(GetTempFileName(DirName,"14f",0,TempFileName))
//	{
		nLen = mystrlen(TempFileName);
		pText = (char*)E_MAlloc_Nzero(nLen+1);
		strcpy(pText,TempFileName);
//	}
	return pText;
}
